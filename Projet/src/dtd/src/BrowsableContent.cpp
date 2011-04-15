/*************************************************************************
 * BrowsableContent  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Réalisation de la classe <BrowsableContent> (fichier BrowsableContent.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "BrowsableContent.hh"
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

bool BrowsableContent::validate(const MarkupNode &)
{
	return false;
}

bool BrowsableContent::validate(const CompositeMarkupNode & node)
// Algorithme :
//	Initialise la récursion sur l'arbre de contenu.
{
	return _newValidation(node.begin(), node.end(), 0);
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
BrowsableContent::BrowsableContent()
{
	// Rien à faire.
}

BrowsableContent::~BrowsableContent()
{
	// Rien à faire.
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
bool BrowsableContent::_newValidation(
		CompositeMarkupNode::ChildrenIterator firstToken,
		CompositeMarkupNode::ChildrenIterator endToken,
		BrowsableContent* nextStep)
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

bool BrowsableContent::_continueValidation(
		xml::CompositeMarkupNode::ChildrenIterator)
{
	// Par défaut, la méthode doit rester inutilisée (pour des
	//	contenus n'ayant pas d'enfant par exemple)
	return false;
}

void BrowsableContent::_beforeValidation(CompositeMarkupNode::ChildrenIterator,
		CompositeMarkupNode::ChildrenIterator, BrowsableContent*)
{
	// Do nothing by default.
}

void BrowsableContent::_afterValidation()
{
	// Do nothing by default.
}

bool BrowsableContent::_browseUp(BrowsableContent * parentContent,
		CompositeMarkupNode::ChildrenIterator currentToken,
		CompositeMarkupNode::ChildrenIterator endToken)
{
	if (parentContent == 0)
	{
		// L'objet n'est pas contenu dans un autre "content".
		// 	On doit avoir consommé tous les jetons pour qu'ils
		//	soient déclarés valides.
		return currentToken == endToken;
	}
	else
	{
		// L'objet est pas contenu dans un autre "content".
		// 	On doit continuer la validation au niveau supérieur.
		return parentContent->_continueValidation(currentToken);
	}
}

bool BrowsableContent::_browseDown(BrowsableContent & childContent,
		CompositeMarkupNode::ChildrenIterator firstToken,
		CompositeMarkupNode::ChildrenIterator endToken,
		BrowsableContent *nextStep)
{
	return childContent._newValidation(firstToken, endToken, nextStep);
}

} // namespace dtd
