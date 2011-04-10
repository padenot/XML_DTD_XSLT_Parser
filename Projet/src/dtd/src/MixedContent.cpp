/*************************************************************************
 * MixedContent  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Réalisation de la classe <MixedContent> (fichier MixedContent.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "MixedContent.hh"
#include "TextContent.hh"
#include "ElementReference.hh"
#include "InterfaceDTDVisitor.hpp"
using namespace xml;

namespace dtd
{
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type MixedContent::Méthode ( liste des paramètres )
// Algorithme :
//	
//{
//}

bool MixedContent::validate(const CompositeMarkupNode& node)
// Algorithme :
//	Initialise la validation récursive (récursion sur les éléments de choix).
{
	return _newValidation(node.begin(), node.end(), 0);
}

void MixedContent::accept(InterfaceDTDVisitor & visitor) const
{
	visitor.visit(*this);
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
MixedContent::MixedContent(TextContent & textContent,
		const ChoosableSet & choosable) :
	_choice(choosable), _textContent(textContent)
{
	// Do nothing
}

MixedContent::~MixedContent()
{
	delete &_textContent;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void MixedContent::_beforeValidation(
		xml::CompositeMarkupNode::ChildrenIterator firstToken,
		xml::CompositeMarkupNode::ChildrenIterator endToken,
		BrowseableContent* nextStep)
{
	_stack.push(_State(firstToken, endToken, nextStep));
}

void MixedContent::_afterValidation()
{
	_stack.pop();
}

bool MixedContent::_startValidation(
		CompositeMarkupNode::ChildrenIterator firstToken,
		CompositeMarkupNode::ChildrenIterator endToken,
		BrowseableContent* nextStep)
{
	_State& state = _stack.top();

	return _browseDown(_textContent, state.firstToken, state.endToken, this)
			|| _browseDown(_choice, state.firstToken, state.endToken, this);
}

bool MixedContent::_continueValidation(
		xml::CompositeMarkupNode::ChildrenIterator currentToken)
{
	// Si cette méthode est appelée, c'est que l'une des alternatives de choix
	//	a été validée (que ce soit "_textContent" ou une alternative de "_choice").
	_State& state = _stack.top();

	if (state.nextStep == 0)
	{
		// L'objet était à l'origine de la validation : tout est ok
		//	si on a réussi à atteindre la fin de la liste de noeuds
		return currentToken == state.endToken;
	}
	else
	{
		// L'objet était subordonnée à un contenu englobant :
		//	d'autres jetons peuvent/doivent peut-être être consommés.
		return _browseUp(*state.nextStep, currentToken);
	}
}

} // namespace dtd
