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

#include<list>

//--------------------------------------------------- Includes personnel

#include "Node.hh"
using namespace xml;

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
	list<Node> & AnalyserNoeud(Node & noeud);
	// Mode d'emploi (destructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

	void AnalyserTemplate(Node & patron, Node & noeud);
	// Mode d'emploi (destructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

	list<Node> & Recopier(Node & noeud);
	// Mode d'emploi (destructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

};

} // namespace xsl

#endif // XSL_TRANSFORMATION_HH
