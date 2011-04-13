/*************************************************************************
 * OutputDTDVisitor  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <OutputDTDVisitor> (fichier OutputDTDVisitor.hh) ------
#if ! defined ( OUTPUTDTDVISITOR_HH_ )
#define OUTPUTDTDVISITOR_HH_

//--------------------------------------------------- Interfaces utilisées
#include <iosfwd>
#include "InterfaceDTDVisitor.hpp"

namespace dtd
{

class OutputDTDVisitor: public InterfaceDTDVisitor
{
protected:
	static const char DEFAULT_INDENT_CHAR = '\t';
	static const unsigned char DEFAULT_INDENT_UNIT = 1;

public:
	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types

	//----------------------------------------------------- Méthodes publiques

	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	OutputDTDVisitor(std::ostream & out, char indentChar = DEFAULT_INDENT_CHAR,
			unsigned int indentUnit = DEFAULT_INDENT_UNIT);
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

	virtual ~OutputDTDVisitor();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

protected:
	static const std::string OPEN_MARKUP_STR;
	static const std::string ELEMENT_MARKUP_NAME_STR;
	static const std::string ATTLIST_MARKUP_NAME_STR;
	static const std::string INSIDE_MARKUP_SPACE_STR;
	static const std::string START_SEQUENCE_STR;
	static const std::string SEQUENCE_SEPARATOR_STR;
	static const std::string END_SEQUENCE_STR;
	static const std::string START_CHOICE_STR;
	static const std::string CHOICE_SEPARATOR_STR;
	static const std::string END_CHOICE_STR;
	static const std::string START_MIXED_STR;
	static const std::string MIXED_SEPARATOR_STR;
	static const std::string END_MIXED_STR;
	static const std::string EMPTY_CONTENT_STR;
	static const std::string ANY_CONTENT_STR;
	static const std::string TEXT_CONTENT_STR;
	static const std::string OPTIONAL_QUANTIFIER_STR;
	static const std::string REPEATABLE_QUANTIFIER_STR;
	static const std::string REPEATED_QUANTIFIER_STR;
	static const std::string CLOSE_MARKUP_STR;

	std::ostream& _out;
	char _indentChar;
	unsigned _indentUnit;
	unsigned int _indent;

	void doIndent();
	// Mode d'emploi :
	//	Indente la ligne courante en fonction de la valeur actuelle de
	//	"_indent" avec le caractère "_indentChar".
	// Contrat :
	//	Aucun.

	virtual void visit(const EmptyContent & content);
	virtual void visit(const AnyContent & content);
	virtual void visit(const MixedContent & content);
	virtual void visit(const TextContent & content);
	virtual void visit(const ElementReference & element);
	virtual void visit(const Choice & content);
	virtual void visit(const Sequence & content);
	virtual void visit(const OptionalContent & content);
	virtual void visit(const RepeatableContent & content);
	virtual void visit(const RepeatedContent & content);
	// Mode d'emploi :
	//	Écrit l'élément sur le flot "_out".
	//	La nature des caractères écrits sur le flot dépend du type du noeud.
	//	Les noeuds inclus sont indentés par rapport à leur ancètre.
	// Contrat :
	//	Aucun.

};

} // namespace dtd

#endif // OUTPUTDTDVISITOR_HH_
