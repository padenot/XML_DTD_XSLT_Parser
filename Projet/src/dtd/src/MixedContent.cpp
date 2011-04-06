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
	//TODO
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

} // namespace dtd
