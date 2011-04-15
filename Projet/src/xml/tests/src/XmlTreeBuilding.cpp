/*************************************************************************
 * XmlTreeBuilding  -  Construction d'arbres XML pour tests.
 * -------------------
 * Début      : mar. 06 avril 2011 15:51:26 CEST
 * Auteur(s)  : H4215
 *************************************************************************/

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "XmlTreeBuilding.hh"
#include "TextNode.hh"
#include "MarkupNode.hh"
#include "CompositeMarkupNode.hh"
#include "OutputVisitor.hh"
using namespace xml;

//------------------------------------------------------------- Constantes

//-------------------------------------------------------------- Fonctions
static string ns(unsigned int offset = 0)
{
	static const size_t NS_SIZE = 3;
	static const string NS[NS_SIZE] = { "ns1", "NS2", "ns34misc" };
	return NS[offset % NS_SIZE];
}

static string name(unsigned int offset = 0)
{
	static const size_t NAME_SIZE = 4;
	static const string NAME[NAME_SIZE] = { "document", "markup", "aAa",
			"mixed10nAme" };
	return NAME[offset % NAME_SIZE];
}

static MarkupNode::Attributes attributes(unsigned int offset = 0,
		unsigned int count = 1)
{
	const size_t ATTR_SIZE = 4;
	const string ATTR[ATTR_SIZE] = { "attr1", "anotherAttribute",
			"AnAttribute", "attr02mixed" };

	const size_t VAL_SIZE = 4;
	const string VAL[VAL_SIZE] = { "12", "bold", "Value", "mixed12VaLue" };

	MarkupNode::Attributes attr;
	for (unsigned int i = 0; i < count; ++i, ++offset)
	{
		attr[ATTR[offset % ATTR_SIZE]] = VAL[offset % VAL_SIZE];
	}
	return attr;
}

static string text(unsigned int offset = 0)
{
	const size_t TEXT_SIZE = 4;
	const string
			TEXT[TEXT_SIZE] = {
					"01 Lorem ipsum dolor sit amet, consectetur adipiscing elit.",
					"02 Vivamus dignissim facilisis nisi quis hendrerit.",
					"03 Donec auctor nisi id justo eleifend et mollis ante cursus.",
					"04 Vivamus velit ipsum, eleifend eget ornare eget, sagittis nec sem." };
	return TEXT[offset % TEXT_SIZE];
}

//////////////////////////////////////////////////////////////
// FONCTIONS PUBLIQUES

Node* trivialTree(unsigned int offset, CompositeMarkupNode** rootParent)
{
	return new CompositeMarkupNode(rootParent, ns(offset + 0),
			name(offset + 0), attributes(offset + 2, offset + 3),
			*new CompositeMarkupNode*, CompositeMarkupNode::Children());
}

Node* simpleTree(unsigned int offset, CompositeMarkupNode** rootParent)
{
	CompositeMarkupNode** parent = new CompositeMarkupNode*;
	CompositeMarkupNode::Children children;

	for (unsigned int i = 0; i < 5 + (offset % 2); ++i)
	{
		if (i % 2 == 0)
		{
			children.push_back(new MarkupNode(parent, ns(offset + i), name(
					offset + i), attributes(offset + i + 2, i / 2)));
		}
		else
		{
			children.push_back(new TextNode(parent, text(offset + i)));
		}
	}

	return new CompositeMarkupNode(rootParent, ns(offset + 2),
			name(offset + 0), attributes(offset + 3, 2), *parent, children);
}

Node* normalTree(unsigned int offset, CompositeMarkupNode** rootParent)
{
	CompositeMarkupNode** parent = new CompositeMarkupNode*;
	CompositeMarkupNode::Children children;

	for (unsigned int i = 0; i < 5; ++i)
	{
		parent = new CompositeMarkupNode*;
		if (i % 3 == 0)
		{
			CompositeMarkupNode** nestedParent = new CompositeMarkupNode*;
			CompositeMarkupNode::Children nestedChildren;

			for (unsigned int j = 0; j < 3; ++j)
			{
				nestedChildren.push_back(simpleTree(offset + i + j,
						nestedParent));
			}
			children.push_back(new CompositeMarkupNode(parent, ns(offset + i
					+ 4), name(offset + i + 2), attributes(offset + i + 1, 3),
					*nestedParent, nestedChildren));
		}
		else
		{
			children.push_back(simpleTree(offset + i, parent));
		}
	}

	return new CompositeMarkupNode(rootParent, ns(offset + 1),
			name(offset + 3), attributes(offset + 2, 1), *parent, children);
}


