/*************************************************************************
 * NonEmptyContent  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Réalisation de la classe <NonEmptyContent> (fichier NonEmptyContent.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "NonEmptyContent.hh"
using namespace xml;

namespace dtd
{
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type NonEmptyContent::Méthode ( liste des paramètres )
// Algorithme :
//	
//{
//}

bool NonEmptyContent::validate(const MarkupNode &)
{
	return false;
}

bool NonEmptyContent::validate(const CompositeMarkupNode & node)
// Algorithme :
//	Initialise la récursion sur l'arbre de contenu.
{
	return _newValidation(node.begin(), node.end(), 0);
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
NonEmptyContent::NonEmptyContent()
{
	//TODO
}

NonEmptyContent::~NonEmptyContent()
{
	//TODO
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
NonEmptyContent::_ValidatorAccessor::_ValidatorAccessor(
		NonEmptyContent& referenced) :
	_referenced(referenced)
{

}

bool NonEmptyContent::_ValidatorAccessor::_newValidation(
		xml::CompositeMarkupNode::ChildrenIterator firstToken,
		xml::CompositeMarkupNode::ChildrenIterator endToken,
		_InterfaceValidator* nextStep)
{
	return _referenced._newValidation(firstToken, endToken, nextStep);
}

bool NonEmptyContent::_ValidatorAccessor::_continueValidation(
		xml::CompositeMarkupNode::ChildrenIterator currentToken)
{
	return _referenced._continueValidation(currentToken);
}

bool NonEmptyContent::_newValidation(
		CompositeMarkupNode::ChildrenIterator firstToken,
		CompositeMarkupNode::ChildrenIterator endToken,
		_InterfaceValidator* nextStep)
// Algorithme :
//	Mémorise l'état induit par cet appel avant de commencer
//	la validation, qui est effectuée par une récursion indirecte
//	sur "_continueValidation".
{
	bool result;

	_beforeValidation(firstToken, endToken, nextStep);
	result = _continueValidation(firstToken);
	_afterValidation();

	return result;
}

bool NonEmptyContent::_continueValidation(
		xml::CompositeMarkupNode::ChildrenIterator currentToken)
{
	return false;
}

void NonEmptyContent::_beforeValidation(CompositeMarkupNode::ChildrenIterator,
		CompositeMarkupNode::ChildrenIterator, _InterfaceValidator*)
{
	// Do nothing by default.
}

void NonEmptyContent::_afterValidation()
{
	// Do nothing by default.
}

} // namespace dtd
