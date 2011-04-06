/*************************************************************************
 * RepeatedContent  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <RepeatedContent> (fichier RepeatedContent.hh) ------
#if ! defined ( REPEATEDCONTENT_HH_ )
#define REPEATEDCONTENT_HH_

//--------------------------------------------------- Interfaces utilisées
#include "QuantifiedContent.hh"

namespace dtd
{

class RepeatedContent: public QuantifiedContent
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
	RepeatedContent(NonEmptyContent & content);
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

	virtual ~RepeatedContent();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

protected:

};

} // namespace dtd

#endif // REPEATEDCONTENT_HH_
