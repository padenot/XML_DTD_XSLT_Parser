/*************************************************************************
 * OptionalContent  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <OptionalContent> (fichier OptionalContent.hh) ------
#if ! defined ( OPTIONALCONTENT_HH_ )
#define OPTIONALCONTENT_HH_

//--------------------------------------------------- Interfaces utilisées
#include "QuantifiedContent.hh"

namespace dtd
{

class OptionalContent: public QuantifiedContent
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
	OptionalContent(QuantifiableContent & content);
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

	virtual ~OptionalContent();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

protected:

	virtual bool _continueValidation(
			xml::CompositeMarkupNode::ChildrenIterator currentToken);

};

} // namespace dtd

#endif // OPTIONALCONTENT_HH_
