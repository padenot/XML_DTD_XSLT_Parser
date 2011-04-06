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
#include "NonEmptyContent.hh"

namespace dtd
{
class ElementReference;

class MixedContent: public NonEmptyContent
{
	//----------------------------------------------------------------- PUBLIC

public:
	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types
	typedef std::set<ElementReference*> ChoiceElements;

	//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//	
	// Contrat :
	//	

	virtual void accept(InterfaceDTDVisitor & visitor) const;

	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	MixedContent(const ChoiceElements & elements);
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

	virtual ~MixedContent();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

	//------------------------------------------------------------------ PRIVE

protected:
	typedef std::set<ElementReference*> _ChoiceElements;
	_ChoiceElements _elements;

	struct _State: public Content::_State
	{
		// TODO
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

#endif // MIXEDCONTENT_HH_
