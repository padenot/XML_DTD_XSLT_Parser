/*************************************************************************
 * Element  -  «Description»
 * -------------------
 * Début      : lun. 04 avril 2011 10:13:39 CEST
 * Auteur(s)  : H4215
*************************************************************************/

//---- Interface de la classe <Element> (fichier Element.hh) ----
#ifndef ELEMENT_HH
#define ELEMENT_HH

//--------------------------------------------------- Interfaces utilisées
#include "InterfaceElement.hh"

//------------------------------------------------------------------------
// Rôle de la classe <Element>
//	«Rôle»
//
//------------------------------------------------------------------------

namespace dtd
{

class Element : public InterfaceElement
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
	Element & operator = ( const Element & unElement );
	// Mode d'emploi :
	//	«TODO»
	// Contrat :
	//	«TODO»


//-------------------------------------------- Constructeurs - destructeur
	Element ( const Element & unElement );
	// Mode d'emploi (constructeur de copie) :
	//	«Mode emploi»
	// Contrat :
	//	«TODO»

	Element ( );
	// Mode d'emploi (constructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

	virtual ~Element ( );
	// Mode d'emploi (destructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

protected:

};

} // namespace dtd

#endif // ELEMENT_HH

