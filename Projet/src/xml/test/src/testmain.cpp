/*************************************************************************
 * testmain  -  Fichier principal de test.
 * -------------------
 * Début      : mar. 05 avril 2011 15:51:26 CEST
 * Auteur(s)  : H4215
 *************************************************************************/

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include<iostream>
#include<iomanip>
#include<sstream>

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
	const string NS_INIT("ns#");
	const string NAME_INIT("name#");
	const string ATTR_INIT("attr#");
	const string VAL_INIT("val#");
	const string TEXT_INIT("Ceci est un texte anticonstitutionnel et verbeux. #");

	CompositeMarkupNode** parent = new CompositeMarkupNode*;
	CompositeMarkupNode::Children children;
	MarkupNode::Attributes attributes;

	for (int i = 0; i < 4; ++i)
	{
		if (i % 2 == 0)
		{
			ostringstream ns;
			ostringstream name;
			ns << NS_INIT << i;
			name << NAME_INIT << i;
			children.push_back(new MarkupNode(*parent, ns.str(), name.str(),
					attributes));
		} else
		{
			ostringstream text;
			text << TEST_INIT << i;
			children .push_back(new TextNode(*parent, text.str()));
		}
	}
	CompositeMarkupNode** rootParent = new CompositeMarkupNode*;
	*rootParent = 0;
	return new CompositeMarkupNode(*rootParent, "rootns", "root", attributes,
			*rootParent, children);
}

bool test01()
{
	Node* root = buildTree();
	OutputVisitor visitor(cout);
	root->accept(visitor);
	return true;
}

int main()
{
	return !test01();
}

