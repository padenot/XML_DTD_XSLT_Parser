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
#include "OutputVisitor.hh"
#include "OutputDTDVisitor.hh"
#include "DTD.hh"
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

#include "Builder.hh"
#include "TrivialBuilder.hh"
#include "SimpleBuilder.hh"

//------------------------------------------------------------- Constantes
const string RESULT_OK = ": ok";
const string RESULT_FAIL = ": FAIL !";
const string MAJOR_SEP =
		"=================================================================";
const string MINOR_SEP =
		"------------------------------------------------------------";

//-------------------------------------------------------------- Fonctions
static bool test(ostream& out, unsigned int testNumber, Builder& builder)
{
	int count;
	bool failed = false;
	OutputDTDVisitor outputDTD(cout);
	OutputVisitor outputNode(cout);
	DTD* dtd = new DTD();
	list<Node*> validTrees = builder.buildValidTrees();
	list<Node*> invalidTrees = builder.buildInvalidTrees();

	out << MAJOR_SEP << endl << "Starting test #" << setw(3) << testNumber
			<< endl << MINOR_SEP << endl;

	builder.buildDTD(*dtd);

	dtd->accept(outputDTD);

	count = 1;
	for (list<Node*>::iterator it = validTrees.begin(); it != validTrees.end(); ++it)
	{
		//(*it)->accept(outputNode);
		out << setw(15) << "Valid node #" << setw(3) << count;
		if (dtd->isValid(**it))
		{
			out << RESULT_OK << endl;
		}
		else
		{
			out << RESULT_FAIL << endl;
			failed = true;
		}
		++count;
	}

	count = 1;
	for (list<Node*>::iterator it = invalidTrees.begin(); it
			!= invalidTrees.end(); ++it)
	{
		//(*it)->accept(outputNode);
		out << setw(15) << "Invalid node #" << setw(3) << count;
		if (dtd->isValid(**it))
		{
			out << RESULT_FAIL << endl;
			failed = true;
		}
		else
		{
			out << RESULT_OK << endl;
		}
		++count;
	}

	out << "TEST #" << setw(3) << testNumber;
	if (failed)
	{
		out << ": FAILURE";
	}
	else
	{
		out << ": ok";
	}
	out << endl;

	delete dtd;
	Builder::releaseTrees(invalidTrees);
	Builder::releaseTrees(validTrees);

	return !failed;
}

static bool test01(ostream& out)
{
	TrivialBuilder builder;
	return test(out, 1, builder);
}

static bool test02(ostream& out)
{
	SimpleBuilder builder;
	return test(out, 2, builder);
}

int main()
{
	if (test01(cout) && test02(cout))
		return 0;
	else
		return -1;
}

