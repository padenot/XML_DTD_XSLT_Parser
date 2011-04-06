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
#include "OutputDTDVisitor.hh"
#include "DTD.hh"
#include "Element.hh"
#include "AttributesList.hh"
#include "EmptyContent.hh"
#include "MixedContent.hh"
#include "ElementReference.hh"
#include "Choice.hh"
#include "Sequence.hh"
#include "OptionalContent.hh"
#include "RepeatableContent.hh"
#include "RepeatedContent.hh"
using namespace xml;
using namespace dtd;

//------------------------------------------------------------- Constantes

//-------------------------------------------------------------- Fonctions
DTD* buildDTD()
{
	const string NS_INIT("__ns");
	const string NAME_INIT("__name");
	const string ATTR_INIT("__attr");
	const string VAL_INIT("__val");
	const string TEXT_INIT(
			"__Ceci est un texte anticonstitutionnel et verbeux.");

	DTD & dtd = *new DTD();

	for (int i = 0; i < 4; ++i)
	{
		if (i % 2 == 0)
		{
			ostringstream ns(NS_INIT);
			ostringstream name(NAME_INIT);

			ns << setw(2) << i;
			name << setw(2) << i;

			dtd.addElement(
					*new Element(dtd, ns.str(), name.str(), *new EmptyContent()));
		} else
		{

		}
	}

	return &dtd;
}

bool test01()
{
	DTD* dtd = buildDTD();
	OutputDTDVisitor visitor(cout);
	dtd->accept(visitor);
	delete dtd;
	return true;
}

int main()
{
	return !test01();
}

