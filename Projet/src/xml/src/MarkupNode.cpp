/*************************************************************************
 * MarkupNode  -  «Description»
 * -------------------
 * Début      : lun. 04 avril 2011 09:01:48 CEST
 * Auteur(s)  : H4215
 *************************************************************************/

//---- Réalisation de la classe <MarkupNode> (fichier MarkupNode.cpp) ----

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "MarkupNode.hh"

namespace xml
{
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void MarkupNode::accept (InterfaceNodeVisitor& visitor) const
{
	visitor.visit(*this);
}

string MarkupNode::ns() const
{
	return _namespace;
}

string MarkupNode::name() const
{
	return _name;
}

MarkupNode::AttributesIterator MarkupNode::begin() const
{
	return _attributes.begin();
}

MarkupNode::AttributesIterator MarkupNode::end() const
{
	return _attributes.end();
}


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
MarkupNode::MarkupNode(CompositeMarkupNode ** parent, const std::string & ns,
		const std::string & name, const Attributes & attributes) :
	Node(parent), _namespace(ns), _name(name), _attributes(attributes)
{
	// Rien à faire.
}


MarkupNode::~MarkupNode()
{
	// Rien à faire.
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

} // namespace xml
