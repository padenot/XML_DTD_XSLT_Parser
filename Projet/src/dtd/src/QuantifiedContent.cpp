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
using namespace xml;

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

bool QuantifiedContent::validate(const CompositeMarkupNode& node)
// Algorithme :
//	Initialise la validation récursive (récursion sur le contenu quantifié).
{
	return _newValidation(node.begin(), node.end(), 0);
}

QuantifiableContent & QuantifiedContent::content()
{
	return _content;
}

const QuantifiableContent & QuantifiedContent::content() const
{
	return _content;
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
QuantifiedContent::QuantifiedContent(QuantifiableContent & content) :
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
void QuantifiedContent::_pushState(
		xml::CompositeMarkupNode::ChildrenIterator firstToken,
		xml::CompositeMarkupNode::ChildrenIterator endToken,
		NonEmptyContent* nextStep)
{
	//TODO
}

void QuantifiedContent::_popState()
{
	//TODO
}

} // namespace dtd
