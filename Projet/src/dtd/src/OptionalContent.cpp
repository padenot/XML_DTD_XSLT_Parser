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
OptionalContent::OptionalContent(NonEmptyContent & content) :
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

} // namespace dtd
