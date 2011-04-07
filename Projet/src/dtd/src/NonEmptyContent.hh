/*************************************************************************
 * NonEmptyContent  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <NonEmptyContent> (fichier NonEmptyContent.hh) ------
#if ! defined ( NONEMPTYCONTENT_HH_ )
#define NONEMPTYCONTENT_HH_

//--------------------------------------------------- Interfaces utilisées
#include "Content.hh"
#include "_InterfaceValidator.hpp"

namespace dtd
{

class NonEmptyContent: public Content, protected _InterfaceValidator
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

	virtual bool validate(const xml::MarkupNode & node);
	virtual bool validate(const xml::CompositeMarkupNode & node);

	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	NonEmptyContent();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

	virtual ~NonEmptyContent();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

protected:
	struct _State
	{
		xml::CompositeMarkupNode::ChildrenIterator firstToken;
		xml::CompositeMarkupNode::ChildrenIterator endToken;
		NonEmptyContent* nextStep;

		_State(xml::CompositeMarkupNode::ChildrenIterator aFirstToken,
				xml::CompositeMarkupNode::ChildrenIterator anEndToken,
				NonEmptyContent* aNextStep) :
			firstToken(aFirstToken), endToken(anEndToken), nextStep(aNextStep)
		{

		}
	};

	bool _newValidation(xml::CompositeMarkupNode::ChildrenIterator firstToken,
			xml::CompositeMarkupNode::ChildrenIterator endToken,
			NonEmptyContent* nextStep);
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

	virtual void _pushState(
			xml::CompositeMarkupNode::ChildrenIterator firstToken,
			xml::CompositeMarkupNode::ChildrenIterator endToken,
			NonEmptyContent* nextStep);
	// Mode d'emploi :
	//	TODO.
	// Contrat :
	//	Aucun.

	virtual void _popState();
	// Mode d'emploi :
	//	TODO.
	// Contrat :
	//	Aucun.

	class _ValidatorAccessor: public _InterfaceValidator
	// Permet aux sous-classes de NonEmptyElement d'accéder à l'interface
	// _InterfaceValidator sur d'autres instances qu'eux-mêmes.
	{
	public:
		_ValidatorAccessor(NonEmptyContent& referenced);
		virtual bool _newValidation(
				xml::CompositeMarkupNode::ChildrenIterator firstToken,
				xml::CompositeMarkupNode::ChildrenIterator endToken,
				NonEmptyContent* nextStep);
		// Mode d'emploi :
		//	Appelle referenced._newValidation(firstToken,endToken,nextStep)
		//	et renvoie le résultat.
		//	Astuce très moche nécessaire pour donner aux instances des
		//	classes filles le droit d'appeler des méthodes protégées de
		//	la classes de base sur d'autres instances.
		//	L'autre solution aurait été de donner à ces méthodes une
		//	visibilité publique...
		// Contrat :
		//	Ceux s'appliquant à NonEmptyContent::_newValidation.

		virtual bool _continueValidation(
				xml::CompositeMarkupNode::ChildrenIterator currentToken);
		// Mode d'emploi :
		//	Appelle referenced._contenueValidation(currentToken) et renvoie
		//	le résultat.
		//	Astuce très moche nécessaire pour donner aux instances des
		//	classes filles le droit d'appeler des méthodes protégées de
		//	la classes de base sur d'autres instances.
		//	L'autre solution aurait été de donner à ces méthodes une
		//	visibilité publique...
		// Contrat :
		//	Ceux s'appliquant à NonEmptyContent::_continueValidation.

	protected:
		NonEmptyContent& _referenced;
	};

	friend class _ValidatorAccessor;
};

} // namespace dtd

#endif // NONEMPTYCONTENT_HH_
