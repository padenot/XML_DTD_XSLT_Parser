/*************************************************************************
 * RepeatableContent  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Réalisation de la classe <RepeatableContent> (fichier RepeatableContent.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "RepeatableContent.hh"
#include "InterfaceDTDVisitor.hpp"
using namespace xml;

namespace dtd
{
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type RepeatableContent::Méthode ( liste des paramètres )
// Algorithme :
//	
//{
//}

void RepeatableContent::accept(InterfaceDTDVisitor & visitor) const
{
	visitor.visit(*this);
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
RepeatableContent::RepeatableContent(QuantifiableContent & content) :
	QuantifiedContent(content)
{
	//TODO
}

RepeatableContent::~RepeatableContent()
{
	//TODO
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
bool RepeatableContent::_startValidation(
		CompositeMarkupNode::ChildrenIterator firstToken,
		CompositeMarkupNode::ChildrenIterator endToken,
		BrowsableContent* nextStep)
{
	//TODO
	return false;
}

bool RepeatableContent::_continueValidation(
		xml::CompositeMarkupNode::ChildrenIterator currentToken)
{
	//TODO
	return false;
}

} // namespace dtd
