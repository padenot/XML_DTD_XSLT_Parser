/*************************************************************************
 * Node  -  «Description»
 * -------------------
 * Début      : lun. 04 avril 2011 08:59:41 CEST
 * Auteur(s)  : H4215
*************************************************************************/

//---- Réalisation de la classe <Node> (fichier Node.cpp) ----

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "Node.hh"

namespace xml
{
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Node::Méthode ( liste de paramètres )
// Algorithme :
//	«TODO»
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
Node & Node::operator = ( const Node & unNode )
// Algorithme :
//	«TODO»
{
	// TODO
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Node::Node ( const Node & unNode ) // TODO
// Algorithme :
//	«TODO»
{
} //----- Fin de Node (constructeur de copie)


Node::Node ( AbstractCompositeMarkupNode * parent ) :
	_parent(parent)
// Algorithme :
//	«TODO»
{
	// TODO
} //----- Fin de Node


Node::~Node ( )
// Algorithme :
//	«TODO»
{
	// TODO
} //----- Fin de ~Node


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

} // namespace xml
