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
	_transformer(transformer)
{
	// Rien à faire.
}

RecursiveTransformerVisitor::~RecursiveTransformerVisitor()
{
	// Rien à faire.
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void RecursiveTransformerVisitor::visit(const TextNode& node)
{
	_result = 0;
}

void RecursiveTransformerVisitor::visit(const MarkupNode& node)
{
	_result = 0;
}

void RecursiveTransformerVisitor::visit(const CompositeMarkupNode& node)
{
	for (CompositeMarkupNode::ChildrenIterator it = node.begin(); it
			!= node.end(); ++it)
	{
		CompositeMarkupNode::Children * analyzed = _transformer.AnalyzeNode(
				_proxy, *it);
		copy(analyzed->begin(), analyzed->end(), back_inserter(_result));
		delete analyzed;
	}
}

} // namespace xsl
