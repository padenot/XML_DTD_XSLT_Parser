/*************************************************************************
 * Choice  -  «Description»
 * -------------------
 * Début      : lun. 04 avril 2011 10:16:52 CEST
 * Auteur(s)  : H4215
*************************************************************************/

//---- Interface de la classe <Choice> (fichier Choice.hh) ----
#ifndef CHOICE_HH
#define CHOICE_HH

//--------------------------------------------------- Interfaces utilisées
#include "ElementContent.hh"

//------------------------------------------------------------------------
// Rôle de la classe <Choice>
//	«Rôle»
//
//------------------------------------------------------------------------

namespace dtd
{

class Choice : public ElementContent
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


//-------------------------------------------- Constructeurs - destructeur
	Choice ( );
	// Mode d'emploi (constructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

	virtual ~Choice ( );
	// Mode d'emploi (destructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

protected:

};

} // namespace dtd

#endif // CHOICE_HH

