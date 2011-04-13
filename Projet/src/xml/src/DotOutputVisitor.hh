/*************************************************************************
 * DotOutputVisitor  -  Visiteur écrivant un noeud et ses descendants
 * sur un flot au format .dot
 * -------------------
 * Début      : mar. 05 avril 2011 14:35:25 CEST
 * Auteur(s)  : H4215
 *************************************************************************/

//---- Interface de la classe <DotOutputVisitor> (fichier DotOutputVisitor.hh) ----
#ifndef DotOutputVisitor_HH
#define DotOutputVisitor_HH

//--------------------------------------------------- Interfaces utilisées
#include <iosfwd>
#include <string>
#include "InterfaceNodeVisitor.hpp"

namespace xml
{
class TextNode;
class MarkupNode;
class CompositeMarkupNode;

class DotOutputVisitor: public InterfaceNodeVisitor
{
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
	DotOutputVisitor(std::ostream & out, std::string filename);
	// Mode d'emploi (constructeur) :
	//	Construit un nouveau visiteur écrivant sur "out".
	// Contrat :
	//	Aucun.
	
		void writeDot(Node * node);

	virtual ~DotOutputVisitor();
	// Mode d'emploi (destructeur) :
	//	Libère les éventuelles ressources allouées par le visiteur.
	// Contrat :
	//	Aucun.
	
	

protected:
	static const std::string GRAPH_TYPE;
	static const std::string LINK;

	std::ostream& _out;
	std::string _document;
	int textNodesCount;
	int _nodesCounter;


	void writeAttributes(const MarkupNode& node);
	// Mode d'emploi :
	//	Écrit les attributs donnés en paramètres sur le flot "_out"
	// Contrat :
	//	Aucun.

	virtual void visit(const TextNode& node);
	virtual void visit(const MarkupNode& node);
	virtual void visit(const CompositeMarkupNode& node);
	// Mode d'emploi :
	//	Écrit le noeud sur le flot "_out".
	//	La nature des caractères écrits sur le flot dépend du type du noeud.
	//	Les noeuds inclus sont indentés par rapport à leur ancètre.
	// Contrat :
	//	Aucun.
	
	void declareNode(const Node& node, std::string label);
	void writeId(const Node& node);


};

} // namespace xml

#endif // DotOutputVisitor_HH
