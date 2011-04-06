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

void MixedContent::accept(InterfaceDTDVisitor & visitor) const
{
	visitor.visit(*this);
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
MixedContent::MixedContent(const ChoiceElements & elements) :
	_elements(elements)
{

}

MixedContent::~MixedContent()
{
	for (_ChoiceElements::iterator it = _elements.begin(); it
			!= _elements.end(); ++it)
	{
		delete *it;
	}
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void MixedContent::_pushState(Content* nextStep)
{
	//_stack.push(new )
	//TODO
}

void MixedContent::_popState()
{
	//TODO
}

bool MixedContent::_continueValidation(
		xml::CompositeMarkupNode::ChildrenIterator firstToken,
		xml::CompositeMarkupNode::ChildrenIterator endToken) const
{
	//TODO
}

} // namespace dtd
