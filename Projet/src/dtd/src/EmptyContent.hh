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
class EmptyContent: public Content
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

	virtual bool validate(const xml::MarkupNode & node);
	virtual bool validate(const xml::CompositeMarkupNode & node);

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

protected:

};

} // namespace dtd

#endif // EMPTYCONTENT_HH_
