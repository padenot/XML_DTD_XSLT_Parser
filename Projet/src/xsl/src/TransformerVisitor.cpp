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

namespace xml
{
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
TransformerVisitor::TransformerVisitor()
{
	templatesMap = new map();
	// Rien à faire
} //----- Fin de OutputVisitor


TransformerVisitor::~TransformerVisitor()
{
	delete templatesMap;
	// Rien à faire
} //----- Fin de ~OutputVisitor


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void TransformerVisitor::creerMap(const Node& node)
{
	node.accept(*this);
}

void TransformerVisitor::getTemplateName(const MarkupNode& node)
{
	for (MarkupNode::AttributesIterator it = node.begin(); it != node.end(); ++it)
	{
		if (it->first == "match")
		{
			(*templatesMap)[it->second] = &node;
		}
	}
} //----- Fin de writeAttributes

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

//------------------------------------------------------- Méthodes privées

} // namespace xml
