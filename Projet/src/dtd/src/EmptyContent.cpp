/*************************************************************************
 * EmptyContent  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Réalisation de la classe <EmptyContent> (fichier EmptyContent.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "EmptyContent.hh"
#include "InterfaceDTDVisitor.hpp"
using namespace xml;

namespace dtd
{
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type EmptyContent::Méthode ( liste des paramètres )
// Algorithme :
//	
//{
//}

bool EmptyContent::validate(const MarkupNode &)
{
	return true;
}

bool EmptyContent::validate(const CompositeMarkupNode &)
{
	return false;
}

void EmptyContent::accept(InterfaceDTDVisitor & visitor) const
{
	visitor.visit(*this);
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
EmptyContent::EmptyContent()
{
	// Rien à faire.
}

EmptyContent::~EmptyContent()
{
	// Rien à faire.
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


} // namespace dtd
