/*************************************************************************
 * EmptyContent  -  «Description»
 * -------------------
 * Début      : lun. 04 avril 2011 10:15:14 CEST
 * Auteur(s)  : H4215
*************************************************************************/

//---- Interface de la classe <EmptyContent> (fichier EmptyContent.hh) ----
#ifndef EMPTYCONTENT_HH
#define EMPTYCONTENT_HH

//--------------------------------------------------- Interfaces utilisées
#include "Content.hh"

//------------------------------------------------------------------------
// Rôle de la classe <EmptyContent>
//	«Rôle»
//
//------------------------------------------------------------------------

namespace dtd
{

class EmptyContent : public Content
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
	EmptyContent & operator = ( const EmptyContent & unEmptyContent );
	// Mode d'emploi :
	//	«TODO»
	// Contrat :
	//	«TODO»


//-------------------------------------------- Constructeurs - destructeur
	EmptyContent ( const EmptyContent & unEmptyContent );
	// Mode d'emploi (constructeur de copie) :
	//	«Mode emploi»
	// Contrat :
	//	«TODO»

	EmptyContent ( );
	// Mode d'emploi (constructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

	virtual ~EmptyContent ( );
	// Mode d'emploi (destructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

protected:

};

} // namespace dtd

#endif // EMPTYCONTENT_HH

