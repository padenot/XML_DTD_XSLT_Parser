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
const std::string XslCopyVisitor::NAMESPACE_APPLY_TEMPLATES("xsl");
//const std::string XslCopyVisitor::NAMESPACE_APPLY_TEMPLATES;
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
	// Rien à faire
}

XslCopyVisitor::~XslCopyVisitor()
{
	// Rien à faire
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void XslCopyVisitor::visit(const TextNode& templte)
{
#ifdef XSL_TRANSFORM_TRACE
	clog << "XslCopy on TextNode" << endl;
#endif
	SimpleCopyVisitor copier(_transformer);
	_result.push_back(copier.copy(_parentProxy, templte));
}

void XslCopyVisitor::visit(const MarkupNode& templte)
{
#ifdef XSL_TRANSFORM_TRACE
	clog << "XslCopy on MarkupNode" << endl;
#endif
	if (templte.ns() == NAMESPACE_APPLY_TEMPLATES && templte.name()
			== NAME_APPLY_TEMPLATES)
	{
#ifdef XSL_TRANSFORM_TRACE
		clog << "XslCopy - applying templates" << endl;
#endif
		CompositeMarkupNode::Children * newChildren = _transformer.transform(
				_parentProxy, *_referenceNode);
		if (newChildren != 0)
		{
			copy(newChildren->begin(), newChildren->end(), back_inserter(
					_result));
			delete newChildren;
		}
	}
	else
	{
		SimpleCopyVisitor copier(_transformer);
		_result.push_back(copier.copy(_parentProxy, templte));
	}
}

void XslCopyVisitor::visit(const CompositeMarkupNode& templte)
{
#ifdef XSL_TRANSFORM_TRACE
	clog << "XslCopy on CompositeMarkupNode" << endl;
#endif
	MarkupNode::Attributes copiedAttributes(templte.MarkupNode::begin(),
			templte.MarkupNode::end());
	CompositeMarkupNode::Children children;
	CompositeMarkupNode ** myParent = _parentProxy;

	_parentProxy = new CompositeMarkupNode*;

	for (CompositeMarkupNode::ChildrenIterator it = templte.begin(); it
			!= templte.end(); ++it)
	{
		(*it)->accept(*this);
		copy(_result.begin(), _result.end(), back_inserter(children));
	}

	_result.assign(1, new CompositeMarkupNode(myParent, templte.ns(),
			templte.name(), copiedAttributes, *_parentProxy, children));

	_parentProxy = myParent;
}

} // namespace xsl
