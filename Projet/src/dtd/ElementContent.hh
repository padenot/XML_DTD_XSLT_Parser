/*************************************************************************
 * ElementContent  -  «Description»
 * -------------------
 * Début      : lun. 04 avril 2011 10:14:09 CEST
 * Auteur(s)  : H4215
*************************************************************************/

//---- Interface de la classe <ElementContent> (fichier ElementContent.hh) ----
#ifndef ELEMENTCONTENT_HH
#define ELEMENTCONTENT_HH

//--------------------------------------------------- Interfaces utilisées
#include "QuantifiableContent.hh"

//------------------------------------------------------------------------
// Rôle de la classe <ElementContent>
//	«Rôle»
//
//------------------------------------------------------------------------

namespace dtd
{

class ElementContent : public QuantifiableContent
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
	ElementContent & operator = ( const ElementContent & unElementContent );
	// Mode d'emploi :
	//	«TODO»
	// Contrat :
	//	«TODO»


//-------------------------------------------- Constructeurs - destructeur
	ElementContent ( const ElementContent & unElementContent );
	// Mode d'emploi (constructeur de copie) :
	//	«Mode emploi»
	// Contrat :
	//	«TODO»

	ElementContent ( );
	// Mode d'emploi (constructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

	virtual ~ElementContent ( );
	// Mode d'emploi (destructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

protected:

};

} // namespace dtd

#endif // ELEMENTCONTENT_HH

