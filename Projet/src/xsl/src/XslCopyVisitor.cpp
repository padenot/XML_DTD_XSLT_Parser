/*************************************************************************
 * XslCopyVisitor  -  Visiteur copiant un noeud XML en prennant en compte
 *                     les templates à appliquer.
 * -------------------
 * Début      : 17 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//-- Réalisation de la classe <XslCopyVisitor> (fichier XslCopyVisitor.cpp)

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iterator>
#include <algorithm>

//------------------------------------------------------ Include personnel
#include "XslCopyVisitor.hh"
#include "RecursiveTransformerVisitor.hh"
#include "SimpleCopyVisitor.hh"
#include "TextNode.hh"
#include "MarkupNode.hh"
#include "CompositeMarkupNode.hh"
using namespace xml;

namespace xsl
{
//------------------------------------------------------------- Constantes
const std::string XslCopyVisitor::NAMESPACE_APPLY_TEMPLATES("xsl");
const std::string XslCopyVisitor::NAME_APPLY_TEMPLATES("apply-templates");

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
CompositeMarkupNode::Children* XslCopyVisitor::xslCopy(
		CompositeMarkupNode ** parentProxy, const Node& templateNode,
		const Node& referenceNode)
{
	CompositeMarkupNode::Children * result = 0;

	_parentProxy = parentProxy;
	_referenceNode = &referenceNode;
	templateNode.accept(*this);
	result = new CompositeMarkupNode::Children(_result);
	_result.clear();

	return result;
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
XslCopyVisitor::XslCopyVisitor(RecursiveTransformerVisitor & transformer) :
	_transformer(transformer)
{
	//TODO
}

XslCopyVisitor::~XslCopyVisitor()
{
	//TODO
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void XslCopyVisitor::visit(const TextNode& node)
{
	SimpleCopyVisitor copier;
	_result.push_back(copier.copy(_parentProxy, node));
}

void XslCopyVisitor::visit(const MarkupNode& node)
{
	if (node.ns() == NAMESPACE_APPLY_TEMPLATES && node.name()
			== NAME_APPLY_TEMPLATES)
	{
		CompositeMarkupNode::Children * children = _transformer.transform(
				_parentProxy, *_referenceNode);
		if (children != 0)
		{
			copy(_result.begin(), _result.end(), back_inserter(*children));
		}
	}
	else
	{
		SimpleCopyVisitor copier;
		_result.push_back(copier.copy(_parentProxy, node));
	}
}

void XslCopyVisitor::visit(const CompositeMarkupNode& node)
{
	MarkupNode::Attributes copiedAttributes(node.MarkupNode::begin(),
			node.MarkupNode::end());
	CompositeMarkupNode::Children children;
	CompositeMarkupNode ** myParent = _parentProxy;

	_parentProxy = new CompositeMarkupNode*;

	for (CompositeMarkupNode::ChildrenIterator it = node.begin(); it
			!= node.end(); ++it)
	{
		(*it)->accept(*this);
		copy(_result.begin(), _result.end(), back_inserter(children));
	}

	_result.assign(1, new CompositeMarkupNode(myParent, node.ns(), node.name(),
			copiedAttributes, *_parentProxy, children));

	_parentProxy = myParent;
}

} // namespace xsl
