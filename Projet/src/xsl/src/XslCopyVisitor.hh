/*************************************************************************
 * XslCopyVisitor  -  Visiteur copiant un noeud XML en prennant en compte
 *                     les templates à appliquer.
 * -------------------
 * Début      : 17 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <XslCopyVisitor> (fichier XslCopyVisitor.hh) ------
#if ! defined ( XSLCOPYVISITOR_HH_ )
#define XSLCOPYVISITOR_HH_

//--------------------------------------------------- Interfaces utilisées
#include "InterfaceNodeVisitor.hpp"
#include "CompositeMarkupNode.hh"

namespace xsl
{
class RecursiveTransformerVisitor;

class XslCopyVisitor: public xml::InterfaceNodeVisitor
{
public:
	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types

	//----------------------------------------------------- Méthodes publiques
	xml::CompositeMarkupNode::Children * xslCopy(
			xml::CompositeMarkupNode ** parentProxy,
			const xml::Node& templateNode, const xml::Node& referenceNode);

	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	XslCopyVisitor(RecursiveTransformerVisitor & transformer);

	virtual ~XslCopyVisitor();

protected:
	RecursiveTransformerVisitor & _transformer;
	const xml::Node * _referenceNode;
	xml::CompositeMarkupNode ** _parentProxy;
	xml::CompositeMarkupNode::Children _result;

	virtual void visit(const xml::TextNode& node);
	virtual void visit(const xml::MarkupNode& node);
	virtual void visit(const xml::CompositeMarkupNode& node);

	static const std::string NAMESPACE_APPLY_TEMPLATES;
	static const std::string NAME_APPLY_TEMPLATES;
};

} // namespace xsl

#endif // XSLCOPYVISITOR_HH_
