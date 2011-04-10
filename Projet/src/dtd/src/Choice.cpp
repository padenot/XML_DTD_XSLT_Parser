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
		BrowseableContent* nextStep)
{
	_stack.push(_State(firstToken, endToken, nextStep, _choosable.begin()));
}

void Choice::_afterValidation()
{
	_stack.pop();
}

bool Choice::_startValidation(CompositeMarkupNode::ChildrenIterator firstToken,
		CompositeMarkupNode::ChildrenIterator endToken,
		BrowseableContent* nextStep)
{
	// Premier appel de validation, aucune alternative de choix n'a
	//	été validée pour le moment.

	_State & state = _stack.top();
	// TODO
	return false;
}

bool Choice::_continueValidation(
		xml::CompositeMarkupNode::ChildrenIterator currentToken)
{
	_State & state = _stack.top();
	// TODO
	return false;
}

} // namespace dtd
