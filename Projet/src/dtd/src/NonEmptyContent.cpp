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
		NonEmptyContent* nextStep)
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
		NonEmptyContent* nextStep)
// Algorithme :
//	TODO
{
	bool result;

	_pushState(firstToken, endToken, nextStep);
	result = _continueValidation(firstToken);
	_popState();

	return result;
}

void NonEmptyContent::_pushState(CompositeMarkupNode::ChildrenIterator,
		CompositeMarkupNode::ChildrenIterator, NonEmptyContent*)
{
	// Do nothing by default.
}

void NonEmptyContent::_popState()
{
	// Do nothing by default.
}

} // namespace dtd
