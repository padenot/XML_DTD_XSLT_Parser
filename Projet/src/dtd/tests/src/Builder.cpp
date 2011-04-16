/*************************************************************************
 * Builder  -  «Description»
 * -------------------
 * Début      : 15 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Réalisation de la classe <Builder> (fichier Builder.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "Builder.hh"
using namespace xml;

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Builder::releaseTrees(list<Node*> trees)
{
	for (list<Node*>::iterator it = trees.begin(); it != trees.end(); ++it)
	{
		delete *it;
	}
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Builder::Builder()
{
	// Ne fait rien.
}

Builder::~Builder()
{
	// Ne fait rien.
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
string Builder::ns(unsigned int offset)
{
	static const size_t NS_SIZE = 3;
	static const string NS[NS_SIZE] = { "ns1", "NS2", "ns34misc" };
	return NS[offset % NS_SIZE];
}

string Builder::name(unsigned int offset)
{
	static const size_t NAME_SIZE = 10;
	static const string NAME[NAME_SIZE] = { "document", "markup1", "markup2",
			"markup3", "markup4", "markup5", "markup6", "markup7", "markup8",
			"markup9" };
	return NAME[offset % NAME_SIZE];
}

string Builder::attname(unsigned int offset)
{
	static const size_t ATTNAME_SIZE = 4;
	static const string ATTNAME[ATTNAME_SIZE] = { "length", "value", "bold",
			"style" };
	return ATTNAME[offset % ATTNAME_SIZE];
}

string Builder::attval(unsigned int offset)
{
	static const size_t ATTVAL_SIZE = 4;
	static const string ATTVAL[ATTVAL_SIZE] = { "10", "34pt", "yes",
			"{background-color:red;display:block;}" };
	return ATTVAL[offset % ATTVAL_SIZE];
}

string Builder::text(unsigned int offset)
{
	static const size_t TEXT_SIZE = 4;
	static const string
			TEXT[TEXT_SIZE] =
					{
							"01 Lorem ipsum dolor sit amet, consectetur adipiscing elit.",
							"02 Vivamus dignissim facilisis nisi quis hendrerit.",
							"03 Donec auctor nisi id justo eleifend et mollis ante cursus.",
							"04 Vivamus velit ipsum, eleifend eget ornare eget, sagittis nec sem." };
	return TEXT[offset % TEXT_SIZE];
}
