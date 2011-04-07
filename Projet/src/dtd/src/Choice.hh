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
public:
	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types
	typedef std::set<ElementContent*> ChoosableSet;

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
	Choice(const ChoosableSet & elements);
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	Aucun des pointeurs fournis ne doit être nul.
	//	TODO

	virtual ~Choice();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

protected:
	typedef std::set<ElementContent*> _ChoosableSet;
	_ChoosableSet _choosable;

	struct _State: public NonEmptyContent::_State
	{
		_ChoosableSet::iterator nextChoosable;

		_State(xml::CompositeMarkupNode::ChildrenIterator aFirstToken,
				xml::CompositeMarkupNode::ChildrenIterator anEndToken,
				NonEmptyContent* aNextStep,
				_ChoosableSet::iterator aNextChoosable) :
			NonEmptyContent::_State(aFirstToken, anEndToken, aNextStep),
					nextChoosable(aNextChoosable)
		{

		}
	};
	typedef std::stack<_State> _StatesStack;
	_StatesStack _stack;

	virtual void _pushState(
			xml::CompositeMarkupNode::ChildrenIterator firstToken,
			xml::CompositeMarkupNode::ChildrenIterator endToken,
			NonEmptyContent* nextStep);
	virtual void _popState();
	virtual bool _continueValidation(
			xml::CompositeMarkupNode::ChildrenIterator currentToken);

};

} // namespace dtd

#endif // CHOICE_HH_
