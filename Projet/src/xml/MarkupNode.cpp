/*************************************************************************
 * MarkupNode  -  «Description»
 * -------------------
 * Début      : lun. 04 avril 2011 09:01:48 CEST
 * Auteur(s)  : H4215
*************************************************************************/

//---- Réalisation de la classe <MarkupNode> (fichier MarkupNode.cpp) ----

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "MarkupNode.hh"

namespace xml
{
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type MarkupNode::Méthode ( liste de paramètres )
// Algorithme :
//	«TODO»
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
MarkupNode & MarkupNode::operator = ( const MarkupNode & unMarkupNode )
// Algorithme :
//	«TODO»
{
	// TODO
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
MarkupNode::MarkupNode ( const MarkupNode & unMarkupNode ) // TODO
// Algorithme :
//	«TODO»
{
} //----- Fin de MarkupNode (constructeur de copie)


MarkupNode::MarkupNode ( Node * parent, std::string ns, std::string name ) :
	Node(parent),
	_namespace(ns),
	_name(name)
// Algorithme :
//	«TODO»
{
	// TODO
} //----- Fin de MarkupNode


MarkupNode::~MarkupNode ( )
// Algorithme :
//	«TODO»
{
	// TODO
} //----- Fin de ~MarkupNode


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

} // namespace xml
