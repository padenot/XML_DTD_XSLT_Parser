/*************************************************************************
 * CompositeMarkupNode  -  «Description»
 * -------------------
 * Début      : lun. 04 avril 2011 11:12:19 CEST
 * Auteur(s)  : H4215
 *************************************************************************/

//---- Interface de la classe <CompositeMarkupNode> (fichier CompositeMarkupNode.hh) ----
#ifndef XSL_TRANFORMATION_HH
#define XSL_TRANFORMATION_HH

//--------------------------------------------------- Interfaces utilisées

//--------------------------------------------------- Includes syst�me

#include <list>
#include <map>

//--------------------------------------------------- Includes personnel

#include "Node.hh"
using namespace xml;
using namespace std;

namespace xsl
{

class XslTransformation
{
protected:

public:
	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types

	//----------------------------------------------------- Méthodes publiques
	Node & Transformation(const Node & XmlTree, const Node & XslTree);
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	XslTransformation();
	// Mode d'emploi (constructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

	virtual ~XslTransformation();
	// Mode d'emploi (destructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

private:
	typedef std::map<std::string, Node*> map;
	map * templatesMap;
	Node & AnalyserNoeud(Node & noeud);
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
	
	void creerMap(const Node& noeudXSL );
	// Mode d'emploi (destructeur) :
	//	Cr�e la map
	// Contrat :
	//	
};

} // namespace xsl

#endif // XSL_TRANSFORMATION_HH
