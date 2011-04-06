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
using namespace xml;

//------------------------------------------------------------- Constantes

//-------------------------------------------------------------- Fonctions
Node* buildTree()
{
	const string NS_INIT("__ns");
	const string NAME_INIT("__name");
	const string ATTR_INIT("__attr");
	const string VAL_INIT("__val");
	const string TEXT_INIT("__Ceci est un texte anticonstitutionnel et verbeux.");

	CompositeMarkupNode** parent = new CompositeMarkupNode*;
	CompositeMarkupNode::Children children;
	MarkupNode::Attributes attributes;

	for (int i = 0; i < 4; ++i)
	{
		if (i % 2 == 0)
		{
			ostringstream ns(NS_INIT);
			ostringstream name(NAME_INIT);
			ns << setw(2) << i;
			name << setw(2) << i;
			children.push_back(new MarkupNode(*parent, ns.str(), name.str(),
					attributes));
		} else
		{
			ostringstream text(TEXT_INIT);
			text << setw(2) << i;
			children .push_back(new TextNode(*parent, text.str()));
		}
	}
	CompositeMarkupNode** rootParent = new CompositeMarkupNode*;
	*rootParent = 0;
	return new CompositeMarkupNode(*rootParent, "rootns", "root", attributes,
			*parent, children);
}

bool test01()
{
	Node* root = buildTree();
	OutputVisitor visitor(cout);
	root->accept(visitor);
	delete root;
	return true;
}

int main()
{
	return !test01();
}

