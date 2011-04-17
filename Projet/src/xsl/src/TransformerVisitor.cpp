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

Node * TransformerVisitor::Transformation(CompositeMarkupNode & XmlTree)
{
	list<Node *> * listNodeHTML = AnalyzeNode(0, XmlTree);

	// TODO Vérification des noeuds que l'on a construit
	return 0;
} //----- Fin de Transformation

list<Node *> * TransformerVisitor::AnalyzeNode(
		CompositeMarkupNode ** noeudParent, Node & noeud)
{
	noeud.accept(*this);
	if (resultatMap == templatesMap->end()) //si ce template n’existe pas

	{
		//return copie_simple(parent,x);
	}
	else
	{
		list<Node *> * remplacants = new list<Node *> ();

		for (CompositeMarkupNode::ChildrenIterator itNoeud =
				(*resultatMap).second->begin(); itNoeud != (*resultatMap).second->end(); ++itNoeud)
		{
			// remplaçants.concat(copie_xsl(Ft,x))
		}

		return remplacants;
	}
} //----- Fin de AnalyserNoeud

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
TransformerVisitor::TransformerVisitor(const xml::CompositeMarkupNode & XslTree)
{
	templatesMap = new mapXsl();
	htmlTree = new list<Node *> ();
	creerMap(XslTree);

} //----- Fin de OutputVisitor


TransformerVisitor::~TransformerVisitor()
{
	delete htmlTree;
	delete templatesMap;
} //----- Fin de ~OutputVisitor


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void TransformerVisitor::creerMap(const CompositeMarkupNode& node)
{
	MapCreator * mapCreator = new MapCreator(templatesMap);
	node.accept(*mapCreator);
}

void TransformerVisitor::visit(const TextNode &)
{

}

void TransformerVisitor::visit(const MarkupNode & node)
{
	resultatMap = templatesMap->find(node.name());
}

void TransformerVisitor::visit(const CompositeMarkupNode& node)
{
	// On récupère l'index du noeud dans la template map
	resultatMap = templatesMap->find(node.name());

	// Si jamais le noeud courant ne correspond pas on recherche en profondeur
	// TODO vérifier si on a besoin de rechercher en profondeur
	/*if (resultatMap == templatesMap->end())
	 {
	 for (CompositeMarkupNode::ChildrenIterator it = node.begin(); it
	 != node.end(); ++it)
	 {
	 (*it)->accept(*this);
	 }
	 }*/
}

} // namespace xsl

//------------------------------------------------------- Méthodes privées
