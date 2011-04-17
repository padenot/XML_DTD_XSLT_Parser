/*************************************************************************
 * MapCreator  -  Description
 * -------------------
 * Début      : 15 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Réalisation de la classe <MapCreator> (fichier MapCreator.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système


//------------------------------------------------------ Include personnel
#include "MapCreator.hh"

using namespace xml;
using namespace std;

namespace xsl
{
//------------------------------------------------------------- Constantes

static const string TEMPLATE = "template";

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type MapCreator::Méthode ( liste des paramètres )
// Algorithme :
//	
//{
//}
void MapCreator::populateMap(const Node& xslTree)
{
	xslTree.accept(*this);
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
MapCreator::MapCreator(map<string, const CompositeMarkupNode *> * theMap) :
	mapTemp(theMap)
{
}

MapCreator::~MapCreator()
{
	// on ne fait rien car on ne veut pas d�truire la map qui est utilis�e apr�s.
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void MapCreator::visit(const TextNode&)
{
	// Dans le type de fichier xsl que nous gérons il n'est pas nécessaire
	// de gérer ce type de Noeud
}

void MapCreator::visit(const MarkupNode&)
{
	// Dans le type de fichier xsl que nous gérons il n'est pas nécessaire
	// de gérer ce type de Noeud
}

void MapCreator::visit(const CompositeMarkupNode& node)
{

	if (node.name() == TEMPLATE)
	{
		checkTemplate(node);
	}

	for (CompositeMarkupNode::ChildrenIterator itNoeud = node.begin(); itNoeud
			!= node.end(); ++itNoeud)
	{
		(*itNoeud)->accept(*this);
	}

}

void MapCreator::checkTemplate(const CompositeMarkupNode& node)
{
	for (MarkupNode::AttributesIterator itAttribut = node.MarkupNode::begin(); itAttribut
			!= node.MarkupNode::end(); ++itAttribut)
	{
		if (itAttribut->first == "match")
		{
			(*mapTemp)[itAttribut->second] = &node;
		}
	}
}

} // namespace xsl
