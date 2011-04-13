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
	typedef ChoosableSet::const_iterator const_iterator;

	//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//	
	// Contrat :
	//	

	virtual bool validate(const xml::CompositeMarkupNode & node);

	virtual void accept(InterfaceDTDVisitor & visitor) const;
	const_iterator begin() const;
		// Mode d'emploi :
	//	Renvoie un itérateur vers le premier enfant du contenu.
	//	La méthode est compatible avec la STL.
	//	L'itérateur pointe vers un pointeur (l'accès aux méthodes des fils
	//	se fait donc de la façon suivante : (*it)->foo()).
	// Contrat :
	//	L'itérateur n'est plus valable en cas de modification du contenu, de
	//	même que les itérateurs obtenus par son intermédiaire.
	
	const_iterator end() const;
	// Mode d'emploi :
	//	Renvoie un itérateur pointant juste après le dernier enfant du contenu.
	//	La méthode est compatible avec la STL.
	//	L'itérateur pointe vers un pointeur (l'accès aux méthodes des fils
	//	se fait donc de la façon suivante : (*it)->foo()).
	// Contrat :
	//	L'itérateur n'est plus valable en cas de modification du noeud, de
	//	même que les itérateurs obtenus par son intermédiaire.

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
			BrowsableContent* nextStep);
	virtual bool _continueValidation(
			xml::CompositeMarkupNode::ChildrenIterator currentToken);

	virtual void _beforeValidation(
			xml::CompositeMarkupNode::ChildrenIterator firstToken,
			xml::CompositeMarkupNode::ChildrenIterator endToken,
			BrowsableContent* nextStep);
	virtual void _afterValidation();

};

} // namespace dtd

#endif // MIXEDCONTENT_HH_
