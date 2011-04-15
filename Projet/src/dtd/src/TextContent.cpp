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
	// Rien à faire.
}

TextContent::~TextContent()
{
	// Rien à faire.
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
bool TextContent::_startValidation(
		CompositeMarkupNode::ChildrenIterator firstToken,
		CompositeMarkupNode::ChildrenIterator endToken,
		BrowsableContent* nextStep)
{
	if (firstToken == endToken)
	{
		// Il n'y a pas de jeton à consommer :
		//	le matching avec cet objet est impossible.
		return false;
	}
	else
	{
		(*firstToken)->accept(*this);

		if (_validationResult)
		{
			// Le jeton est consommé.
			++firstToken;

			return _browseUp(nextStep, firstToken, endToken);
		}
		else
		{
			// Le jeton courant est incorrect.
			return false;
		}
	}
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
