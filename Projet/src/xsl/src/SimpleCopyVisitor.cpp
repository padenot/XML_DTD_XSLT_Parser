/*************************************************************************
 * SimpleCopyVisitor  -  Description
 * -------------------
 * D�but      : 17 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- R�alisation de la classe <SimpleCopyVisitor> (fichier SimpleCopyVisitor.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#ifdef XSL_TRANSFORM_TRACE
#include <iostream>
#endif
#include <cassert>

//------------------------------------------------------ Include personnel
#include "SimpleCopyVisitor.hh"
using namespace xml;

namespace xsl
{
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type SimpleCopyVisitor::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//}
Node * SimpleCopyVisitor::copy(CompositeMarkupNode ** parent,
		const Node& referenceNode)
{
	_parentProxy = parent;
	referenceNode.accept(*this);
	return _copiedNode;
}

//------------------------------------------------- Surcharge d'op�rateurs


//-------------------------------------------- Constructeurs - destructeur
SimpleCopyVisitor::SimpleCopyVisitor(TransformerVisitor & transformer) :
	_transformer(transformer), _copiedNode(0), _parentProxy(0)
{
	// Rien à faire
}

SimpleCopyVisitor::SimpleCopyVisitor(RecursiveTransformerVisitor & transformer) :
	_transformer(transformer), _copiedNode(0), _parentProxy(0)
{
	// Rien à faire
}

SimpleCopyVisitor::~SimpleCopyVisitor()
{
	// Rien à faire
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es
void SimpleCopyVisitor::visit(const TextNode& node)
{
#ifdef XSL_TRANSFORM_TRACE
	clog << "SimpleCopy on TextNode:" << node.content() << endl;
#endif
	_copiedNode = new TextNode(_parentProxy, node.content());
}

void SimpleCopyVisitor::visit(const MarkupNode& node)
{
#ifdef XSL_TRANSFORM_TRACE
	clog << "SimpleCopy on MarkupNode" << endl;
#endif
	MarkupNode::Attributes list(node.MarkupNode::begin(),
			node.MarkupNode::end());

	_copiedNode = new MarkupNode(_parentProxy, node.ns(), node.name(), list);
}

void SimpleCopyVisitor::visit(const CompositeMarkupNode& node)
{
#ifdef XSL_TRANSFORM_TRACE
	clog << "SimpleCopy on CompositeMarkupNode" << endl;
#endif
	MarkupNode::Attributes list(node.MarkupNode::begin(),
			node.MarkupNode::end());
	CompositeMarkupNode::Children * newChildren = 0;
	CompositeMarkupNode ** myParent = _parentProxy;
	_parentProxy = new CompositeMarkupNode*;

	// Applique les templates sur les noeuds fils
	newChildren = _transformer.transform(_parentProxy, node);
	assert(newChildren != 0); // Ne devrait jamais arriver puisque "node" est composite

	_copiedNode = new CompositeMarkupNode(myParent, node.ns(), node.name(),
			list, *_parentProxy, *newChildren);
	delete newChildren;
	_parentProxy = myParent;
}

} // namespace xsl
