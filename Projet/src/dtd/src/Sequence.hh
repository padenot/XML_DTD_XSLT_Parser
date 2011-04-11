/*************************************************************************
 * Sequence  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <Sequence> (fichier Sequence.hh) ------
#if ! defined ( SEQUENCE_HH_ )
#define SEQUENCE_HH_

//--------------------------------------------------- Interfaces utilisées
#include <list>
#include <stack>
#include "ElementContent.hh"

namespace dtd
{

class Sequence: public ElementContent
{
protected:
	typedef std::list<ElementContent*> _OrderedContent;
public:
	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types
	typedef std::list<ElementContent*> OrderedContent;
	typedef _OrderedContent::const_iterator OrderedContentIterator;
	//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//	
	// Contrat :
	//	

	virtual bool validate(const xml::CompositeMarkupNode & node);

	virtual void accept(InterfaceDTDVisitor & visitor) const;
	
	OrderedContentIterator begin() const;
	// Mode d'emploi :
	//	Renvoie un itérateur vers le premier enfant de la sequence.
	//	La méthode est compatible avec la STL.
	//	L'itérateur pointe vers un pointeur (l'accès aux méthodes des fils
	//	se fait donc de la façon suivante : (*it)->foo()).
	// Contrat :
	//	L'itérateur n'est plus valable en cas de modification de la sequence, de
	//	même que les itérateurs obtenus par son intermédiaire.
	
	OrderedContentIterator end() const;
	// Mode d'emploi :
	//	Renvoie un itérateur pointant juste après le dernier enfant de la se-
	//  quence.
	//	La méthode est compatible avec la STL.
	//	L'itérateur pointe vers un pointeur (l'accès aux méthodes des fils
	//	se fait donc de la façon suivante : (*it)->foo()).
	// Contrat :
	//	L'itérateur n'est plus valable en cas de modification de la sequence, de
	//	même que les itérateurs obtenus par son intermédiaire.


	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	Sequence(const OrderedContent & embeddedContent);
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	Aucun des pointeurs fournis ne doit être nul.
	//	TODO

	virtual ~Sequence();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

protected:
	_OrderedContent _embeddedContent;

	struct _State: public QuantifiableContent::_State
	{
		_OrderedContent::iterator nextEmbeddedContent;

		_State(xml::CompositeMarkupNode::ChildrenIterator aFirstToken,
				xml::CompositeMarkupNode::ChildrenIterator anEndToken,
				BrowsableContent* aNextStep,
				_OrderedContent::iterator aNextEmbeddedContent) :
			QuantifiableContent::_State(aFirstToken, anEndToken, aNextStep),
					nextEmbeddedContent(aNextEmbeddedContent)
		{

		}
	};
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

#endif // SEQUENCE_HH_
