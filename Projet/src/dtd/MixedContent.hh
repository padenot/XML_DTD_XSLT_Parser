/*************************************************************************
 * MixedContent  -  «Description»
 * -------------------
 * Début      : lun. 04 avril 2011 10:15:38 CEST
 * Auteur(s)  : H4215
*************************************************************************/

//---- Interface de la classe <MixedContent> (fichier MixedContent.hh) ----
#ifndef MIXEDCONTENT_HH
#define MIXEDCONTENT_HH

//--------------------------------------------------- Interfaces utilisées
#include "QuantifiableContent.hh"

//------------------------------------------------------------------------
// Rôle de la classe <MixedContent>
//	«Rôle»
//
//------------------------------------------------------------------------

namespace dtd
{

class MixedContent : public QuantifiableContent
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
	MixedContent ( );
	// Mode d'emploi (constructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

	virtual ~MixedContent ( );
	// Mode d'emploi (destructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

protected:

};

} // namespace dtd

#endif // MIXEDCONTENT_HH

