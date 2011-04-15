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
#include <string>

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
void TextNode::accept(InterfaceNodeVisitor& visitor) const
{
	visitor.visit(*this);
}

string TextNode::content() const
{
	return _content;
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
TextNode::TextNode(CompositeMarkupNode ** parent, const string & content) :
	Node(parent), _content(content)
{
	// Rien à faire.
} //----- Fin de TextNode


TextNode::~TextNode()
{
	// Rien à faire.
} //----- Fin de ~TextNode


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


//------------------------------------------------------- Méthodes privées

} // namespace xml
