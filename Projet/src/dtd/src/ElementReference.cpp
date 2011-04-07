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
bool ElementReference::_continueValidation(
		xml::CompositeMarkupNode::ChildrenIterator currentToken)
{
	(*currentToken)->accept(*this);

	if (_validationResult)
	{
		//TODO: gérer la mémoire (nextStep, etc.)
		return false;
	}
	else
	{
		return false;
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
