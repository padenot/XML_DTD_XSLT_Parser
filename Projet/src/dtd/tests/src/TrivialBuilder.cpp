/*************************************************************************
 * TrivialBuilder  -  «Description»
 * -------------------
 * Début      : 15 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Réalisation de la classe <TrivialBuilder> (fichier TrivialBuilder.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrivialBuilder.hh"
#include "EmptyContent.hh"
#include "AttributesList.hh"
using namespace dtd;
using namespace xml;

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrivialBuilder::buildDTD(DTD& dtd) const
{
	AttributesList attlist;

	// --- ROOT
	dtd.addElement(ns(0), name(0), *new EmptyContent());

	attlist.insert(new Attribute(attname(0)));
	attlist.insert(new Attribute(attname(1)));
	dtd.addAttributesList(ns(0), name(0), attlist);

	// --- USELESS ATTLISTS
	attlist.clear();
	attlist.insert(new Attribute(attname(2)));
	attlist.insert(new Attribute(attname(3)));
	dtd.addAttributesList(ns(2), name(1), attlist);

	attlist.clear();
	attlist.insert(new Attribute(attname(2)));
	attlist.insert(new Attribute(attname(3)));
	dtd.addAttributesList(ns(1), name(3), attlist);
}

list<Node*> TrivialBuilder::buildValidTrees() const
{
	list<Node*> result;
	MarkupNode::Attributes attributes;

	// #01
	result.push_back(new MarkupNode(0, ns(0), name(0), attributes));

	// #02
	attributes[attname(0)] = attval(0);
	result.push_back(new MarkupNode(0, ns(0), name(0), attributes));

	// #03
	attributes[attname(1)] = attval(1);
	result.push_back(new MarkupNode(0, ns(0), name(0), attributes));

	// #04
	attributes.clear();
	attributes[attname(1)] = attval(1);
	result.push_back(new MarkupNode(0, ns(0), name(0), attributes));

	return result;
}

list<Node*> TrivialBuilder::buildInvalidTrees() const
{
	list<Node*> result;
	MarkupNode::Attributes attributes;
	CompositeMarkupNode::Children children;
	CompositeMarkupNode** proxy;

	// #01
	proxy = new CompositeMarkupNode*;
	result.push_back(
			new CompositeMarkupNode(0, ns(0), name(0), attributes, *proxy,
					children));

	// #02
	result.push_back(
			new MarkupNode(0, ns(1), name(0), attributes));

	// #03
	result.push_back(
			new MarkupNode(0, ns(0), name(1), attributes));

	// #04
	result.push_back(
			new MarkupNode(0, ns(2), name(1), attributes));

	// #05
	attributes[attname(3)] = attval(3);
	result.push_back(
			new MarkupNode(0, ns(0), name(0), attributes));

	return result;
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
TrivialBuilder::TrivialBuilder()
{
	// Ne fait rien.
}

TrivialBuilder::~TrivialBuilder()
{
	// Ne fait rien.
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

