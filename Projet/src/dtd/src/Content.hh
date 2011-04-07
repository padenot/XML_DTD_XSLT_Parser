/*************************************************************************
 * Content  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <Content> (fichier Content.hh) ------
#if ! defined ( CONTENT_HH_ )
#define CONTENT_HH_

//--------------------------------------------------- Interfaces utilisées
#include "Node.hh"
#include "TextNode.hh"
#include "CompositeMarkupNode.hh"

namespace dtd
{
class InterfaceDTDVisitor;

class Content
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

	virtual bool validate(const xml::MarkupNode & node) = 0;
	// Mode d'emploi :
	//	Renvoie vrai si le contenu est de type EMPTY ou ANY.
	//	Renvoie faux sinon.
	//	Méthode destinée à être utilisée par la classe Element.
	// Contrat :
	//	Aucun.

	virtual bool validate(const xml::CompositeMarkupNode & node) = 0;
	// Mode d'emploi :
	//	Renvoie vrai si le noeud passé en paramètre respecte la strucure
	//	imposée par ce contenu.
	//	Renvoie faux sinon (en particulier si le contenu est de type EMPTY).
	//	Méthode destinée à être utilisée par la classe Element.
	//	Cette méthode ne valide pas récursivement la structure des enfants.
	// Contrat :
	//	Aucun.

	virtual void accept(InterfaceDTDVisitor & visitor) const = 0;
	// Mode d'emploi :
	//	Permet à un visiteur d'inspecter ce contenu sous sa vraie identité
	//	(en lui révélant son type réel).
	// Contrat :
	//	Aucun.


	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	Content();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

	virtual ~Content();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

protected:

};

} // namespace dtd

#endif // CONTENT_HH_
