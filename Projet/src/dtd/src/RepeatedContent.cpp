/*************************************************************************
 * RepeatedContent  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Réalisation de la classe <RepeatedContent> (fichier RepeatedContent.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "RepeatedContent.hh"
#include "InterfaceDTDVisitor.hpp"

namespace dtd
{
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type RepeatedContent::Méthode ( liste des paramètres )
// Algorithme :
//	
//{
//}

void RepeatedContent::accept(InterfaceDTDVisitor & visitor) const
{
	visitor.visit(*this);
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
RepeatedContent::RepeatedContent(QuantifiableContent & content) :
	QuantifiedContent(content)
{
	//TODO
}

RepeatedContent::~RepeatedContent()
{
	//TODO
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
bool RepeatedContent::_continueValidation(
		xml::CompositeMarkupNode::ChildrenIterator currentToken)
{
	//TODO
	return false;
}

} // namespace dtd
