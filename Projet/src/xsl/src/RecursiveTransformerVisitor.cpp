/*************************************************************************
 * RecursiveTransformerVisitor  -  «Description»
 * -------------------
 * Début      : 17 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Réalisation de la classe <RecursiveTransformerVisitor> (fichier RecursiveTransformerVisitor.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#ifdef XSL_TRANSFORM_TRACE
#include <iostream>
#endif

//------------------------------------------------------ Include personnel
#include "RecursiveTransformerVisitor.hh"
#include "TransformerVisitor.hh"
#include "TextNode.hh"
#include "MarkupNode.hh"
#include "CompositeMarkupNode.hh"
using namespace xml;

namespace xsl
{
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
CompositeMarkupNode::Children* RecursiveTransformerVisitor::transform(
		CompositeMarkupNode** proxy, const Node & reference)
{
	_proxy = proxy;
	reference.accept(*this);
	return _result;
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
RecursiveTransformerVisitor::RecursiveTransformerVisitor(
		TransformerVisitor& transformer) :
	_transformer(transformer), _proxy(0), _result(0)
{
	// Rien à faire.
}

RecursiveTransformerVisitor::~RecursiveTransformerVisitor()
{
	// Rien à faire.
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void RecursiveTransformerVisitor::visit(const TextNode&)
{
	_result = 0;
}

void RecursiveTransformerVisitor::visit(const MarkupNode&)
{
	_result = 0;
}

void RecursiveTransformerVisitor::visit(const CompositeMarkupNode& node)
{
#ifdef XSL_TRANSFORM_TRACE
	clog << "RecursiveTransformerVisitor on CompositeMarkupNode" << endl;
#endif
	_result = new CompositeMarkupNode::Children();

	for (CompositeMarkupNode::ChildrenIterator it = node.begin(); it
			!= node.end(); ++it)
	{
#ifdef XSL_TRANSFORM_TRACE
		clog << "Loop in RecursiveTransformerVisitor on CompositeMarkupNode" << endl;
#endif
		CompositeMarkupNode::Children * analyzed = _transformer.AnalyzeNode(
				_proxy, **it);
		copy(analyzed->begin(), analyzed->end(), back_inserter(*_result));
		delete analyzed;
	}

#ifdef XSL_TRANSFORM_TRACE
	clog << "End of RecursiveTransformerVisitor on CompositeMarkupNode" << endl;
#endif
}

} // namespace xsl
