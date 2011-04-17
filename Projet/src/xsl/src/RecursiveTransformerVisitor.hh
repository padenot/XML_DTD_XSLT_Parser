/*************************************************************************
 * RecursiveTransformerVisitor  -  «Description»
 * -------------------
 * Début      : 17 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <RecursiveTransformerVisitor> (fichier RecursiveTransformerVisitor.hh) ------
#if ! defined ( RECURSIVETRANSFORMERVISITOR_HH_ )
#define RECURSIVETRANSFORMERVISITOR_HH_

//--------------------------------------------------- Interfaces utilisées
#include "InterfaceNodeVisitor.hpp"
#include "CompositeMarkupNode.hh"

namespace xsl
{
class TransformerVisitor;

class RecursiveTransformerVisitor: public xml::InterfaceNodeVisitor
{
public:
	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types

	//----------------------------------------------------- Méthodes publiques
	xml::CompositeMarkupNode::Children * transform(
			xml::CompositeMarkupNode ** proxy, const xml::Node & reference);

	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	RecursiveTransformerVisitor(TransformerVisitor& transformer);

	virtual ~RecursiveTransformerVisitor();

protected:
	TransformerVisitor & _transformer;
	xml::CompositeMarkupNode ** _proxy;
	xml::CompositeMarkupNode::Children * _result;

	virtual void visit(const xml::TextNode& node);
	virtual void visit(const xml::MarkupNode& node);
	virtual void visit(const xml::CompositeMarkupNode& node);
};

} // namespace xsl

#endif // RECURSIVETRANSFORMERVISITOR_HH_
