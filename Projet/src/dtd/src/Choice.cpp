/*************************************************************************
 * Choice  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Réalisation de la classe <Choice> (fichier Choice.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "Choice.hh"
#include "InterfaceDTDVisitor.hpp"
using namespace xml;

namespace dtd
{
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Choice::Méthode ( liste des paramètres )
// Algorithme :
//	
//{
//}

bool Choice::validate(const CompositeMarkupNode& node)
// Algorithme :
//	Initialise la validation récursive (récursion sur les éléments de choix).
{
	return _newValidation(node.begin(), node.end(), 0);
}

void Choice::accept(InterfaceDTDVisitor & visitor) const
{
	visitor.visit(*this);
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Choice::Choice(const ChoosableSet & choosable) :
	_choosable(choosable)
{
	//TODO
}

Choice::~Choice()
{
	for (_ChoosableSet::iterator it = _choosable.begin(); it
			!= _choosable.end(); ++it)
	{
		delete *it;
	}
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void Choice::_beforeValidation(
		xml::CompositeMarkupNode::ChildrenIterator firstToken,
		xml::CompositeMarkupNode::ChildrenIterator endToken,
		_InterfaceValidator* nextStep)
{
	_stack.push(_State(firstToken, endToken, nextStep, _choosable.begin()));
}

void Choice::_afterValidation()
{
	_stack.pop();
}

bool Choice::_startValidation(CompositeMarkupNode::ChildrenIterator firstToken,
		CompositeMarkupNode::ChildrenIterator endToken,
		_InterfaceValidator* nextStep)
{
	// Premier appel de validation, aucune alternative de choix n'a
	//	été validée pour le moment.

	_State & state = _stack.top();
	bool valid = false;
	/*
	 while (state.nextChoosable != _choosable.end() && !valid)
	 {
	 state.nextChoosable
	 }

	 if (state.nextStep == 0)
	 {
	 // La séquence était à l'origine de la validation : tout est ok
	 //	si on a réussi à atteindre la fin de la liste de noeuds
	 return currentToken == state.endToken;
	 }
	 else
	 {
	 // La séquence était subordonnée à un contenu englobant :
	 //	d'autres jetons doivent peut-être être consommés.
	 return state.nextStep->_continueValidation(currentToken);
	 }*/
}

bool Choice::_continueValidation(
		xml::CompositeMarkupNode::ChildrenIterator currentToken)
{
	_State & state = _stack.top();
	/*
	 // Fin de séquence non atteinte : on teste le contenu incrusté suivant.
	 _ValidatorAccessor thisValidator(*this);
	 _InterfaceValidator& currentEmbeddedContent =
	 **state.nextEmbeddedContent;
	 ++state.nextEmbeddedContent;

	 if (currentEmbeddedContent._newValidation(currentToken, state.endToken,
	 &thisValidator))
	 {
	 // Le reste de la liste de jetons a pu être consommé par le reste de
	 //	l'arbre de contenus : la validation est terminée et réussie.
	 return true;
	 }
	 else
	 {
	 // La configuration actuelle n'est pas valide.
	 //	Il faut annuler la dernière décision prise (backtracking).
	 return false;
	 }
	 */
}

} // namespace dtd
