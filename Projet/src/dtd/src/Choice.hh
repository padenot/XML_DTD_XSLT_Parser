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
	typedef std::set<ElementContent*> ChoiceElements;

	//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//	
	// Contrat :
	//	

	virtual void accept(InterfaceDTDVisitor & visitor) const;

	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	Choice(const ChoiceElements & elements);
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

	virtual ~Choice();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

protected:
	typedef std::set<ElementContent*> _ChoiceElements;
	_ChoiceElements _elements;

	struct _State: public Content::_State
	{
		//TODO
	};
	typedef std::stack<_State> _StatesStack;
	_StatesStack _stack;

	virtual void _pushState(Content* nextStep);
	virtual void _popState();
	virtual bool _continueValidation(
			xml::CompositeMarkupNode::ChildrenIterator firstToken,
			xml::CompositeMarkupNode::ChildrenIterator endToken) const;
};

} // namespace dtd

#endif // CHOICE_HH_
