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
	const std::string ns = "ns";
	const std::string element1 = "note";
	const std::string element2 = "to";
	const std::string att1 = "type";
	const std::string att2 = "truc";
	
	DTD * dtd = new DTD();
	//elements
/*	
	ElementReference * elementRef1 ElementReference( *dtd, ns, att1);
	ElementReference * elementRef2 ElementReference( *dtd, ns, att2);	
	OrderedContent list = 
	Sequence * seq = new Sequence();
	Sequence(const OrderedContent & embeddedContent);
	
	dtd.addElement(ns, element1, );
	dtd.addElement(ns, element2, );
	*/
	//attributs
	return dtd;
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

