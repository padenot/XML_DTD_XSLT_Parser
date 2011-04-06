/*************************************************************************
 * Content  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Réalisation de la classe <Content> (fichier Content.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "Content.hh"
#include "TextNode.hh"
using namespace xml;

namespace dtd
{
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Content::Méthode ( liste des paramètres )
// Algorithme :
//	
//{
//}

bool Content::validate(const TextNode& node)
// Algorithme :
//	Méthode surchargée dans TextContent pour avoir un
//	résultat positif.
{
	return false;
}

bool Content::validate(const MarkupNode& node)
// Algorithme :
//	Méthode surchargée dans EmptyContent pour avoir un
//	résultat positif.
{
	return false;
}

bool Content::validate(const CompositeMarkupNode& node)
// Algorithme :
//	Initialise la récursion.
{
	return _newValidation(node.begin(), node.end(), 0);
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Content::Content()
{
	//TODO
}

Content::~Content()
{
	//TODO
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

bool Content::_newValidation(
		xml::CompositeMarkupNode::ChildrenIterator firstToken,
		xml::CompositeMarkupNode::ChildrenIterator endToken, Content* nextStep)
// Algorithme :
//	TODO
{
	bool result;

	_pushState(nextStep);
	result = _continueValidation(firstToken, endToken);
	_popState();

	return result;
}

} // namespace dtd
