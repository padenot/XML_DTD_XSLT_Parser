/*************************************************************************
 * AnyContent  -  «Description»
 * -------------------
 * Début      : 6 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Réalisation de la classe <AnyContent> (fichier AnyContent.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "AnyContent.hh"
#include "InterfaceDTDVisitor.hpp"
using namespace xml;

namespace dtd
{
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type AnyContent::Méthode ( liste des paramètres )
// Algorithme :
//	
//{
//}

bool AnyContent::validate(const MarkupNode &)
{
	return true;
}

bool AnyContent::validate(const CompositeMarkupNode &)
{
	return true;
}

void AnyContent::accept(InterfaceDTDVisitor & visitor) const
{
	visitor.visit(*this);
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
AnyContent::AnyContent()
{
	//TODO
}

AnyContent::~AnyContent()
{
	//TODO
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

} // namespace dtd
