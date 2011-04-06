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

void Sequence::accept(InterfaceDTDVisitor & visitor) const
{
	visitor.visit(*this);
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Sequence::Sequence(const SequenceElements & elements) :
	_elements(elements)
{
	//TODO
}

Sequence::~Sequence()
{
	for (_SequenceElements::iterator it = _elements.begin(); it
			!= _elements.end(); ++it)
	{
		delete *it;
	}
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void Sequence::_pushState(Content* nextStep)
{
	//_stack.push(new )
	//TODO
}

void Sequence::_popState()
{
	//TODO
}

bool Sequence::_continueValidation(xml::CompositeMarkupNode::ChildrenIterator firstToken,
		xml::CompositeMarkupNode::ChildrenIterator endToken) const
{
	//TODO
}

} // namespace dtd
