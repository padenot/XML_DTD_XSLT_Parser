/*************************************************************************
 * AbstractCompositeMarkupNode  -  «Description»
 * -------------------
 * Début      : lun. 04 avril 2011 08:54:19 CEST
 * Auteur(s)  : H4215
*************************************************************************/

//---- Interface de la classe <AbstractCompositeMarkupNode> (fichier AbstractCompositeMarkupNode.hh) ----
#ifndef ABSTRACTCOMPOSITEMARKUPNODE_HH
#define ABSTRACTCOMPOSITEMARKUPNODE_HH

//--------------------------------------------------- Interfaces utilisées
#include <list>
#include "MarkupNode.hh"

//------------------------------------------------------------------------
// Rôle de la classe <AbstractCompositeMarkupNode>
//	«Rôle»
//
//------------------------------------------------------------------------

namespace xml
{

class AbstractCompositeMarkupNode : public MarkupNode
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
	AbstractCompositeMarkupNode & operator = ( const AbstractCompositeMarkupNode & unAbstractCompositeMarkupNode );
	// Mode d'emploi :
	//	«TODO»
	// Contrat :
	//	«TODO»


//-------------------------------------------- Constructeurs - destructeur
	AbstractCompositeMarkupNode ( const AbstractCompositeMarkupNode & unAbstractCompositeMarkupNode );
	// Mode d'emploi (constructeur de copie) :
	//	«Mode emploi»
	// Contrat :
	//	«TODO»

	AbstractCompositeMarkupNode ( Node * parent, std::string ns, std::string name );
	// Mode d'emploi (constructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

	virtual ~AbstractCompositeMarkupNode ( );
	// Mode d'emploi (destructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

protected:

};

} // namespace xml

#endif // ABSTRACTCOMPOSITEMARKUPNODE_HH

