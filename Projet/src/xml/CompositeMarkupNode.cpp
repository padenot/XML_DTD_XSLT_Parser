/*************************************************************************
 * CompositeMarkupNode  -  «Description»
 * -------------------
 * Début      : lun. 04 avril 2011 09:05:13 CEST
 * Auteur(s)  : H4215
*************************************************************************/

//---- Réalisation de la classe <CompositeMarkupNode> (fichier CompositeMarkupNode.cpp) ----

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "CompositeMarkupNode.hh"

namespace xml
{
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type CompositeMarkupNode::Méthode ( liste de paramètres )
// Algorithme :
//	«TODO»
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
CompositeMarkupNode & CompositeMarkupNode::operator = ( const CompositeMarkupNode & unCompositeMarkupNode )
// Algorithme :
//	«TODO»
{
	//TODO
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
CompositeMarkupNode::CompositeMarkupNode ( const CompositeMarkupNode & unCompositeMarkupNode ) // TODO
// Algorithme :
//	«TODO»
{
	//TODO
} //----- Fin de CompositeMarkupNode (constructeur de copie)


CompositeMarkupNode::CompositeMarkupNode ( Node * parent, std::string ns,
	std::string name, CompositeMarkupNodeProxy & proxy, std::list<Node> & 
	children)
		: AbstractCompositeMarkupNode( parent, ns, name ), 
			_children( children )
// Algorithme :
//	«TODO»
{
	// TODO use proxy
} //----- Fin de CompositeMarkupNode


CompositeMarkupNode::~CompositeMarkupNode ( )
// Algorithme :
//	«TODO»
{
	//TODO
} //----- Fin de ~CompositeMarkupNode


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

} // namespace xml
