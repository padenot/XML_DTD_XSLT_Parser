/*************************************************************************
 * QuantifiedContent  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Réalisation de la classe <QuantifiedContent> (fichier QuantifiedContent.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "QuantifiedContent.hh"

namespace dtd
{
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type QuantifiedContent::Méthode ( liste des paramètres )
// Algorithme :
//	
//{
//}

NonEmptyContent & QuantifiedContent::content()
{
	return _content;
}

const NonEmptyContent & QuantifiedContent::content() const
{
	return _content;
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
QuantifiedContent::QuantifiedContent(NonEmptyContent & content) :
	_content(content)
{
	//TODO
}

QuantifiedContent::~QuantifiedContent()
{
	delete &_content;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

} // namespace dtd
