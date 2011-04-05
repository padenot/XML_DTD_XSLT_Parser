/*************************************************************************
 * Sequence  -  «Description»
 * -------------------
 * Début      : lun. 04 avril 2011 10:17:46 CEST
 * Auteur(s)  : H4215
 *************************************************************************/

//---- Interface de la classe <Sequence> (fichier Sequence.hh) ----
#ifndef SEQUENCE_HH
#define SEQUENCE_HH

//--------------------------------------------------- Interfaces utilisées
#include "ElementContent.hh"

//------------------------------------------------------------------------
// Rôle de la classe <Sequence>
//	«Rôle»
//
//------------------------------------------------------------------------

namespace dtd
{

class Sequence: public ElementContent
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
	Sequence();
	// Mode d'emploi (constructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

	virtual ~Sequence();
	// Mode d'emploi (destructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

protected:

};

} // namespace dtd

#endif // SEQUENCE_HH
