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
#include <iostream>
#include <iomanip>

//------------------------------------------------------ Include personnel
#include "Node.hh"

namespace xml
{
//------------------------------------------------------------- Constantes
const char Node::INDENT_CHAR = ' ';
const unsigned char Node::INDENT_UNIT = 1;

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies
ostream& operator <<(ostream& out, const Node & aNode)
{
	return aNode.Write(out);
}


//----------------------------------------------------- Méthodes publiques
// type Node::Méthode ( liste de paramètres )
// Algorithme :
//	«TODO»
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Node::Node(CompositeMarkupNode *& parent) :
	_parent(parent)
{
	// Rien à faire
} //----- Fin de Node


Node::~Node()
{
	// Rien à faire
} //----- Fin de ~Node


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
ostream & Node::doIndent(ostream& out, unsigned char indent)
{
	if (indent > 0)
	{
		char fillChar = out.fill(INDENT_CHAR);
		out << setw(indent * INDENT_UNIT) << INDENT_CHAR;
		out.fill(fillChar);
	}
	return out;
}

//------------------------------------------------------- Méthodes privées

} // namespace xml
