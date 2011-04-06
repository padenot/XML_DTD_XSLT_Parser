/*************************************************************************
 * QuantifiedContent  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <QuantifiedContent> (fichier QuantifiedContent.hh) ------
#if ! defined ( QUANTIFIEDCONTENT_HH_ )
#define QUANTIFIEDCONTENT_HH_

//--------------------------------------------------- Interfaces utilisées
#include "ElementContent.hh"

namespace dtd
{

class QuantifiedContent: public ElementContent
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

	NonEmptyContent & content();
	const NonEmptyContent & content() const;
	// Mode d'emploi :
	//	Renvoie le contenu quantifié par le QuantifiedContent.
	// Contrat :
	//	Aucun.

	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	QuantifiedContent(NonEmptyContent & content);
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

	virtual ~QuantifiedContent();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

protected:
	NonEmptyContent & _content;

};

} // namespace dtd

#endif // QUANTIFIEDCONTENT_HH_
