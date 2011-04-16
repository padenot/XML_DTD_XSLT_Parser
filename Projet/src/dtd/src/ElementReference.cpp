/*************************************************************************
 * ElementReference  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Réalisation de la classe <ElementReference> (fichier ElementReference.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#ifdef DTD_VALIDATION_TRACE
#include <iostream>
#endif

//------------------------------------------------------ Include personnel
#include "ElementReference.hh"
#include "InterfaceDTDVisitor.hpp"
using namespace xml;

namespace dtd
{
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type ElementReference::Méthode ( liste des paramètres )
// Algorithme :
//	
//{
//}

void ElementReference::accept(InterfaceDTDVisitor & visitor) const
{
	visitor.visit(*this);
}

bool ElementReference::matches(xml::Node& node)
{
	node.accept(*this);

	return _matchResult;
}

std::string ElementReference::ns() const
{
	return _namespace;
}

std::string ElementReference::name() const
{
	return _name;
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
ElementReference::ElementReference(DTD& dtd, std::string ns, std::string name) :
	_dtd(dtd), _namespace(ns), _name(name)
{
	// Rien à faire.
}

ElementReference::~ElementReference()
{
	// Rien à faire.
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
bool ElementReference::_startValidation(
		CompositeMarkupNode::ChildrenIterator firstToken,
		CompositeMarkupNode::ChildrenIterator endToken,
		BrowsableContent* nextStep)
{
	if (firstToken == endToken)
	{
#ifdef DTD_VALIDATION_TRACE
		cerr << "No token available to match (" << _namespace << "," << _name
		<< ")!" << endl;
#endif
		// Il n'y a pas de jeton à consommer :
		//	le matching avec cet objet est impossible.
		return false;
	}
	else
	{
#ifdef DTD_VALIDATION_TRACE
		cerr << "Trying to match (" << _namespace << "," << _name << ")... ";
#endif
		if (matches(**firstToken))
		{
#ifdef DTD_VALIDATION_TRACE
			cerr << "matched." << endl;
#endif
			// Le jeton est consommé.
			++firstToken;

			return _browseUp(nextStep, firstToken, endToken);
		}
		else
		{
#ifdef DTD_VALIDATION_TRACE
			cerr << "didn't match." << endl;
#endif
			// Le jeton courant est incorrect.
			return false;
		}
	}
}

void ElementReference::visit(const TextNode&)
{
	_matchResult = false;
}

void ElementReference::visit(const MarkupNode& node)
{
	_matchResult = (node.ns() == _namespace && node.name() == _name);
}

void ElementReference::visit(const CompositeMarkupNode& node)
{
	_matchResult = (node.ns() == _namespace && node.name() == _name);
}

} // namespace dtd
