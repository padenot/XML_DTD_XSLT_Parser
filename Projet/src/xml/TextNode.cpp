/*************************************************************************
 * TextNode  -  «Description»
 * -------------------
 * Début      : lun. 04 avril 2011 09:03:16 CEST
 * Auteur(s)  : H4215
*************************************************************************/

//---- Réalisation de la classe <TextNode> (fichier TextNode.cpp) ----

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "TextNode.hh"

namespace xml
{
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type TextNode::Méthode ( liste de paramètres )
// Algorithme :
//	«TODO»
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
TextNode & TextNode::operator = ( const TextNode & unTextNode )
// Algorithme :
//	«TODO»
{
	// TODO
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
TextNode::TextNode ( const TextNode & unTextNode ) // TODO
// Algorithme :
//	«TODO»
{
	//TODO
} //----- Fin de TextNode (constructeur de copie)


TextNode::TextNode ( Node * parent, string content ) :
	Node(parent),
	_content(content)
// Algorithme :
//	«TODO»
{
	//TODO
} //----- Fin de TextNode


TextNode::~TextNode ( )
// Algorithme :
//	«TODO»
{
	//TODO
} //----- Fin de ~TextNode


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

} // namespace xml
