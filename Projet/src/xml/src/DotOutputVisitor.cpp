/*************************************************************************
 * DotOutputVisitor
 * -------------------
 * Début      : mar. 05 avril 2011 14:37:55 CEST
 * Auteur(s)  : H4215
 *************************************************************************/

//---- Réalisation de la classe <DotOutputVisitor> (fichier DotOutputVisitor.cpp) ----

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <iomanip>

//------------------------------------------------------ Include personnel
#include "DotOutputVisitor.hh"
#include "TextNode.hh"
#include "MarkupNode.hh"
#include "CompositeMarkupNode.hh"

namespace xml
{
//------------------------------------------------------------- Constantes
const std::string DotOutputVisitor::GRAPH_TYPE = "digraph";
const std::string DotOutputVisitor::LINK = " -> ";


//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type DotOutputVisitor::Méthode ( liste de paramètres )
// Algorithme :
//	«TODO»
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
DotOutputVisitor::DotOutputVisitor(ostream & out, std::string filename) :
	_out(out), _document(filename)
{
	// Rien à faire
	textNodesCount = 0;
} //----- Fin de DotOutputVisitor


DotOutputVisitor::~DotOutputVisitor()
{
	// Rien à faire
} //----- Fin de ~DotOutputVisitor


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void DotOutputVisitor::writeAttributes(const MarkupNode& node)
{/*
	for (MarkupNode::AttributesIterator it = node.begin(); it != node.end(); ++it)
	{
		_out << INSIDE_MARKUP_SPACE_STR << it->first
				<< ASSIGN_ATTRIBUTE_VALUE_STR << OPEN_ATTRIBUTE_VALUE_STR
				<< it->second << CLOSE_ATTRIBUTE_VALUE_STR;
	}*/
} //----- Fin de writeAttributes

void DotOutputVisitor::writeDot(Node * node)
{
	_out << "digraph " << _document << " {" << endl ;
	node->accept(*this);
	_out << "}" << endl;
	
}

void DotOutputVisitor::visit(const TextNode& node)
{
	_out << "\"textNode"<< textNodesCount << "\"";//node.content() << endl;
	textNodesCount++;

}

void DotOutputVisitor::visit(const MarkupNode& node)
{
	_out << '"' << node.name() << '"';
	a [label="Foo"];
	//writeAttributes(node);
}

void DotOutputVisitor::visit(const CompositeMarkupNode& node)
{
	for (CompositeMarkupNode::ChildrenIterator it = node.begin(); it
			!= node.end(); ++it)
	{
		_out << '"' << node.name() << '"'<< LINK;
		(*it)->accept(*this);
		_out << endl;
	}
}

//------------------------------------------------------- Méthodes privées

} // namespace xml
