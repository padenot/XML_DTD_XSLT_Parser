/*************************************************************************
 * Choice  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <Choice> (fichier Choice.hh) ------
#if ! defined ( CHOICE_HH_ )
#define CHOICE_HH_

//--------------------------------------------------- Interfaces utilisées
#include <set>
#include <stack>
#include "ElementContent.hh"

namespace dtd
{

class Choice: public ElementContent
{
protected:
	typedef std::set<ElementContent*> _ChoosableSet;
public:
	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types
	typedef std::set<ElementContent*> ChoosableSet;
	typedef _ChoosableSet::const_iterator const_iterator;

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
	Choice(const ChoosableSet & elements);
	// Mode d'emploi :
	//	Construit un choix composé des alternatives présentes dans "elements".
	// Contrat :
	//	Aucun des pointeurs fournis ne doit être nul.

	virtual ~Choice();

protected:

	_ChoosableSet _choosable;

	struct _State: public QuantifiableContent::_State
	{
		_ChoosableSet::iterator nextChoosable;

		_State(xml::CompositeMarkupNode::ChildrenIterator aFirstToken,
				xml::CompositeMarkupNode::ChildrenIterator anEndToken,
				BrowsableContent* aNextStep,
				_ChoosableSet::iterator aNextChoosable) :
			QuantifiableContent::_State(aFirstToken, anEndToken, aNextStep),
					nextChoosable(aNextChoosable)
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

#endif // CHOICE_HH_
