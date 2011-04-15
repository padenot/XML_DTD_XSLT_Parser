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
	CompositeMarkupNode** proxy = new CompositeMarkupNode*;

	result.push_back(buildValidTree(children, *proxy, false));
	return result;
}

list<Node*> SimpleBuilder::buildInvalidTrees() const
{
	list<Node*> result;

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
Node * SimpleBuilder::buildValidTree(
		CompositeMarkupNode::Children markup1Chosen,
		CompositeMarkupNode*& markup1Proxy, bool withMarkup7) const
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
	// TODO : attributes
	attributes.clear();
	//attributes[attname(1)] = attval(1);
	children.push_back(
			new CompositeMarkupNode(proxy, ns(1), name(1), attributes,
					markup1Proxy, markup1Chosen));

	// --- Markup 4
	// TODO : attributes
	attributes.clear();
	//attributes[attname(1)] = attval(1);
	children.push_back(new MarkupNode(proxy, ns(4), name(4), attributes));

	// --- Markup 2
	CompositeMarkupNode::Children children2;
	CompositeMarkupNode** proxy2 = new CompositeMarkupNode*;
	if (withMarkup7)
	{
		// TODO : attributes
		attributes.clear();
		//attributes[attname(1)] = attval(1);
		children2.push_back(new MarkupNode(proxy2, ns(7), name(7), attributes));
	}
	// TODO : attributes
	attributes.clear();
	//attributes[attname(1)] = attval(1);
	children.push_back(
			new CompositeMarkupNode(proxy, ns(2), name(2), attributes, *proxy2,
					children2));

	// --- Markup 3
	// TODO : attributes
	attributes.clear();
	//attributes[attname(1)] = attval(1);
	children.push_back(new MarkupNode(proxy, ns(3), name(3), attributes));

	return new CompositeMarkupNode(0, ns(0), name(0), attributes, *proxy,
			children);
}

