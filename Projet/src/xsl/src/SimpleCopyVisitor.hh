/*************************************************************************
 * SimpleCopyVisitor  -  Description
 * -------------------
 * D�but      : 17 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <SimpleCopyVisitor> (fichier SimpleCopyVisitor.hh) ------
#if ! defined ( SIMPLECOPYVISITOR_HH_ )
#define SIMPLECOPYVISITOR_HH_

//--------------------------------------------------- Interfaces utilis�es
#include "InterfaceNodeVisitor.hpp"
#include "Node.hh"
#include "TextNode.hh"
#include "MarkupNode.hh"
#include "CompositeMarkupNode.hh"
#include "RecursiveTransformerVisitor.hh"

namespace xsl
{

class SimpleCopyVisitor: public xml::InterfaceNodeVisitor
{
public:
	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types

	//----------------------------------------------------- M�thodes publiques
	// type M�thode ( liste des param�tres );
	// Mode d'emploi :
	//	
	// Contrat :
	//	
	xml::Node * copy(xml::CompositeMarkupNode ** parent,
			const xml::Node& referenceNode);

	//------------------------------------------------- Surcharge d'op�rateurs


	//-------------------------------------------- Constructeurs - destructeur
	explicit SimpleCopyVisitor(TransformerVisitor & transformer);
	explicit SimpleCopyVisitor(RecursiveTransformerVisitor & transformer);

	virtual ~SimpleCopyVisitor();

protected:
	RecursiveTransformerVisitor _transformer;
	xml::Node * _copiedNode;
	xml::CompositeMarkupNode ** _parentProxy;

	virtual void visit(const xml::TextNode & node);
	virtual void visit(const xml::MarkupNode & node);
	virtual void visit(const xml::CompositeMarkupNode & node);
};

} // namespace xsl

#endif // SIMPLECOPYVISITOR_HH_
