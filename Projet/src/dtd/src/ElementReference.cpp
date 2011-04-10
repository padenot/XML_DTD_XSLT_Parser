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

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
ElementReference::ElementReference(DTD& dtd, std::string ns, std::string name) :
	_dtd(dtd), _namespace(ns), _name(name)
{
	//TODO
}

ElementReference::~ElementReference()
{
	//TODO
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
		// Il n'y a pas de jeton à consommer :
		//	le matching avec cet objet est impossible.
		return false;
	}
	else
	{
		(*firstToken)->accept(*this);

		if (_validationResult)
		{
			// Le jeton est consommé.
			++firstToken;

			return _browseUp(nextStep, firstToken, endToken);
		}
		else
		{
			// Le jeton courant est incorrect.
			return false;
		}
	}
}

void ElementReference::visit(const TextNode&)
{
	_validationResult = false;
}

void ElementReference::visit(const MarkupNode& node)
{
	_validationResult = (node.ns() == _namespace && node.name() == _name);
}

void ElementReference::visit(const CompositeMarkupNode& node)
{
	_validationResult = (node.ns() == _namespace && node.name() == _name);
}

} // namespace dtd
