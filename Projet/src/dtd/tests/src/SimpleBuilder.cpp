/*************************************************************************
 * SimpleBuilder  -  «Description»
 * -------------------
 * Début      : 15 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Réalisation de la classe <SimpleBuilder> (fichier SimpleBuilder.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "SimpleBuilder.hh"
#include "Sequence.hh"
#include "Choice.hh"
#include "EmptyContent.hh"
#include "ElementReference.hh"
#include "MixedContent.hh"
#include "OptionalContent.hh"
#include "TextContent.hh"
#include "RepeatableContent.hh"
#include "AttributesList.hh"
using namespace dtd;
using namespace xml;

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void SimpleBuilder::buildDTD(DTD& dtd) const
{
	unsigned int elementNumber = 0;
	AttributesList attlist;

	// --- ROOT : SEQUENCE
	Sequence::OrderedContent embeddedContent;
	embeddedContent.push_back(new ElementReference(dtd, ns(1), name(1)));
	embeddedContent.push_back(new ElementReference(dtd, ns(4), name(4)));
	embeddedContent.push_back(new ElementReference(dtd, ns(2), name(2)));
	embeddedContent.push_back(new ElementReference(dtd, ns(3), name(3)));
	dtd.addElement(ns(elementNumber), name(elementNumber),
			*new Sequence(embeddedContent));

	attlist.clear();
	attlist.insert(new Attribute(attname(2)));
	attlist.insert(new Attribute(attname(3)));
	dtd.addAttributesList(ns(elementNumber), name(elementNumber), attlist);

	elementNumber = 1;

	// --- CHILD 1 : REPEATABLECONTENT(MIXEDCONTENT)
	MixedContent::ChoosableSet choosables;
	choosables.insert(new ElementReference(dtd, ns(5), name(5)));
	choosables.insert(new ElementReference(dtd, ns(6), name(6)));
	dtd.addElement(
			ns(elementNumber),
			name(elementNumber),
			*new RepeatableContent(
					*new MixedContent(*new TextContent(), choosables)));

	attlist.clear();
	attlist.insert(new Attribute(attname(0)));
	attlist.insert(new Attribute(attname(1)));
	dtd.addAttributesList(ns(elementNumber), name(elementNumber), attlist);

	elementNumber = 2;

	// --- CHILD 2 : OPTIONAL CONTENT
	dtd.addElement(ns(elementNumber), name(elementNumber),
			*new OptionalContent(*new ElementReference(dtd, ns(7), name(7))));

	attlist.clear();
	attlist.insert(new Attribute(attname(4)));
	attlist.insert(new Attribute(attname(5)));
	dtd.addAttributesList(ns(elementNumber), name(elementNumber), attlist);

	// --- LEAFS
	for (int i = 3; i <= 7; ++i)
	{
		dtd.addElement(ns(i), name(i), *new EmptyContent());
	}
}

list<Node*> SimpleBuilder::buildValidTrees() const
{
	list<Node*> result;
	MarkupNode::Attributes attributes;
	CompositeMarkupNode::Children children;
	CompositeMarkupNode** proxy = 0;

	// #01
	children.clear();
	proxy = new CompositeMarkupNode*;
	result.push_back(buildTree(children, *proxy, false));

	// #02
	children.clear();
	proxy = new CompositeMarkupNode*;
	result.push_back(buildTree(children, *proxy, true));

	// #03
	children.clear();
	proxy = new CompositeMarkupNode*;
	// TODO : attributes
	children.push_back(new TextNode(proxy, text(0)));
	result.push_back(buildTree(children, *proxy, false));

	// #04
	children.clear();
	proxy = new CompositeMarkupNode*;
	// TODO : attributes
	children.push_back(new TextNode(proxy, text(0)));
	result.push_back(buildTree(children, *proxy, true));

	// #05
	children.clear();
	proxy = new CompositeMarkupNode*;
	// TODO : attributes
	children.push_back(new MarkupNode(proxy, ns(5), name(5), attributes));
	result.push_back(buildTree(children, *proxy, false));

	// #06
	children.clear();
	proxy = new CompositeMarkupNode*;
	// TODO : attributes
	children.push_back(new MarkupNode(proxy, ns(6), name(6), attributes));
	result.push_back(buildTree(children, *proxy, false));

	// #07
	children.clear();
	proxy = new CompositeMarkupNode*;
	// TODO : attributes
	children.push_back(new MarkupNode(proxy, ns(5), name(5), attributes));
	children.push_back(new MarkupNode(proxy, ns(5), name(5), attributes));
	children.push_back(new TextNode(proxy, text(0)));
	children.push_back(new MarkupNode(proxy, ns(6), name(6), attributes));
	children.push_back(new TextNode(proxy, text(1)));
	children.push_back(new TextNode(proxy, text(0)));
	children.push_back(new MarkupNode(proxy, ns(6), name(6), attributes));
	children.push_back(new TextNode(proxy, text(2)));
	children.push_back(new MarkupNode(proxy, ns(5), name(5), attributes));
	children.push_back(new TextNode(proxy, text(3)));
	result.push_back(buildTree(children, *proxy, false));

	// #08
	children.clear();
	proxy = new CompositeMarkupNode*;
	// TODO : attributes
	children.push_back(new MarkupNode(proxy, ns(5), name(5), attributes));
	children.push_back(new MarkupNode(proxy, ns(5), name(5), attributes));
	children.push_back(new TextNode(proxy, text(0)));
	children.push_back(new MarkupNode(proxy, ns(6), name(6), attributes));
	children.push_back(new TextNode(proxy, text(1)));
	children.push_back(new TextNode(proxy, text(0)));
	children.push_back(new MarkupNode(proxy, ns(6), name(6), attributes));
	children.push_back(new TextNode(proxy, text(2)));
	children.push_back(new MarkupNode(proxy, ns(5), name(5), attributes));
	children.push_back(new TextNode(proxy, text(3)));
	result.push_back(buildTree(children, *proxy, true));

	// #09
	// TODO : attributes
	result.push_back(new MarkupNode(0, ns(4), name(4), attributes));

	// #10
	// TODO : attributes
	result.push_back(new MarkupNode(0, ns(5), name(5), attributes));

	// #11
	// TODO : attributes
	result.push_back(new MarkupNode(0, ns(6), name(6), attributes));

	// #12
	// TODO : attributes
	result.push_back(new MarkupNode(0, ns(7), name(7), attributes));

	return result;
}

list<Node*> SimpleBuilder::buildInvalidTrees() const
{
	list<Node*> result;
	MarkupNode::Attributes attributes;
	CompositeMarkupNode::Children children;
	CompositeMarkupNode** proxy = 0;

	// #01
	children.clear();
	proxy = new CompositeMarkupNode*;
	// TODO : attributes
	children.push_back(new MarkupNode(proxy, ns(7), name(7), attributes));
	result.push_back(buildTree(children, *proxy, false));

	// #02
	children.clear();
	proxy = new CompositeMarkupNode*;
	// TODO : attributes
	children.push_back(new MarkupNode(proxy, ns(7), name(7), attributes));
	children.push_back(new TextNode(proxy, text(1)));
	result.push_back(buildTree(children, *proxy, false));

	// #03
	children.clear();
	proxy = new CompositeMarkupNode*;
	// TODO : attributes
	children.push_back(new MarkupNode(proxy, ns(7), name(7), attributes));
	children.push_back(new TextNode(proxy, text(1)));
	children.push_back(new MarkupNode(proxy, ns(9), name(9), attributes));
	result.push_back(buildTree(children, *proxy, false));

	// #04
	// TODO : attributes
	result.push_back(new MarkupNode(0, ns(0), name(0), attributes));

	// #05
	// TODO : attributes
	result.push_back(new MarkupNode(0, ns(8), name(8), attributes));

	// #06 - #20
	// Try each possibility to have an invalid tree just by omitting
	//	a node - with markup7
	for (char c = 0; c < 0x0F; ++c)
	{
		children.clear();
		proxy = new CompositeMarkupNode*;
		// TODO : attributes
		result.push_back(
				buildTree(children, *proxy, false, c & 0x08, c & 0x04,
						c & 0x02, c & 0x01));
	}

	// #21 - #35
	// Try each possibility to have an invalid tree just by omitting
	//	a node - without markup7
	for (char c = 0; c < 0x0F; ++c)
	{
		children.clear();
		proxy = new CompositeMarkupNode*;
		// TODO : attributes
		result.push_back(
				buildTree(children, *proxy, false, c & 0x08, c & 0x04,
						c & 0x02, c & 0x01));
	}

	return result;
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
SimpleBuilder::SimpleBuilder()
{
	// Rien à faire.
}

SimpleBuilder::~SimpleBuilder()
{
	// Rien à faire.
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
Node * SimpleBuilder::buildTree(CompositeMarkupNode::Children markup1Chosen,
		CompositeMarkupNode*& markup1Proxy, bool withMarkup7, bool withMarkup1,
		bool withMarkup4, bool withMarkup2, bool withMarkup3) const
/* Builds this :
 * <document>
 *  <markup1>
 *  <!-- insert markup1Chosen here -->
 *  </markup1>
 *  <markup4 />
 *  <markup2>
 *  <!-- insert an instance of markup7 here if withMarkup7 is true -->
 *  </markup2>
 *  <markup3 />
 * </document>
 */
{
	MarkupNode::Attributes attributes;
	CompositeMarkupNode::Children children;
	CompositeMarkupNode** proxy;

	proxy = new CompositeMarkupNode*;

	// --- Markup 1
	if (withMarkup1)
	{
		// TODO : attributes
		attributes.clear();
		//attributes[attname(1)] = attval(1);
		children.push_back(
				new CompositeMarkupNode(proxy, ns(1), name(1), attributes,
						markup1Proxy, markup1Chosen));
	}

	// --- Markup 4
	if (withMarkup4)
	{
		// TODO : attributes
		attributes.clear();
		//attributes[attname(1)] = attval(1);
		children.push_back(new MarkupNode(proxy, ns(4), name(4), attributes));
	}

	// --- Markup 2
	if (withMarkup2)
	{
		CompositeMarkupNode::Children children2;
		CompositeMarkupNode** proxy2 = new CompositeMarkupNode*;
		if (withMarkup7)
		{
			// TODO : attributes
			attributes.clear();
			//attributes[attname(1)] = attval(1);
			children2.push_back(
					new MarkupNode(proxy2, ns(7), name(7), attributes));
		}
		// TODO : attributes
		attributes.clear();
		//attributes[attname(1)] = attval(1);
		children.push_back(
				new CompositeMarkupNode(proxy, ns(2), name(2), attributes,
						*proxy2, children2));
	}

	// --- Markup 3
	if (withMarkup3)
	{
		// TODO : attributes
		attributes.clear();
		//attributes[attname(1)] = attval(1);
		children.push_back(new MarkupNode(proxy, ns(3), name(3), attributes));
	}

	return new CompositeMarkupNode(0, ns(0), name(0), attributes, *proxy,
			children);
}

