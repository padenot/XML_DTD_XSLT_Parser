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
#include "InterfaceNodeVisitor.hpp"

namespace dtd
{
class DTD;
class Element;

class ElementReference: public ElementContent, public xml::InterfaceNodeVisitor
{
public:
	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types

	//----------------------------------------------------- Méthodes publiques
	virtual void accept(InterfaceDTDVisitor & visitor) const;

	virtual bool matches(xml::Node& node);

	virtual std::string ns() const;

	virtual std::string name() const;

	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	ElementReference(DTD& dtd, std::string ns, std::string name);
	// Mode d'emploi :
	//	Construit une référence vers un élément dans l'espace de nom "ns"
	//	ayant pour nom "name".
	//	La dtd permet de retrouver l'élément référencé (pour des ajouts futurs
	//	dans l'implémentation).
	// Contrat :
	//	Aucun.

	virtual ~ElementReference();

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
