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
#include "BrowsableContent.hh"
#include "InterfaceNodeVisitor.hpp"

namespace dtd
{

class TextContent: public BrowsableContent, public xml::InterfaceNodeVisitor
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

	bool _validationResult;
	// Variable temporaire utilisée pour transmettre un retour booléen
	//	lors d'un appel à visit()

	virtual bool _startValidation(
			xml::CompositeMarkupNode::ChildrenIterator firstToken,
			xml::CompositeMarkupNode::ChildrenIterator endToken,
			BrowsableContent* nextStep);

	virtual void visit(const xml::TextNode& node);
	virtual void visit(const xml::MarkupNode& node);
	virtual void visit(const xml::CompositeMarkupNode& node);
};

} // namespace dtd

#endif // TEXTCONTENT_HH_
