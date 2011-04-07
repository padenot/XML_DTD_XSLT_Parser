/*************************************************************************
 * AnyContent  -  «Description»
 * -------------------
 * Début      : 6 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <AnyContent> (fichier AnyContent.hh) ------
#if ! defined ( ANYCONTENT_HH_ )
#define ANYCONTENT_HH_

//--------------------------------------------------- Interfaces utilisées
#include "Content.hh"

namespace dtd
{

class AnyContent: public Content
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
	AnyContent();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

	virtual ~AnyContent();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

protected:

};

} // namespace dtd

#endif // ANYCONTENT_HH_
