/*************************************************************************
 * BrowseableContent  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Réalisation de la classe <BrowseableContent> (fichier BrowseableContent.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "BrowseableContent.hh"
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

bool BrowseableContent::validate(const MarkupNode &)
{
	return false;
}

bool BrowseableContent::validate(const CompositeMarkupNode & node)
// Algorithme :
//	Initialise la récursion sur l'arbre de contenu.
{
	return _newValidation(node.begin(), node.end(), 0);
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
BrowseableContent::BrowseableContent()
{
	//TODO
}

BrowseableContent::~BrowseableContent()
{
	//TODO
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
bool BrowseableContent::_newValidation(
		CompositeMarkupNode::ChildrenIterator firstToken,
		CompositeMarkupNode::ChildrenIterator endToken,
		BrowseableContent* nextStep)
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

bool BrowseableContent::_continueValidation(
		xml::CompositeMarkupNode::ChildrenIterator currentToken)
{
	return false;
}

void BrowseableContent::_beforeValidation(
		CompositeMarkupNode::ChildrenIterator,
		CompositeMarkupNode::ChildrenIterator, BrowseableContent*)
{
	// Do nothing by default.
}

void BrowseableContent::_afterValidation()
{
	// Do nothing by default.
}

bool BrowseableContent::_browseUp(BrowseableContent & parentContent,
		CompositeMarkupNode::ChildrenIterator currentToken)
{
	return parentContent._continueValidation(currentToken);
}

bool BrowseableContent::_browseDown(BrowseableContent & childContent,
		CompositeMarkupNode::ChildrenIterator firstToken,
		CompositeMarkupNode::ChildrenIterator endToken,
		BrowseableContent *nextStep)
{
	return childContent._newValidation(firstToken, endToken, nextStep);
}

} // namespace dtd
