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

namespace xsl
{
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

Node & TransformerVisitor::Transformation(Node & XmlTree, Node & XslTree)
{
	creerMap(XslTree);
	return AnalyserNoeud(XmlTree); // TODO d�commenter si �a marche
} //----- Fin de Transformation

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
TransformerVisitor::TransformerVisitor()
{
	templatesMap = new map();
} //----- Fin de OutputVisitor


TransformerVisitor::~TransformerVisitor()
{
	delete templatesMap;
} //----- Fin de ~OutputVisitor


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées



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

CompositeMarkupNode & TransformerVisitor::AnalyserNoeud(Node & noeud)
{
	//CompositeMarkupNode patron = templatesMap["le noeud"/*noeud*/];
	/*analyser_noeud(Noeud x)
	 Template t = rechercher_template(x); //recherche un template qui matche x
	 if (t == vide) //si ce template n�existe pas
	 return recopier(x);
	 else
	 copier (t -> res) //on r̩copie le contenu du template ...
	 //on l�analyse pour l��̩tendre� avec les apply-template et apr̬s on le renvoie
	 analyse_template(res,x)
	 return res;
	 end*/
} //----- Fin de AnalyserNoeud


void TransformerVisitor::AnalyserTemplate(CompositeMarkupNode & patron, Node & noeud)
{
	for (CompositeMarkupNode::ChildrenIterator it = (patron.begin()); it
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
	list<Node *> * node = new list<Node *>();
	for (CompositeMarkupNode::ChildrenIterator it = (noeud.begin()); it
			!= (noeud.end()); it++)
	{
		node->push_back(&AnalyserNoeud(**it));
	}

	return *node;
} //----- Fin de Recopier

Node & TransformerVisitor::RechercherTemplate(const Node & noeudXML)
{

}

void TransformerVisitor::creerMap(const Node& noeudXSL )
{
	/*std::string key = noeudXSL.;
	map.*/
}

} // namespace xsl

//------------------------------------------------------- Méthodes privées
