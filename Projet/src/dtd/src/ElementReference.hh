/*************************************************************************
 * ElementReference  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <ElementReference> (fichier ElementReference.hh) ------
#if ! defined ( ELEMENTREFERENCE_HH_ )
#define ELEMENTREFERENCE_HH_

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "ElementContent.hh"
#include "InterfaceElement.hpp"
#include "BadReferenceException.hpp"

namespace dtd
{
class DTD;
class Element;

class ElementReference: public ElementContent, public InterfaceElement
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

	virtual bool matches(xml::Node& node);

	virtual std::string ns() const;

	virtual std::string name() const;

	virtual const AttributesList& attributesList() const
			throw (BadReferenceException);
	// Mode d'emploi :
	//	Renvoie les attributes de l'élément référencé. Une exception est lancée en cas
	//	d'erreur (si l'élément référencé ne peut être retrouvé).
	// Contrat :
	//	Aucun.

	virtual const Content& content() const;

	virtual void accept(InterfaceDTDVisitor & visitor) const;

	Element& referenced() throw (BadReferenceException);
	const Element& referenced() const throw (BadReferenceException);
	// Mode d'emploi :
	//	Renvoie l'élément référencé. Une exception est lancée en cas
	//	d'erreur (si l'élément référencé ne peut être retrouvé).
	// Contrat :
	//	Aucun.

	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	ElementReference(DTD& dtd, std::string ns, std::string name);
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

	virtual ~ElementReference();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

protected:
	DTD& _dtd;
	std::string _namespace;
	std::string _name;

	bool _matchResult;
	// Variable temporaire utilisée pour transmettre un retour booléen
	//	lors d'un appel à visit()

	virtual bool _startValidation(
			xml::CompositeMarkupNode::ChildrenIterator firstToken,
			xml::CompositeMarkupNode::ChildrenIterator endToken,
			BrowsableContent* nextStep);

	virtual void visit(const xml::TextNode& node);
	virtual void visit(const xml::MarkupNode& node);
	virtual void visit(const xml::CompositeMarkupNode& node);

};

} // namespace dtd

#endif // ELEMENTREFERENCE_HH_
