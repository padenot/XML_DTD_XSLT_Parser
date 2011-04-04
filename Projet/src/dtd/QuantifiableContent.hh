/*************************************************************************
 * QuantifiableContent  -  «Description»
 * -------------------
 * Début      : lun. 04 avril 2011 10:14:51 CEST
 * Auteur(s)  : H4215
*************************************************************************/

//---- Interface de la classe <QuantifiableContent> (fichier QuantifiableContent.hh) ----
#ifndef QUANTIFIABLECONTENT_HH
#define QUANTIFIABLECONTENT_HH

//--------------------------------------------------- Interfaces utilisées
#include "Content.hh"

//------------------------------------------------------------------------
// Rôle de la classe <QuantifiableContent>
//	«Rôle»
//
//------------------------------------------------------------------------

namespace dtd
{

class QuantifiableContent : public Content
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
	QuantifiableContent ( );
	// Mode d'emploi (constructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

	virtual ~QuantifiableContent ( );
	// Mode d'emploi (destructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

protected:

};

} // namespace dtd

#endif // QUANTIFIABLECONTENT_HH

