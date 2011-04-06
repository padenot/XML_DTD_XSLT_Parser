/*************************************************************************
 * AttributesList  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Réalisation de la classe <AttributesList> (fichier AttributesList.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "AttributesList.hh"
#include "InterfaceDTDVisitor.hpp"

namespace dtd
{
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type AttributesList::Méthode ( liste des paramètres )
// Algorithme :
//	
//{
//}

string AttributesList::name() const
{
	return _name;
}

void AttributesList::accept(InterfaceDTDVisitor& visitor) const
{
	visitor.visit(*this);
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
AttributesList::AttributesList(const string & name) :
	_name(name)
{
	//TODO
}

AttributesList::~AttributesList()
{
	//TODO
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

} // namespace dtd
