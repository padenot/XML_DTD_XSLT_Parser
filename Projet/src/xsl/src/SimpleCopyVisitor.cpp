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
	_parent = parent;
	referenceNode.accept(*this);
	return _copiedNode;
}

//------------------------------------------------- Surcharge d'op�rateurs


//-------------------------------------------- Constructeurs - destructeur
SimpleCopyVisitor::SimpleCopyVisitor()
{
	//TODO
}

SimpleCopyVisitor::~SimpleCopyVisitor()
{
	//TODO
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es
void SimpleCopyVisitor::visit(const TextNode& node)
{
	_copiedNode = new TextNode(_parent, node.content());
}

void SimpleCopyVisitor::visit(const MarkupNode& node)
{
	MarkupNode::Attributes list(node.MarkupNode::begin(),
			node.MarkupNode::end());

	_copiedNode = new MarkupNode(_parent, node.ns(), node.name(), list);
}

void SimpleCopyVisitor::visit(const CompositeMarkupNode& node)
{
	CompositeMarkupNode::Children childrenNodes;
	CompositeMarkupNode ** tempParent = _parent;
	_parent = new CompositeMarkupNode*;

	for (CompositeMarkupNode::ChildrenIterator itNoeud = node.begin(); itNoeud
			!= node.end(); ++itNoeud)
	{
		(*itNoeud)->accept(*this);//stocke dans copiedNode la copie du fils
		childrenNodes.push_back(_copiedNode);
	}
	MarkupNode::Attributes list(node.MarkupNode::begin(),
			node.MarkupNode::end());

	_copiedNode = new CompositeMarkupNode(tempParent, node.ns(), node.name(),
			list, *_parent, childrenNodes);
	_parent = tempParent;
}

} // namespace xsl
