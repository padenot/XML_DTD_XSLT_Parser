/*************************************************************************
 * testmain  -  Fichier principal de test.
 * -------------------
 * Début      : mar. 05 avril 2011 15:51:26 CEST
 * Auteur(s)  : H4215
 *************************************************************************/

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <iomanip>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "Node.hh"
#include "TextNode.hh"
#include "MarkupNode.hh"
#include "CompositeMarkupNode.hh"
#include "OutputVisitor.hh"
#include "XmlTreeBuilding.hh"
#include "DotOutputVisitor.hh"
using namespace xml;

//------------------------------------------------------------- Constantes

//-------------------------------------------------------------- Fonctions
static bool test01()
{
	Node* root = normalTree();
	OutputVisitor visitor(cout, '\t');
	root->accept(visitor);
	
	DotOutputVisitor dvisitor(cout, "xmltruc");
	dvisitor.writeDot(root);
	
	delete root;
	return true;
}

int main()
{
	return !test01();
}

