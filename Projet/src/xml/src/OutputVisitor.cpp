/*************************************************************************
 * OutputVisitor
 * -------------------
 * Début      : mar. 05 avril 2011 14:37:55 CEST
 * Auteur(s)  : H4215
 *************************************************************************/

//---- Réalisation de la classe <OutputVisitor> (fichier OutputVisitor.cpp) ----

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <iomanip>

//------------------------------------------------------ Include personnel
#include "OutputVisitor.hh"
#include "TextNode.hh"
#include "MarkupNode.hh"
#include "CompositeMarkupNode.hh"

namespace xml
{
//------------------------------------------------------------- Constantes
const std::string OutputVisitor::OPEN_MARKUP_STR = "<";
const std::string OutputVisitor::NS_SEPARATOR_STR = ":";
const std::string OutputVisitor::INSIDE_MARKUP_SPACE_STR = " ";
const std::string OutputVisitor::CLOSING_MARKUP_STR = "/";
const std::string OutputVisitor::CLOSE_MARKUP_STR = ">";
const std::string OutputVisitor::ASSIGN_ATTRIBUTE_VALUE_STR = "=";
const std::string OutputVisitor::OPEN_ATTRIBUTE_VALUE_STR = "\"";
const std::string OutputVisitor::CLOSE_ATTRIBUTE_VALUE_STR = "\"";

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
OutputVisitor::OutputVisitor(ostream & out, char indentChar,
		unsigned int indentUnit) :
	_out(out), _indentChar(indentChar), _indentUnit(indentUnit), _indent(0)
{
	// Rien à faire
} //----- Fin de OutputVisitor


OutputVisitor::~OutputVisitor()
{
	// Rien à faire
} //----- Fin de ~OutputVisitor


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void OutputVisitor::doIndent()
{
	if (_indent > 0)
	{
		char fillChar = _out.fill(_indentChar);
		_out << setw(_indent) << _indentChar;
		_out.fill(fillChar);
	}
} //----- Fin de doIndent

void OutputVisitor::writeAttributes(const MarkupNode& node)
{
	for (MarkupNode::AttributesIterator it = node.begin(); it != node.end(); ++it)
	{
		_out << INSIDE_MARKUP_SPACE_STR << it->first
				<< ASSIGN_ATTRIBUTE_VALUE_STR << OPEN_ATTRIBUTE_VALUE_STR
				<< it->second << CLOSE_ATTRIBUTE_VALUE_STR;
	}
} //----- Fin de writeAttributes

void OutputVisitor::visit(const TextNode& node)
{
	doIndent();
	_out << node.content() << endl;
}

void OutputVisitor::visit(const MarkupNode& node)
{
	doIndent();
	_out << OPEN_MARKUP_STR << node.ns() << NS_SEPARATOR_STR << node.name();
	writeAttributes(node);
	_out << CLOSING_MARKUP_STR << CLOSE_MARKUP_STR << endl;
}

void OutputVisitor::visit(const CompositeMarkupNode& node)
{
	doIndent();
	_out << OPEN_MARKUP_STR << node.ns() << NS_SEPARATOR_STR << node.name();
	writeAttributes(node);
	_out << CLOSE_MARKUP_STR << endl;

	_indent += _indentUnit;
	for (CompositeMarkupNode::ChildrenIterator it = node.begin(); it
			!= node.end(); ++it)
	{
		(*it)->accept(*this);
	}
	_indent -= _indentUnit;

	doIndent();
	_out << OPEN_MARKUP_STR << CLOSING_MARKUP_STR << node.ns()
			<< NS_SEPARATOR_STR << node.name() << CLOSE_MARKUP_STR << endl;
}

//------------------------------------------------------- Méthodes privées

} // namespace xml
