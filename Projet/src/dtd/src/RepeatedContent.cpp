/*************************************************************************
 * RepeatedContent  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Réalisation de la classe <RepeatedContent> (fichier RepeatedContent.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "RepeatedContent.hh"
#include "InterfaceDTDVisitor.hpp"
using namespace xml;

namespace dtd
{
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type RepeatedContent::Méthode ( liste des paramètres )
// Algorithme :
//	
//{
//}

void RepeatedContent::accept(InterfaceDTDVisitor & visitor) const
{
	visitor.visit(*this);
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
RepeatedContent::RepeatedContent(QuantifiableContent & content) :
	QuantifiedContent(content)
{
	// Rien à faire.
}

RepeatedContent::~RepeatedContent()
{
	// Rien à faire.
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
bool RepeatedContent::_startValidation(
		CompositeMarkupNode::ChildrenIterator firstToken,
		CompositeMarkupNode::ChildrenIterator endToken,
		BrowsableContent* nextStep)
{
	// Il faut et suffit que le contenu enfant soit validé au moins une fois.
	return _browseDown(_content, firstToken, endToken, this);
}

bool RepeatedContent::_continueValidation(
		xml::CompositeMarkupNode::ChildrenIterator currentToken)
{
	_State& state = _stack.top();

	if (_browseDown(_content, currentToken, state.endToken, this))
	{
		// On a tenté (avec succès) de faire correspondre encore une
		//	ou plusieurs fois le contenu enfant avec les jetons.
		return true;
	}
	else if (_browseUp(state.nextStep, currentToken, state.endToken))
	{
		// On n'a pas pu faire correspondre encore une ou plusieurs fois
		//	le contenu enfant avec les jetons.
		//	Le contenu enfant a été validé au moins une fois (puisque cette
		//	méthode a été appelée), ce qui est suffisant.
		//	On a donc tenté (avec succès) de faire valider le reste des
		//	jetons par le contenu parent.
		return true;
	}
	else
	{
		// Il a été impossible de valider le reste des jetons par le contenu
		//	parent. L'état actuel des choses ne permet pas de valider la
		//	liste de jetons. (Il faut backtracker)
		return false;
	}
}

} // namespace dtd
