/*************************************************************************
 * EmptyContent  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <EmptyContent> (fichier EmptyContent.hh) ------
#if ! defined ( EMPTYCONTENT_HH_ )
#define EMPTYCONTENT_HH_

//--------------------------------------------------- Interfaces utilisées
#include "Content.hh"

namespace dtd
{
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 


class EmptyContent: public Content
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//	
	// Contrat :
	//	

	virtual bool validate(const xml::MarkupNode & node);

	virtual void accept(InterfaceDTDVisitor & visitor) const;

	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	EmptyContent();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

	virtual ~EmptyContent();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés

};

} // namespace dtd

#endif // EMPTYCONTENT_HH_
