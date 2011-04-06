/*************************************************************************
 * TextContent  -  «Description»
 * -------------------
 * Début      : 6 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <TextContent> (fichier TextContent.hh) ------
#if ! defined ( TEXTCONTENT_HH_ )
#define TEXTCONTENT_HH_

//--------------------------------------------------- Interfaces utilisées
#include "Content.hh"

namespace dtd
{

class TextContent: public Content
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

	virtual bool validate(const xml::TextNode & node);

	virtual void accept(InterfaceDTDVisitor & visitor) const;

	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	TextContent();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

	virtual ~TextContent();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

protected:
};

} // namespace dtd

#endif // TEXTCONTENT_HH_
