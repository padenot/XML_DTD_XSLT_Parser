/*************************************************************************
 * QuantifiedContent  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <QuantifiedContent> (fichier QuantifiedContent.hh) ------
#if ! defined ( QUANTIFIEDCONTENT_HH_ )
#define QUANTIFIEDCONTENT_HH_

//--------------------------------------------------- Interfaces utilisées
#include <stack>
#include "ElementContent.hh"

namespace dtd
{

class QuantifiedContent: public ElementContent
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

	virtual bool validate(const xml::CompositeMarkupNode & node);

	QuantifiableContent & content();
	const QuantifiableContent & content() const;
	// Mode d'emploi :
	//	Renvoie le contenu quantifié par le QuantifiedContent.
	// Contrat :
	//	Aucun.

	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	QuantifiedContent(QuantifiableContent & content);
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

	virtual ~QuantifiedContent();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

protected:
	QuantifiableContent & _content;

	struct _State: public QuantifiableContent::_State
	{
		// TODO
	};
	typedef std::stack<_State> _StatesStack;
	_StatesStack _stack;

	virtual void _beforeValidation(
			xml::CompositeMarkupNode::ChildrenIterator firstToken,
			xml::CompositeMarkupNode::ChildrenIterator endToken,
			_InterfaceValidator* nextStep);
	virtual void _afterValidation();

};

} // namespace dtd

#endif // QUANTIFIEDCONTENT_HH_
