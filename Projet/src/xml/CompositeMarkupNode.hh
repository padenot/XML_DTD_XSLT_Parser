/*************************************************************************
 * CompositeMarkupNode  -  «Description»
 * -------------------
 * Début      : lun. 04 avril 2011 08:54:19 CEST
 * Auteur(s)  : H4215
*************************************************************************/

//---- Interface de la classe <CompositeMarkupNode> (fichier CompositeMarkupNode.hh) ----
#ifndef COMPOSITEMARKUPNODE_HH
#define COMPOSITEMARKUPNODE_HH

//--------------------------------------------------- Interfaces utilisées
#include <list>
#include "MarkupNode.hh"

//------------------------------------------------------------------------
// Rôle de la classe <CompositeMarkupNode>
//	«Rôle»
//
//------------------------------------------------------------------------

namespace xml
{

class CompositeMarkupNode : public MarkupNode
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
	CompositeMarkupNode & operator = ( const CompositeMarkupNode & unCompositeMarkupNode );
	// Mode d'emploi :
	//	«TODO»
	// Contrat :
	//	«TODO»


//-------------------------------------------- Constructeurs - destructeur
	CompositeMarkupNode ( const CompositeMarkupNode & unCompositeMarkupNode );
	// Mode d'emploi (constructeur de copie) :
	//	«Mode emploi»
	// Contrat :
	//	«TODO»

	CompositeMarkupNode ( );
	// Mode d'emploi (constructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

	virtual ~CompositeMarkupNode ( );
	// Mode d'emploi (destructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

protected:
	typedef std::list<Node> Children;
	Children _children;

};

} // namespace xml

#endif // COMPOSITEMARKUPNODE_HH

