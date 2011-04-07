/*************************************************************************
 * TextContent  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Réalisation de la classe <TextContent> (fichier TextContent.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "TextContent.hh"
#include "InterfaceDTDVisitor.hpp"
using namespace xml;

namespace dtd
{
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TextContent::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//}

void TextContent::accept(InterfaceDTDVisitor & visitor) const
{
	visitor.visit(*this);
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
TextContent::TextContent()
{
	//TODO
}

TextContent::~TextContent()
{
	//TODO
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
bool TextContent::_continueValidation(
		xml::CompositeMarkupNode::ChildrenIterator currentToken)
{
	//TODO
	return false;
}

void TextContent::visit(const TextNode&)
{
	_validationResult = true;
}

void TextContent::visit(const MarkupNode&)
{
	_validationResult = false;
}

void TextContent::visit(const CompositeMarkupNode&)
{
	_validationResult = false;
}

} // namespace dtd
