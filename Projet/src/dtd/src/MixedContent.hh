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

namespace dtd
{
class ElementReference;

class MixedContent: public QuantifiableContent
{
	//----------------------------------------------------------------- PUBLIC

public:
	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types
	typedef std::set<ElementReference*> ChoosableSet;

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
	MixedContent(const ChoosableSet & choosable);
	// Mode d'emploi :
	//	TODO
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
	typedef std::set<ElementReference*> _ChoosableSet;
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

#endif // MIXEDCONTENT_HH_
