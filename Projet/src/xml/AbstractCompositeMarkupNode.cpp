/*************************************************************************
 * AbstractCompositeMarkupNode  -  «Description»
 * -------------------
 * Début      : lun. 04 avril 2011 09:05:13 CEST
 * Auteur(s)  : H4215
*************************************************************************/

//---- Réalisation de la classe <AbstractCompositeMarkupNode> (fichier AbstractCompositeMarkupNode.cpp) ----

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "AbstractCompositeMarkupNode.hh"

namespace xml
{
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type AbstractCompositeMarkupNode::Méthode ( liste de paramètres )
// Algorithme :
//	«TODO»
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
AbstractCompositeMarkupNode & AbstractCompositeMarkupNode::operator = ( const AbstractCompositeMarkupNode & unAbstractCompositeMarkupNode )
// Algorithme :
//	«TODO»
{
	//TODO
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
AbstractCompositeMarkupNode::AbstractCompositeMarkupNode ( const AbstractCompositeMarkupNode & unAbstractCompositeMarkupNode ) // TODO
// Algorithme :
//	«TODO»
{
	//TODO
} //----- Fin de AbstractCompositeMarkupNode (constructeur de copie)


AbstractCompositeMarkupNode::AbstractCompositeMarkupNode ( Node * parent )
	: MarkupNode ( parent ) // TODO
// Algorithme :
//	«TODO»
{
	// TODO
} //----- Fin de AbstractCompositeMarkupNode


AbstractCompositeMarkupNode::~AbstractCompositeMarkupNode ( )
// Algorithme :
//	«TODO»
{
	//TODO
} //----- Fin de ~AbstractCompositeMarkupNode


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

} // namespace xml
