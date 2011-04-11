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

Sequence::OrderedContentIterator Sequence::begin() const
{
	return _embeddedContent.begin();
}

Sequence::OrderedContentIterator Sequence::end() const
{
	return _embeddedContent.end();
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
		BrowsableContent* nextStep)
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
		CompositeMarkupNode::ChildrenIterator, BrowsableContent*)
{
	// Il n'y a aucune différence entre l'algorithme de la première
	//	étape de validation d'une séquence et les suivantes.
	return _continueValidation(firstToken);
}

bool Sequence::_continueValidation(
		xml::CompositeMarkupNode::ChildrenIterator currentToken)
{
	_State & state = _stack.top();

	if (state.nextEmbeddedContent != _embeddedContent.end())
	{
		// Fin de séquence non atteinte : on teste le contenu incrusté suivant.
		BrowsableContent& currentEmbeddedContent = **state.nextEmbeddedContent;
		++state.nextEmbeddedContent;

		if (_browseDown(currentEmbeddedContent, currentToken, state.endToken,
				this))
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

		return _browseUp(state.nextStep, currentToken, state.endToken);
	}
}

} // namespace dtd
