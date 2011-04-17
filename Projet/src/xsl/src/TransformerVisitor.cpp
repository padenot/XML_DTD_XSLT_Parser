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

namespace xsl
{
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

Node & TransformerVisitor::Transformation(CompositeMarkupNode & XmlTree, Node & XslTree)
{
	creerMap(XslTree);
	return AnalyserNoeud(XmlTree);
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

void TransformerVisitor::getTemplateName(const MarkupNode& node)
{

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

CompositeMarkupNode & TransformerVisitor::AnalyserNoeud(CompositeMarkupNode & noeud)
{
	mapXsl::iterator noeudXslTemplate = RechercherTemplate(noeud);

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
				noeud);*/
	}

} //----- Fin de AnalyserNoeud


void TransformerVisitor::AnalyserTemplate(const Node & patron,
		CompositeMarkupNode & noeud)
{
	/*for (CompositeMarkupNode::ChildrenIterator it = (patron.begin()); it
			!= (patron.end()); it++)
	{
		//if(it.isapplytemplate()){
		/*	it = Recopier(noeud);
		 TransformerVisitor trans(CompositeMarkupNode** parent, ....);
		 noeud.accept(trans);
		 Node* = trans.result();*/
		//} else (if
	}
	/*
	 foreach (fils **f de t)
	 if (f.is(apply_template))
	 **f = recopier(x);
	 else if (!f.isTexte())
	 analyse_template(f,x)
	 else
	 //do nothing
	 end_for
	 end*/

} //----- Fin de AnalyserTemplate


 /*mapXsl::iterator TransformerVisitor::RechercherTemplate(const CompositeMarkupNode & noeudXML)
{
	return templatesMap.find(noeudXML.name());
}*/ //----- Fin de RechercherTemplate

list<Node *> & TransformerVisitor::Recopier(TextNode & noeud)
{
	/*list<Node *> * node = new list<Node *>();
	 node->push_back(&noeud);
	 return *node;*/
	/*
	 else
	 foreach (fils f de x)
	 res.add(analyser_noeud(f))
	 return res;
	 end;*/
} //----- Fin de Recopier

list<Node *> & TransformerVisitor::Recopier(CompositeMarkupNode & noeud)
{
	list<Node *> * node = new list<Node *> ();
	for (CompositeMarkupNode::ChildrenIterator it = (noeud.begin()); it
			!= (noeud.end()); it++)
	{
		//node->push_back(&AnalyserNoeud(**it));
	}

	return *node;
} //----- Fin de Recopier

} // namespace xsl

//------------------------------------------------------- Méthodes privées
