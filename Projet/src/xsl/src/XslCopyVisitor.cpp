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
#ifdef XSL_TRANSFORM_TRACE
#include <iostream>
#endif

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
// TODO : remettre la bonne valeur
//const std::string XslCopyVisitor::NAMESPACE_APPLY_TEMPLATES("xsl");
const std::string XslCopyVisitor::NAMESPACE_APPLY_TEMPLATES;
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
XslCopyVisitor::XslCopyVisitor(TransformerVisitor & transformer) :
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
#ifdef XSL_TRANSFORM_TRACE
	clog << "XslCopy on TextNode" << endl;
#endif
	SimpleCopyVisitor copier;
	_result.push_back(copier.copy(_parentProxy, node));
}

void XslCopyVisitor::visit(const MarkupNode& node)
{
#ifdef XSL_TRANSFORM_TRACE
	clog << "XslCopy on MarkupNode" << endl;
#endif
	if (node.ns() == NAMESPACE_APPLY_TEMPLATES && node.name()
			== NAME_APPLY_TEMPLATES)
	{
#ifdef XSL_TRANSFORM_TRACE
		clog << "XslCopy - applying templates" << endl;
#endif
		CompositeMarkupNode::Children * children = _transformer.transform(
				_parentProxy, *_referenceNode);
		if (children != 0)
		{
			copy(children->begin(), children->end(), back_inserter(_result));
			delete children;
		}
#ifdef XSL_TRANSFORM_TRACE
		else
		{
			clog << "XslCopy - no result ?????" << endl;
		}
#endif
	}
	else
	{
		SimpleCopyVisitor copier;
		_result.push_back(copier.copy(_parentProxy, node));
	}
}

void XslCopyVisitor::visit(const CompositeMarkupNode& node)
{
#ifdef XSL_TRANSFORM_TRACE
	clog << "XslCopy on CompositeMarkupNode" << endl;
#endif
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
