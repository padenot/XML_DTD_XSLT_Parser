/*************************************************************************
 * RepeatableContent  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <RepeatableContent> (fichier RepeatableContent.hh) ------
#if ! defined ( REPEATABLECONTENT_HH_ )
#define REPEATABLECONTENT_HH_

//--------------------------------------------------- Interfaces utilisées
#include "QuantifiedContent.hh"

namespace dtd
{

class RepeatableContent: public QuantifiedContent
{

public:
	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types

	//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//	
	// Contrat :
	//	

	virtual void accept(InterfaceDTDVisitor & visitor) const;

	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	RepeatableContent(NonEmptyContent & content);
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

	virtual ~RepeatableContent();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

protected:

};

} // namespace dtd

#endif // REPEATABLECONTENT_HH_