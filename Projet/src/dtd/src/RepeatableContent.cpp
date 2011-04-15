/*************************************************************************
 * RepeatableContent  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Réalisation de la classe <RepeatableContent> (fichier RepeatableContent.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "RepeatableContent.hh"
#include "InterfaceDTDVisitor.hpp"
using namespace xml;

namespace dtd
{
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type RepeatableContent::Méthode ( liste des paramètres )
// Algorithme :
//	
//{
//}

void RepeatableContent::accept(InterfaceDTDVisitor & visitor) const
{
	visitor.visit(*this);
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
RepeatableContent::RepeatableContent(QuantifiableContent & content) :
	QuantifiedContent(content)
{
	// Rien à faire.
}

RepeatableContent::~RepeatableContent()
{
	// Rien à faire.
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
bool RepeatableContent::_startValidation(
		CompositeMarkupNode::ChildrenIterator firstToken,
		CompositeMarkupNode::ChildrenIterator,
		BrowsableContent*)
{

	// Il n'y a aucune différence entre l'algorithme de la première
	//	étape de validation et les suivantes.
	return _continueValidation(firstToken);
}

bool RepeatableContent::_continueValidation(
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
