/*************************************************************************
 * CompositeMarkupNodeProxy  -  «Description»
 * -------------------
 * Début      : lun. 04 avril 2011 08:54:19 CEST
 * Auteur(s)  : H4215
*************************************************************************/

//---- Interface de la classe <CompositeMarkupNodeProxy> (fichier CompositeMarkupNodeProxy.hh) ----
#ifndef COMPOSITEMARKUPNODEPROXY_HH
#define COMPOSITEMARKUPNODEPROXY_HH

//--------------------------------------------------- Interfaces utilisées
#include <list>
#include "AbstractCompositeMarkupNode.hh"

//------------------------------------------------------------------------
// Rôle de la classe <CompositeMarkupNodeProxy>
//	«Rôle»
//
//------------------------------------------------------------------------

namespace xml
{

class CompositeMarkupNodeProxy : public AbstractCompositeMarkupNode
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
	CompositeMarkupNodeProxy & operator = ( const CompositeMarkupNode & unCompositeMarkupNode );
	// Mode d'emploi :
	//	«TODO»
	// Contrat :
	//	«TODO»


//-------------------------------------------- Constructeurs - destructeur
	CompositeMarkupNodeProxy ( const CompositeMarkupNode & unCompositeMarkupNode );
	// Mode d'emploi (constructeur de copie) :
	//	«Mode emploi»
	// Contrat :
	//	«TODO»

	CompositeMarkupNodeProxy ( );
	// Mode d'emploi (constructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

	virtual ~CompositeMarkupNodeProxy ( );
	// Mode d'emploi (destructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

protected:

};

} // namespace xml

#endif // COMPOSITEMARKUPNODEPROXY_HH

