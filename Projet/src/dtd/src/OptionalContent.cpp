/*************************************************************************
 * OptionalContent  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Réalisation de la classe <OptionalContent> (fichier OptionalContent.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "OptionalContent.hh"
#include "InterfaceDTDVisitor.hpp"
using namespace xml;

namespace dtd
{
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type OptionalContent::Méthode ( liste des paramètres )
// Algorithme :
//	
//{
//}

void OptionalContent::accept(InterfaceDTDVisitor & visitor) const
{
	visitor.visit(*this);
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
OptionalContent::OptionalContent(QuantifiableContent & content) :
	QuantifiedContent(content)
{
	//TODO
}

OptionalContent::~OptionalContent()
{
	//TODO
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
bool OptionalContent::_startValidation(
		CompositeMarkupNode::ChildrenIterator firstToken,
		CompositeMarkupNode::ChildrenIterator endToken,
		BrowsableContent* nextStep)
{
	if (_browseDown(_content, firstToken, endToken, this))
	{
		// La liste de jetons est valide en incluant le contenu optionnel
		return true;
	}
	else if (_browseUp(nextStep, firstToken, endToken))
	{
		// La liste de jetons est valide en excluant le contenu optionnel
		return true;
	}
	else
	{
		// La liste de jetons est invalide
		return false;
	}
}

bool OptionalContent::_continueValidation(
		xml::CompositeMarkupNode::ChildrenIterator currentToken)
{
	_State& state = _stack.top();

	// Arrivé à ce stade, la liste de jetons a permis de lui faire
	//	correspondre le contenu optionnel. On vérifie que le reste du
	//	contenu peut être validé également.
	return _browseUp(state.nextStep, currentToken, state.endToken);
}

} // namespace dtd
