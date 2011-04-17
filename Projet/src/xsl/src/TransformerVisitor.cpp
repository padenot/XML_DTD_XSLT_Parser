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
#include <iostream>
#include <iomanip>

//------------------------------------------------------ Include personnel
#include "TransformerVisitor.hh"
#include "TextNode.hh"
#include "MarkupNode.hh"
#include "CompositeMarkupNode.hh"
#include "MapCreator.hh"
using namespace xml;

namespace xsl
{
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

Node * TransformerVisitor::Transformation(CompositeMarkupNode & XmlTree, Node & XslTree)
{
	creerMap(XslTree);
	list< Node * > * listNodeHTML = AnalyserNoeud(XmlTree);

	// TODO Vérification des noeuds que l'on a construit
	return 0;
} //----- Fin de Transformation

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
TransformerVisitor::TransformerVisitor()
{
	templatesMap = new mapXsl();
	htmlTree = new list<Node *>();

} //----- Fin de OutputVisitor


TransformerVisitor::~TransformerVisitor()
{
	delete htmlTree;
	delete templatesMap;
} //----- Fin de ~OutputVisitor


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void TransformerVisitor::creerMap(const Node& node)
{
	MapCreator * mapCreator = new MapCreator(templatesMap);
	node.accept(*mapCreator);
}

void TransformerVisitor::visit(const TextNode& node)
{

}

void TransformerVisitor::visit(const MarkupNode& node)
{

}

void TransformerVisitor::visit(const CompositeMarkupNode& node)
{
	//node.name();
	for (CompositeMarkupNode::ChildrenIterator it = node.begin(); it
			!= node.end(); ++it)
	{
		(*it)->accept(*this);
	}
}

list <Node * > * TransformerVisitor::AnalyserNoeud(CompositeMarkupNode & noeud)
{
	/*mapXsl::iterator noeudXslTemplate = RechercherTemplate(noeud);

	if(noeudXslTemplate == templatesMap->end())
	{
		(*noeudXslTemplate).second->accept(*this);
	}
	else
	{
		const Node * noeudTemporaire
		= (*noeudXslTemplate)
		.second;
		/*AnalyserTemplate(noeudTemporaire,
				noeud);
	}*/

} //----- Fin de AnalyserNoeud

} // namespace xsl

//------------------------------------------------------- Méthodes privées
