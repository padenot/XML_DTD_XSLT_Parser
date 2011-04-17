/*************************************************************************
 * DTD  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Réalisation de la classe <DTD> (fichier DTD.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#ifdef DTD_VALIDATION_TRACE
#include <iostream>
#endif

//------------------------------------------------------ Include personnel
#include "DTD.hh"
#include "Content.hh"
#include "Attribute.hh"
#include "MarkupNode.hh"
#include "TextNode.hh"
#include "CompositeMarkupNode.hh"
#include "InterfaceDTDVisitor.hpp"
using namespace xml;

namespace dtd
{
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type DTD::Méthode ( liste des paramètres )
// Algorithme :
//	
//{
//}

void DTD::accept(InterfaceDTDVisitor & visitor)
{
	for (_Elements::const_iterator it = _elements.begin(); it
			!= _elements.end(); ++it)
	{
		visitor.visitElement(it->first.first, it->first.second, *it->second);
	}

	for (_AttributesLists::const_iterator it = _attributesLists.begin(); it
			!= _attributesLists.end(); ++it)
	{
		visitor.visitAttributesList(it->first.first, it->first.second,
				it->second);
	}
}

void DTD::addElement(const std::string & ns, const std::string & elementName,
		Content& content)
{
	_ElementId insertedId(ns, elementName);
	pair<_Elements::iterator, bool> insertResult = _elements.insert(
			_Elements::value_type(insertedId, &content));

	if (!insertResult.second)
	{
		// Erreur, cet élément a déjà été déclaré
		// TODO Gérer l'erreur
	}
}

void DTD::addAttributesList(const std::string & ns,
		const std::string & elementName, const AttributesList& newAttributes)
{
	_ElementId insertedId(ns, elementName);
	_AttributesLists::iterator attList = _attributesLists.find(insertedId);

	if (attList == _attributesLists.end())
	{
		// L'attribute list n'existe pas encore, il faut la créer
		pair<_AttributesLists::iterator, bool> insertResult =
				_attributesLists.insert(
						_AttributesLists::value_type(insertedId,
								AttributesList()));
		attList = insertResult.first;
	}

	// On ajoute les attributs à la liste
	attList->second.insert(newAttributes.begin(), newAttributes.end());
	// TODO : gérer l'erreur "cet attribut a déjà été déclaré"
}

Content * DTD::getElement(std::string ns, std::string name) const
{
	_Elements::const_iterator it = _elements.find(_ElementId(ns, name));

	if (it == _elements.end())
	{
		// Élément non trouvé
		return 0;
	}
	else
	{
		return it->second;
	}
}

const AttributesList * DTD::getAttributesList(std::string ns, std::string name) const
{
	_AttributesLists::const_iterator it = _attributesLists.find(
			_ElementId(ns, name));

	if (it == _attributesLists.end())
	{
		// Élément non trouvé
		return 0;
	}
	else
	{
		return &(it->second);
	}
}

bool DTD::isValid(const xml::Node& root, const std::string & validRootName)
{
	_validRootName = validRootName;
	_validatingRoot = true;
	return _isValid(root);
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
DTD::DTD() :
	_elements(), _attributesLists(), _validatingRoot(true), _validRootName(),
			_lastNodeIsValid(false)
{
	// Rien à faire.
}

DTD::~DTD()
{
	for (_Elements::iterator it = _elements.begin(); it != _elements.end(); ++it)
	{
		delete it->second;
	}
	for (_AttributesLists::iterator it = _attributesLists.begin(); it
			!= _attributesLists.end(); ++it)
	{
		for (AttributesList::iterator it2 = it->second.begin(); it2
				!= it->second.end(); ++it2)
		{
			delete *it2;
		}
	}
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
bool DTD::_isValid(const xml::Node& node)
{
	node.accept(*this);

	return _lastNodeIsValid;
}

void DTD::visit(const TextNode&)
// Un noeud texte est toujours valide, sauf à la racine
{
	_lastNodeIsValid = !_validatingRoot;
}

void DTD::visit(const MarkupNode& node)
// Un noeud balise est valide si sa structure correspond
//	à celle attendue.
{
	Content* content = getElement(node.ns(), node.name());

#ifdef DTD_VALIDATION_TRACE
	cerr << endl
	<< "Validating (" << node.ns() <<"," << node.name() << ")" << endl;
#endif
	if (content == 0)
	{
#ifdef DTD_VALIDATION_TRACE
		cerr << "(" << node.ns() <<"," << node.name() << ") was not found." << endl;
#endif
		_lastNodeIsValid = false;
	}
	else
	{
		if (_validatingRoot && node.name() != _validRootName)
		{
			_lastNodeIsValid = false;
		}
		else
		{
			_lastNodeIsValid = content->validate(node) && checkAttributes(node);
		}
#ifdef DTD_VALIDATION_TRACE
		cerr << "(" << node.ns() <<"," << node.name() << ") validation result: "
		<< boolalpha << _lastNodeIsValid << endl;
#endif
	}
}

void DTD::visit(const CompositeMarkupNode& node)
// Un noeud composite est valide si sa structure correspond
//	à celle attendue et si ses enfants sont valides.
{
	Content* content = getElement(node.ns(), node.name());

#ifdef DTD_VALIDATION_TRACE
	cerr << endl
	<< "Validating (" << node.ns() <<"," << node.name() << ")" << endl;
#endif

	if (content == 0)
	{
#ifdef DTD_VALIDATION_TRACE
		cerr << "(" << node.ns() <<"," << node.name() << ") was not found." << endl;
#endif
		_lastNodeIsValid = false;
	}
	else
	{
		if (_validatingRoot && node.name() != _validRootName)
		{
			_lastNodeIsValid = false;
		}
		else
		{
			_lastNodeIsValid = content->validate(node) && checkAttributes(node);

			_validatingRoot = false;
			for (CompositeMarkupNode::ChildrenIterator it = node.begin(); _lastNodeIsValid
					&& it != node.end(); ++it)
			{
				_lastNodeIsValid = _isValid(**it);
			}
		}
#ifdef DTD_VALIDATION_TRACE
		cerr << "(" << node.ns() <<"," << node.name() << ") validation result: "
		<< boolalpha << _lastNodeIsValid << endl;
#endif
	}
}

bool DTD::checkAttributes(const xml::MarkupNode & node)
{
	const AttributesList* attlist = getAttributesList(node.ns(), node.name());
	MarkupNode::AttributesIterator nodeAttribute = node.begin();

	if (attlist == 0)
	{
		// Aucun attribut n'est défini pour cet élément. L'élément est correct
		//	s'il n'a pas d'attribut.
		return nodeAttribute == node.end();
	}
	else
	{
		bool attributesAreOk = true;
		for (; attributesAreOk && nodeAttribute != node.end(); ++nodeAttribute)
		{
			Attribute contentAttribute(nodeAttribute->first);

			// L'attribut est correct si on le trouve dans la liste
			attributesAreOk = (attlist->find(&contentAttribute)
					!= attlist->end());
		}

		return attributesAreOk;
	}
}

} // namespace dtd
