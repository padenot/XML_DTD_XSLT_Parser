/*************************************************************************
 * OutputVisitor  -  Visiteur écrivant un noeud et ses descendants
 * sur un flot.
 * -------------------
 * Début      : mar. 05 avril 2011 14:35:25 CEST
 * Auteur(s)  : H4215
 *************************************************************************/

//---- Interface de la classe <OutputVisitor> (fichier OutputVisitor.hh) ----
#ifndef OUTPUTVISITOR_HH
#define OUTPUTVISITOR_HH

//--------------------------------------------------- Interfaces utilisées
#include <iosfwd>
#include "InterfaceNodeVisitor.hpp"

namespace xml
{
class TextNode;
class MarkupNode;
class CompositeMarkupNode;

class OutputVisitor : public InterfaceNodeVisitor
{
protected:
	static const char DEFAULT_INDENT_CHAR = ' ';
	static const unsigned char DEFAULT_INDENT_UNIT = 1;

public:
	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types

	//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//	«TODO»
	// Contrat :
	//	«TODO»


	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	OutputVisitor(std::ostream & out, char indentChar = DEFAULT_INDENT_CHAR,
			unsigned int indentUnit = DEFAULT_INDENT_UNIT);
	// Mode d'emploi (constructeur) :
	//	Construit un nouveau visiteur écrivant sur "out".
	// Contrat :
	//	Aucun.

	virtual ~OutputVisitor();
	// Mode d'emploi (destructeur) :
	//	Libère les éventuelles ressources allouées par le visiteur.
	// Contrat :
	//	Aucun.

protected:
	static const char OPEN_MARKUP_CHAR;
	static const char NS_SEPARATOR_CHAR;
	static const char INSIDE_MARKUP_SPACE_CHAR;
	static const char CLOSING_MARKUP_CHAR;
	static const char CLOSE_MARKUP_CHAR;
	static const char ASSIGN_ATTRIBUTE_VALUE_CHAR;
	static const char OPEN_ATTRIBUTE_VALUE_CHAR;
	static const char CLOSE_ATTRIBUTE_VALUE_CHAR;

	std::ostream& _out;
	char _indentChar;
	unsigned _indentUnit;
	unsigned int _indent;

	virtual void visit(const TextNode& node) = 0;
	virtual void visit(const MarkupNode& node) = 0;
	virtual void visit(const CompositeMarkupNode& node) = 0;
	// Mode d'emploi :
	//	Écrit le noeud sur le flot "out".
	//	La nature des caractères écrits sur le flot dépend du type du noeud.
	//	Les noeuds inclus sont indentés par rapport à leur ancètre.
	// Contrat :
	//	Aucun.

	void doIndent();
	// Mode d'emploi :
	//	Indente la ligne couraqnte en fonction de la valeur actuelle de
	//	"_indent" avec le caractère "_indentChar".
	// Contrat :
	//	Aucun.

	void writeAttributes(const MarkupNode& node);
	// Mode d'emploi :
	//	Écrit les attributs donnés en paramètres sur le flot "_out"
	// Contrat :
	//	Aucun.

};

} // namespace xml

#endif // OUTPUTVISITOR_HH
