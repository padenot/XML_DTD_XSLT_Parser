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
MixedContent::MixedContent(const ChoosableSet & choosable) :
	_choosable(choosable)
{

}

MixedContent::~MixedContent()
{
	for (_ChoosableSet::iterator it = _choosable.begin(); it
			!= _choosable.end(); ++it)
	{
		delete *it;
	}
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void MixedContent::_pushState(
		xml::CompositeMarkupNode::ChildrenIterator firstToken,
		xml::CompositeMarkupNode::ChildrenIterator endToken,
		NonEmptyContent* nextStep)
{
	//TODO
}

void MixedContent::_popState()
{
	//TODO
}

bool MixedContent::_continueValidation(
		xml::CompositeMarkupNode::ChildrenIterator currentToken)
{
	//TODO
	return false;
}

} // namespace dtd
