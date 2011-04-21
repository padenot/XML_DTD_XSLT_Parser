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
#include <utility>
#include <list>
#include <map>
#include <string>

//--------------------------------------------------- Includes personnel

#include "InterfaceNodeVisitor.hpp"

namespace xsl
{
class TransformerVisitor: public xml::InterfaceNodeVisitor
{
public:
	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types

	//----------------------------------------------------- Méthodes publiques

	xml::Node * Transformation(xml::Node & XmlTree);
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

	std::list<xml::Node *> * AnalyzeNode(
			xml::CompositeMarkupNode ** noeudParent, xml::Node & noeud);
	// Mode d'emploi (destructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	TransformerVisitor(const xml::Node & XslTree);
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

	typedef std::map<std::pair<std::string,std::string>, const xml::CompositeMarkupNode*> mapXsl;
	mapXsl templatesMap;

	mapXsl::iterator resultatMap;

	void createMap(const xml::Node& node);
	void getTemplateName(const xml::MarkupNode& node);

	virtual void visit(const xml::TextNode& node);
	virtual void visit(const xml::MarkupNode& node);
	virtual void visit(const xml::CompositeMarkupNode& node);

	// TODO inclure MapCreator de manière protected afin de limiter la visibilité des autres classes
	//class MapCreator;
};

} // namespace xsl

#endif // TransformerVisitor_HH
