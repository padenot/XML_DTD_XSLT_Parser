/*************************************************************************
 * Sequence  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Réalisation de la classe <Sequence> (fichier Sequence.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "Sequence.hh"
#include "InterfaceDTDVisitor.hpp"
using namespace xml;

namespace dtd
{
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Sequence::Méthode ( liste des paramètres )
// Algorithme :
//	
//{
//}

bool Sequence::validate(const CompositeMarkupNode& node)
// Algorithme :
//	Initialise la validation récursive (récursion sur les éléments de la
//	séquence).
{
	return _newValidation(node.begin(), node.end(), 0);
}

void Sequence::accept(InterfaceDTDVisitor & visitor) const
{
	visitor.visit(*this);
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Sequence::Sequence(const OrderedContent & embeddedContent) :
	_embeddedContent(embeddedContent)
{
	//TODO
}

Sequence::~Sequence()
{
	for (_OrderedContent::iterator it = _embeddedContent.begin(); it
			!= _embeddedContent.end(); ++it)
	{
		delete *it;
	}
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void Sequence::_beforeValidation(
		xml::CompositeMarkupNode::ChildrenIterator firstToken,
		xml::CompositeMarkupNode::ChildrenIterator endToken,
		_InterfaceValidator* nextStep)
{
	_stack.push(
			_State(firstToken, endToken, nextStep, _embeddedContent.begin()));
}

void Sequence::_afterValidation()
{
	_stack.pop();
}

bool Sequence::_startValidation(
		CompositeMarkupNode::ChildrenIterator firstToken,
		CompositeMarkupNode::ChildrenIterator endToken,
		_InterfaceValidator* nextStep)
{
	// Il n'y a aucune différence entre l'algorithme de la première
	//	étape de validation d'une séquence et les suivantes.
	return _continueValidation(firstToken);
}

bool Sequence::_continueValidation(
		xml::CompositeMarkupNode::ChildrenIterator currentToken)
// Note : comme aucune décision n'est prise dans cette méthode, le
//	véritable backtracking est délégué aux objets ayant demandé la validation
//	en renvoyant faux.
{
	_State & state = _stack.top();

	if (state.nextEmbeddedContent != _embeddedContent.end())
	{
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
	}
	else
	{
		// Fin de séquence atteinte : l'objet a été consommé (on a trouvé des
		//	noeuds correspondant à la séquence).

		if (state.nextStep == 0)
		{
			// La séquence était à l'origine de la validation : tout est ok
			//	si on a réussi à atteindre la fin de la liste de noeuds
			return currentToken == state.endToken;
		}
		else
		{
			// La séquence était subordonnée à un contenu englobant :
			//	d'autres jetons peuvent/doivent peut-être être consommés.
			return state.nextStep->_continueValidation(currentToken);
		}
	}
}

} // namespace dtd
