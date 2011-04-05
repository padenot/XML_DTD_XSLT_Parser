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
const char MarkupNode::OPEN_MARKUP_CHAR = '<';
const char MarkupNode::NS_SEPARATOR_CHAR = ':';
const char MarkupNode::INSIDE_MARKUP_SPACE_CHAR = ' ';
const char MarkupNode::CLOSING_MARKUP_CHAR = '/';
const char MarkupNode::CLOSE_MARKUP_CHAR = '>';
const char MarkupNode::ASSIGN_ATTRIBUTE_VALUE_CHAR = '=';
const char MarkupNode::OPEN_ATTRIBUTE_VALUE_CHAR = '"';
const char MarkupNode::CLOSE_ATTRIBUTE_VALUE_CHAR = '"';

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type MarkupNode::Méthode ( liste de paramètres )
// Algorithme :
//	«TODO»
//{
//} //----- Fin de Méthode

ostream& MarkupNode::Write(ostream& out, unsigned char indent) const
{
	doIndent(out, indent);
	out << OPEN_MARKUP_CHAR << _namespace << NS_SEPARATOR_CHAR << _name;
	writeAttributes(out) << CLOSING_MARKUP_CHAR << CLOSE_MARKUP_CHAR << endl;
	return out;
} //----- Fin de Write


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
MarkupNode::MarkupNode(CompositeMarkupNode *& parent, const std::string & ns,
		const std::string & name, const Attributes & attributes) :
	Node(parent), _namespace(ns), _name(name), _attributes(attributes)
{
	// TODO
} //----- Fin de MarkupNode


MarkupNode::~MarkupNode()
{
	// TODO
} //----- Fin de ~MarkupNode


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
ostream& MarkupNode::writeAttributes(ostream& out) const
{
	for (_Attributes::const_iterator it = _attributes.begin(); it
			!= _attributes.end(); ++it)
	{
		out << INSIDE_MARKUP_SPACE_CHAR << it->first
				<< ASSIGN_ATTRIBUTE_VALUE_CHAR << OPEN_ATTRIBUTE_VALUE_CHAR
				<< it->second << CLOSE_ATTRIBUTE_VALUE_CHAR;
	}
	return out;
} //----- Fin de write

//------------------------------------------------------- Méthodes privées

} // namespace xml
