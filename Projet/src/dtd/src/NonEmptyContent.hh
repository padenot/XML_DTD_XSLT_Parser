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

namespace dtd
{

class NonEmptyContent: public Content
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
	//	TODO.
	// Contrat :
	//	Aucun.

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

	virtual bool _continueValidation(
			xml::CompositeMarkupNode::ChildrenIterator currentToken) = 0;
	// Mode d'emploi :
	//	TODO.
	// Contrat :
	//	Aucun.

	static bool _CALL_newValidation(NonEmptyContent & target,
			xml::CompositeMarkupNode::ChildrenIterator firstToken,
			xml::CompositeMarkupNode::ChildrenIterator endToken,
			NonEmptyContent* nextStep);
	// Mode d'emploi :
	//	Appelle target._newValidation(firstToken,endToken,nextStep)
	//	et renvoie le résultat.
	//	Astuce très moche nécessaire pour donner aux instances des
	//	classes filles le droit d'appeler des méthodes protégées de
	//	la classes de base sur d'autres instances.
	//	L'autre solution aurait été de donner à ces méthodes une
	//	visibilité publique...
	// Contrat :
	//	Ceux s'appliquant à _newValidation (non static).

	static bool _CALL_continueValidation(NonEmptyContent & target,
			xml::CompositeMarkupNode::ChildrenIterator currentToken);
	// Mode d'emploi :
	//	Appelle target._contenueValidation(currentToken) et renvoie
	//	le résultat.
	//	Astuce très moche nécessaire pour donner aux instances des
	//	classes filles le droit d'appeler des méthodes protégées de
	//	la classes de base sur d'autres instances.
	//	L'autre solution aurait été de donner à ces méthodes une
	//	visibilité publique...
	// Contrat :
	//	Ceux s'appliquant à _continueValidation (non static).
};

} // namespace dtd

#endif // NONEMPTYCONTENT_HH_
