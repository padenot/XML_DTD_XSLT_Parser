/*************************************************************************
 * TransformerVisitor
 * -------------------
 * Début      : mar. 05 avril 2011 14:37:55 CEST
 * Auteur(s)  : H4215
 *************************************************************************/

//---- Réalisation de la classe <TransformerVisitor> (fichier TransformerVisitor.cpp) ----

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#ifdef XSL_TRANSFORM_TRACE
#include <iostream>
#endif

//------------------------------------------------------ Include personnel
#include "TransformerVisitor.hh"
#include "TextNode.hh"
#include "MarkupNode.hh"
#include "CompositeMarkupNode.hh"
#include "MapCreator.hh"
#include "SimpleCopyVisitor.hh"
#include "XslCopyVisitor.hh"
using namespace xml;

namespace xsl
{
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

Node * TransformerVisitor::Transformation(Node & XmlTree)
{
#ifdef XSL_TRANSFORM_TRACE
	clog << "Starting main analyze" << endl;
#endif

	list<Node *> * listNodeHTML = AnalyzeNode(0, XmlTree);

#ifdef XSL_TRANSFORM_TRACE
	clog << "End of main analyze" << endl;
#endif

	if (listNodeHTML->size() > 1)
	{
		for (list<Node *>::iterator itList = listNodeHTML->begin(); itList
				!= listNodeHTML->end(); ++itList)
		{
			delete *itList;
		}
		delete listNodeHTML;
		return 0;
	}
	else
	{
		Node * result = listNodeHTML->front();
		delete listNodeHTML;
		return result;
	}
} //----- Fin de Transformation

list<Node *> * TransformerVisitor::AnalyzeNode(
		CompositeMarkupNode ** noeudParent, Node & noeud)
{
#ifdef XSL_TRANSFORM_TRACE
	clog << "AnalyzeNode" << endl;
#endif
	list<Node *> * remplacants = new list<Node *> ();
	noeud.accept(*this);
	if (resultatMap == templatesMap->end()) //si ce template n’existe pas

	{
		SimpleCopyVisitor simpleCopier(*this);
		remplacants->push_back(simpleCopier.copy(noeudParent, noeud));
	}
	else
	{
		const CompositeMarkupNode& templte = *resultatMap->second;
		XslCopyVisitor xslCopier(*this);
		for (CompositeMarkupNode::ChildrenIterator itNoeud = templte.begin(); itNoeud
				!= templte.end(); ++itNoeud)
		{
			list<Node *> * tempList = xslCopier.xslCopy(noeudParent, **itNoeud,
					noeud);
			copy(tempList->begin(), tempList->end(),
					back_inserter(*remplacants));
		}
	}

#ifdef XSL_TRANSFORM_TRACE
	clog << "End of AnalyzeNode" << endl;
#endif
	return remplacants;
} //----- Fin de AnalyserNoeud

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
TransformerVisitor::TransformerVisitor(const xml::Node & XslTree)
{
	templatesMap = new mapXsl();
	createMap(XslTree);

} //----- Fin de OutputVisitor


TransformerVisitor::~TransformerVisitor()
{
	delete templatesMap;
} //----- Fin de ~OutputVisitor


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void TransformerVisitor::createMap(const Node& node)
{
	MapCreator * mapCreator = new MapCreator(templatesMap);
	node.accept(*mapCreator);
}

void TransformerVisitor::visit(const TextNode &)
{
	resultatMap = templatesMap->end();
}

void TransformerVisitor::visit(const MarkupNode & node)
{
	resultatMap = templatesMap->find(node.name());
}

void TransformerVisitor::visit(const CompositeMarkupNode& node)
{
	// On récupère l'index du noeud dans la template map
	resultatMap = templatesMap->find(node.name());
}

} // namespace xsl

//------------------------------------------------------- Méthodes privées
