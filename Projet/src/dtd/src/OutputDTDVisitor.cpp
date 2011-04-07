/*************************************************************************
 * OutputDTDVisitor  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Réalisation de la classe <OutputDTDVisitor> (fichier OutputDTDVisitor.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <iomanip>

//------------------------------------------------------ Include personnel
#include "OutputDTDVisitor.hh"
#include "Element.hh"
#include "AttributesList.hh"
#include "EmptyContent.hh"
#include "AnyContent.hh"
#include "MixedContent.hh"
#include "ElementReference.hh"
#include "Choice.hh"
#include "Sequence.hh"
#include "OptionalContent.hh"
#include "RepeatableContent.hh"
#include "RepeatedContent.hh"

namespace dtd
{
//------------------------------------------------------------- Constantes
const std::string OutputDTDVisitor::OPEN_MARKUP_STR = "<!";
const std::string OutputDTDVisitor::ELEMENT_MARKUP_NAME_STR = "ELEMENT";
const std::string OutputDTDVisitor::ATTLIST_MARKUP_NAME_STR = "ATTLIST";
const std::string OutputDTDVisitor::INSIDE_MARKUP_SPACE_STR = " ";
const std::string OutputDTDVisitor::START_SEQUENCE_STR = "(";
const std::string OutputDTDVisitor::SEQUENCE_SEPARATOR_STR = ",";
const std::string OutputDTDVisitor::END_SEQUENCE_STR = ")";
const std::string OutputDTDVisitor::START_CHOICE_STR = "(";
const std::string OutputDTDVisitor::CHOICE_SEPARATOR_STR = "|";
const std::string OutputDTDVisitor::END_CHOICE_STR = ")";
const std::string OutputDTDVisitor::START_MIXED_STR = "(";
const std::string OutputDTDVisitor::MIXED_SEPARATOR_STR = "|";
const std::string OutputDTDVisitor::END_MIXED_STR = ")";
const std::string OutputDTDVisitor::EMPTY_CONTENT_STR = "EMPTY";
const std::string OutputDTDVisitor::ANY_CONTENT_STR = "ANY";
const std::string OutputDTDVisitor::TEXT_CONTENT_STR = "#PCDATA";
const std::string OutputDTDVisitor::OPTIONAL_QUANTIFIER_STR = "?";
const std::string OutputDTDVisitor::REPEATABLE_QUANTIFIER_STR = "*";
const std::string OutputDTDVisitor::REPEATED_QUANTIFIER_STR = "+";
const std::string OutputDTDVisitor::CLOSE_MARKUP_STR = ">";

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type OutputDTDVisitor::Méthode ( liste des paramètres )
// Algorithme :
//	
//{
//}


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
OutputDTDVisitor::OutputDTDVisitor(std::ostream & out, char indentChar,
		unsigned int indentUnit) :
	_out(out), _indentChar(indentChar), _indentUnit(indentUnit), _indent(0)
{
	//TODO
}

OutputDTDVisitor::~OutputDTDVisitor()
{
	//TODO
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void OutputDTDVisitor::doIndent()
{
	if (_indent > 0)
	{
		char fillChar = _out.fill(_indentChar);
		_out << setw(_indent) << _indentChar;
		_out.fill(fillChar);
	}
} //----- Fin de doIndent

void OutputDTDVisitor::visit(const Element & element)
{
	_out << OPEN_MARKUP_STR << ELEMENT_MARKUP_NAME_STR
			<< INSIDE_MARKUP_SPACE_STR << element.name()
			<< INSIDE_MARKUP_SPACE_STR;
	element.content().accept(*this);
	_out << CLOSE_MARKUP_STR << endl;
}

void OutputDTDVisitor::visit(const AttributesList & attlist)
{
	_out << OPEN_MARKUP_STR << ATTLIST_MARKUP_NAME_STR
			<< INSIDE_MARKUP_SPACE_STR << attlist.name() << endl;

	_indent += _indentUnit;
	for (int i = 0; i < 3; ++i)
	{
		doIndent();
		_out << ">>>>>>>>>>>>>>TODO TODO TODO <<<<<<<<<<<" << endl;
	}
	_indent -= _indentUnit;

	doIndent();
	_out << CLOSE_MARKUP_STR << endl;
}

void OutputDTDVisitor::visit(const AnyContent &)
{
	_out << ANY_CONTENT_STR;
}

void OutputDTDVisitor::visit(const EmptyContent &)
{
	_out << EMPTY_CONTENT_STR;
}

void OutputDTDVisitor::visit(const MixedContent & content)
{
	_out << START_MIXED_STR;
	for (int i = 0; i < 3; ++i)
	{
		_out << MIXED_SEPARATOR_STR << "#TODO#>" << endl;
	}
	_out << END_MIXED_STR;
}

void OutputDTDVisitor::visit(const TextContent & content)
{
	_out << TEXT_CONTENT_STR;
}

void OutputDTDVisitor::visit(const ElementReference & element)
{
	_out << element.name();
}

void OutputDTDVisitor::visit(const Choice & content)
{
	_out << START_CHOICE_STR << "#TODO#";
	for (int i = 0; i < 2; ++i)
	{
		_out << CHOICE_SEPARATOR_STR << "#TODO#>" << endl;
	}
	_out << END_CHOICE_STR;
}

void OutputDTDVisitor::visit(const Sequence & content)
{
	_out << START_SEQUENCE_STR << "#TODO#";
	for (int i = 0; i < 2; ++i)
	{
		_out << SEQUENCE_SEPARATOR_STR << "#TODO#>" << endl;
	}
	_out << END_SEQUENCE_STR;
}

void OutputDTDVisitor::visit(const OptionalContent & content)
{
	content.content().accept(*this);
	_out << OPTIONAL_QUANTIFIER_STR;
}

void OutputDTDVisitor::visit(const RepeatableContent & content)
{
	content.content().accept(*this);
	_out << REPEATABLE_QUANTIFIER_STR;
}

void OutputDTDVisitor::visit(const RepeatedContent & content)
{
	content.content().accept(*this);
	_out << REPEATED_QUANTIFIER_STR;
}

} // namespace dtd
