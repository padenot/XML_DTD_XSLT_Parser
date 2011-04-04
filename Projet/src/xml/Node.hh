/*************************************************************************
 * Node  -  «Description»
 * -------------------
 * Début      : lun. 04 avril 2011 08:46:08 CEST
 * Auteur(s)  : H4215
*************************************************************************/

//---- Interface de la classe <Node> (fichier Node.hh) ----
#ifndef NODE_HH
#define NODE_HH

//--------------------------------------------------- Interfaces utilisées
class AbstractCompositeMarkupNode;

//------------------------------------------------------------------------
// Rôle de la classe <Node>
//	«Rôle»
//
//------------------------------------------------------------------------

namespace xml
{

class Node
{
public:
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//	«TODO»
	// Contrat :
	//	«TODO»


//------------------------------------------------- Surcharge d'opérateurs
	Node & operator = ( const Node & aNode );
	// Mode d'emploi :
	//	«TODO»
	// Contrat :
	//	«TODO»


//-------------------------------------------- Constructeurs - destructeur
	Node ( const Node & aNode );
	// Mode d'emploi (constructeur de copie) :
	//	«Mode emploi»
	// Contrat :
	//	«TODO»

	Node ( AbstractCompositeMarkupNode * parent );
	// Mode d'emploi (constructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

	virtual ~Node ( );
	// Mode d'emploi (destructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

protected:
	AbstractCompositeMarkupNode* _parent;
};

} // namespace xml

#endif // NODE_HH

