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

	virtual bool validate(const xml::TextNode & node);
	// Mode d'emploi :
	//	Renvoie vrai si le contenu est de type texte.
	//	Renvoie faux sinon.
	// Contrat :
	//	Aucun.

	virtual bool validate(const xml::MarkupNode & node);
	// Mode d'emploi :
	//	Renvoie vrai si le contenu est de type vide.
	//	Renvoie faux sinon.
	// Contrat :
	//	Aucun.

	virtual bool validate(const xml::CompositeMarkupNode & node);
	// Mode d'emploi :
	//	Renvoie vrai si le noeud passé en paramètre respecte la strucure
	//	imposée par ce contenu, et si ses descendants
	// 	sont référencés dans la même DTD que cet élément et respectent
	//	également la structure imposée par les éléments correspondants de
	//	la même DTD (attributs et contenu).
	//	Renvoie faux sinon.
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
	struct _State
	{
		Content* nextStep;
		xml::CompositeMarkupNode::ChildrenIterator firstToken;
		xml::CompositeMarkupNode::ChildrenIterator currentToken;
		xml::CompositeMarkupNode::ChildrenIterator endToken;
	};

	bool _newValidation(xml::CompositeMarkupNode::ChildrenIterator firstToken,
			xml::CompositeMarkupNode::ChildrenIterator endToken,
			Content* nextStep);
	// Mode d'emploi :
	//	TODO.
	// Contrat :
	//	Aucun.

	virtual void _pushState(Content* nextStep) = 0;
	// Mode d'emploi :
	//	TODO.
	// Contrat :
	//	Aucun.

	virtual void _popState() = 0;
	// Mode d'emploi :
	//	TODO.
	// Contrat :
	//	Aucun.

	virtual bool _continueValidation(
			xml::CompositeMarkupNode::ChildrenIterator firstToken,
			xml::CompositeMarkupNode::ChildrenIterator endToken) const = 0;
	// Mode d'emploi :
	//	TODO.
	// Contrat :
	//	Aucun.
};

} // namespace dtd

#endif // CONTENT_HH_
