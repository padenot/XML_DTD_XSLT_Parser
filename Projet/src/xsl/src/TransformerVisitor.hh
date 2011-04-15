/*************************************************************************
 * TransformerVisitor  -  Visiteur 
 * -------------------
 * Début      : mar. 05 avril 2011 14:35:25 CEST
 * Auteur(s)  : H4215
 *************************************************************************/

//---- Interface de la classe <TransformerVisitor> (fichier TransformerVisitor.hh) ----
#ifndef TransformerVisitor_HH
#define TransformerVisitor_HH

//--------------------------------------------------- Interfaces utilisées

#include <list>
#include <map>
#include <string>

//--------------------------------------------------- Includes personnel

#include "InterfaceNodeVisitor.hpp"
#include <map>
#include <string>

using namespace xml;
using namespace std;

namespace xsl
{
class TransformerVisitor: public InterfaceNodeVisitor
{
public:
	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types

	//----------------------------------------------------- Méthodes publiques

	Node & Transformation(Node & XmlTree, Node & XslTree);
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	TransformerVisitor();
	// Mode d'emploi (constructeur) :
	//	Construit un nouveau visiteur.
	// Contrat :
	//	Aucun.


	virtual ~TransformerVisitor();
	// Mode d'emploi (destructeur) :
	//	Libère les éventuelles ressources allouées par le visiteur.
	// Contrat :
	//	Aucun.


protected:

	typedef std::map<std::string, const Node*> map;
	map * templatesMap;
	
	void creerMap(const Node& node);
	void getTemplateName(const MarkupNode& node);

	virtual void visit(const TextNode& node);
	virtual void visit(const MarkupNode& node);
	virtual void visit(const CompositeMarkupNode& node);

	CompositeMarkupNode & AnalyserNoeud(Node & noeud);
	// Mode d'emploi (destructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

	void AnalyserTemplate(CompositeMarkupNode & patron, Node & noeud);
	// Mode d'emploi (destructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

	list<Node *> & Recopier(TextNode & noeud);
	// Mode d'emploi (destructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

	list<Node *> & Recopier(CompositeMarkupNode & noeud);
	// Mode d'emploi (destructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

	Node & RechercherTemplate(const Node & noeudXML);
	// Mode d'emploi (destructeur) :
	//	 Effectue la recherche du noeud template xsl associ� au noeud pass� en
	//	 param�tre. Null est retourn� si aucun template n'est trouv�.
	// Contrat :
	//
};

} // namespace xsl

#endif // TransformerVisitor_HH
