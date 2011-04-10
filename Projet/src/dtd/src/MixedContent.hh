/*************************************************************************
 * MixedContent  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <MixedContent> (fichier MixedContent.hh) ------
#if ! defined ( MIXEDCONTENT_HH_ )
#define MIXEDCONTENT_HH_

//--------------------------------------------------- Interfaces utilisées
#include <set>
#include <stack>
#include "QuantifiableContent.hh"
#include "Choice.hh"

namespace dtd
{
class TextContent;

class MixedContent: public QuantifiableContent
{
	//----------------------------------------------------------------- PUBLIC

public:
	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types
	typedef Choice::ChoosableSet ChoosableSet;

	//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//	
	// Contrat :
	//	

	virtual bool validate(const xml::CompositeMarkupNode & node);

	virtual void accept(InterfaceDTDVisitor & visitor) const;

	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	MixedContent(TextContent & textContent, const ChoosableSet & choosable);
	// Mode d'emploi :
	//	TODO
	//	La destruction des "Content" passés en paramètres ("textContent" et
	//	les éléments pointés par le contenu de "choosable") sera assurée
	//	par l'objet construit.
	// Contrat :
	//	Aucun des pointeurs fournis ne doit être nul.
	//	TODO

	virtual ~MixedContent();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

	//------------------------------------------------------------------ PRIVE

protected:
	Choice _choice;
	TextContent& _textContent;

	typedef std::stack<_State> _StatesStack;
	_StatesStack _stack;

	virtual bool _startValidation(
			xml::CompositeMarkupNode::ChildrenIterator firstToken,
			xml::CompositeMarkupNode::ChildrenIterator endToken,
			BrowseableContent* nextStep);
	virtual bool _continueValidation(
			xml::CompositeMarkupNode::ChildrenIterator currentToken);

	virtual void _beforeValidation(
			xml::CompositeMarkupNode::ChildrenIterator firstToken,
			xml::CompositeMarkupNode::ChildrenIterator endToken,
			BrowseableContent* nextStep);
	virtual void _afterValidation();

};

} // namespace dtd

#endif // MIXEDCONTENT_HH_
