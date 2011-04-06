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

void Choice::accept(InterfaceDTDVisitor & visitor) const
{
	visitor.visit(*this);
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Choice::Choice(const ChoiceElements & elements) :
	_elements(elements)
{
	//TODO
}

Choice::~Choice()
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
