/*************************************************************************
 * ElementRef  -  «Description»
 * -------------------
 * Début      : lun. 04 avril 2011 10:16:06 CEST
 * Auteur(s)  : H4215
*************************************************************************/

//---- Interface de la classe <ElementRef> (fichier ElementRef.hh) ----
#ifndef ELEMENTREF_HH
#define ELEMENTREF_HH

//--------------------------------------------------- Interfaces utilisées
#include "InterfaceElement.hh"
#include "ElementContent.hh"

//------------------------------------------------------------------------
// Rôle de la classe <ElementRef>
//	«Rôle»
//
//------------------------------------------------------------------------

namespace dtd
{

class ElementRef : public InterfaceElement, ElementContent
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
	ElementRef & operator = ( const ElementRef & unElementRef );
	// Mode d'emploi :
	//	«TODO»
	// Contrat :
	//	«TODO»


//-------------------------------------------- Constructeurs - destructeur
	ElementRef ( const ElementRef & unElementRef );
	// Mode d'emploi (constructeur de copie) :
	//	«Mode emploi»
	// Contrat :
	//	«TODO»

	ElementRef ( );
	// Mode d'emploi (constructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

	virtual ~ElementRef ( );
	// Mode d'emploi (destructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

protected:

};

} // namespace dtd

#endif // ELEMENTREF_HH

