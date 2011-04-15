/*************************************************************************
 * XmlTreeBuilding  -  Construction d'arbres XML pour tests.
 * -------------------
 * Début      : mar. 06 avril 2011 15:51:26 CEST
 * Auteur(s)  : H4215
 *************************************************************************/

#if ! defined (XMLTREEBUILDING_HH)
#define XMLTREEBUILDING_HH

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "Node.hh"

//------------------------------------------------------------- Constantes

//-------------------------------------------------------------- Fonctions
xml::Node* trivialTree(unsigned int offset = 0,
		xml::CompositeMarkupNode** rootParent = 0);
xml::Node* simpleTree(unsigned int offset = 0,
		xml::CompositeMarkupNode** rootParent = 0);
xml::Node* normalTree(unsigned int offset = 0,
		xml::CompositeMarkupNode** rootParent = 0);

#endif // XMLTREEBUILDING_HH
