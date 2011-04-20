#include <unistd.h>

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>

#include "Node.hh"
#include "MarkupNode.hh"
#include "OutputVisitor.hh"
#include "DotOutputVisitor.hh"
#include "TransformerVisitor.hh"

#include "DTD.hh"
#include "OutputDTDVisitor.hh"

#include "error.hh"

using namespace std;
using namespace dtd;
using namespace xml;
using namespace xsl;

int xmlparse(void);
int dtdparse(void);

extern MarkupNode* root;
extern string dtdName;
extern string validRootName;
extern DTD* rootDTD;

extern FILE * xmlin;
extern FILE * dtdin;

extern int xmllineno;
extern char* xmltext;
extern int xmlSyntaxErrorCount;

bool exportMode;
bool transformMode;

void xmlerror(char* msg)
{
}
void dtderror(char* msg)
{
	printf("Erreur");
}
/**********************************************************************************/
int handleDTD(string filename)
{
	int err;
	FILE* inputFile = (FILE*) fopen(filename.c_str(), "r");
	if (!exportMode)
		cout << "** Parsing de " << filename << "..." << endl;
	if (inputFile == NULL)
	{
		cout << "Fichier inexistant." << endl;
		exit(1);
	}

	dtdin = inputFile;
	err = dtdparse();
	fclose(dtdin);

	if (!exportMode)
	{
		dtd::OutputDTDVisitor visitor(cout, '\t');
		rootDTD->accept(visitor);
	}

	if (err != 0)
		cout << endl << "Badformed XML : " << xmlSyntaxErrorCount
				<< " syntex errors detected." << endl;
	else if (!exportMode)
		cout << endl << "Wellformed XML." << endl;

	return err;
}

/**********************************************************************************/

void print_help(ostream & out = cout)
{
	out << "Usage : <xml_file> [-xedcv] [-k <dtd_file>] [-t <xslt_file>]"
			<< endl << endl;

	out
			<< "  -x				print in the line command the XML file as it has been parsed"
			<< endl;
	out
			<< "  -e				print in the line command the XML fil as it has been parsed but in dot format"
			<< endl;
	out
			<< "  -d				print in the line command the DTD file as it has been parsed"
			<< endl;
	out << "  -t FILE			transform the xml file with the specific xslt file"
			<< endl;
	out
			<< "  -c				check the syntax of the xml and verify with the specified dtd in the xml file"
			<< endl;
	out
			<< "  -k FILE			check the syntax of the xml file and verify with the specified dtd in the command line"
			<< endl;
	out << "  -v				set verbose flag" << endl;
	out << "  -h				display this help..." << endl;
}

int main(int argc, char** argv)
{
	/* Début truc de ouf */

	int opt;

	/*
	 // no arguments given
	 */
	if (argc == 1)
	{
		cerr << "<you>\n\t<are>\n\t\t<stupide?>true</stupide?>\n\t</are>\n</you>" << endl << endl;
		print_help(cerr);
		return 1;
	}

	while ((opt = getopt(argc, argv, "hxedtckv:")) != -1)
	{
		switch (opt)
		{
		case 'h':
			print_help(cout);
			return 0;
		case 'x':
			exportMode = true;
			break;
		case 'e':
			cout << "" << endl;
			break;
		case 'd':
			cout << "" << endl;
			break;
		case 't':
			cout << "" << endl;
			break;
		case 'c':
			cout << "" << endl;
			break;
		case 'k':
			cout << "" << endl;
			break;
		case 'v':
			cout << "" << endl;
			break;
		case ':':
			cerr << "Invalid option" << endl;
			print_help(cerr);
			return 0;
		case '?':
			cerr << "Invalid option" << endl;
			print_help(cerr);
		}
	}

	/*
	 // print all remaining options
	 */
	for (; optind < argc; optind++)
		printf("argument: %s\n", argv[optind]);
	/* Fin truc de ouf*/

	if (argc < 2)
	{
		cout << "Veuillez entrez un nom de fichier." << endl;
		exit(0);
	}

	if (argc >= 3)
	{
		exportMode = (string(argv[2]) == "--export");
		transformMode = (argc >= 4 && string(argv[2]) == "--xsl");
		if (transformMode)
			exportMode = true;
	}

	FILE* inputFile = (FILE*) fopen(argv[1], "r");
	if (!exportMode)
		cout << "** Parsing de " << argv[1] << "..." << endl;
	if (inputFile == NULL)
	{
		cout << "Fichier inexistant." << endl;
		exit(1);
	}

	xmlin = inputFile;
	xmlparse();
	fclose(xmlin);

	if (xmlSyntaxErrorCount != 0)
		cout << endl << "Badformed XML : " << xmlSyntaxErrorCount
				<< " syntax errors detected." << endl;
	else
	{
		if (exportMode && !transformMode)
		{
			DotOutputVisitor dvisitor(cout, "xmlTree");
			dvisitor.writeDot(root);

		}
		else if(!exportMode && !transformMode) {
			OutputVisitor visitor(cout, ' ');
			root->accept(visitor);
		}

		if (!dtdName.empty())
		{
			err = handleDTD(dtdName);

			if (err == 0 && !exportMode)
			{
				validationResult = rootDTD->isValid(*root, validRootName);
				if (validationResult)
					cout << "DTD Validation : OK." << endl;
				else
					cout << "DTD Validation : FAIL." << endl;
			}

			delete rootDTD;
			rootDTD = 0;
		}

	}

	if (validationResult && transformMode)
	{
		Node* xmlRoot = root;
		FILE* inputFile = (FILE*) fopen(argv[3], "r");

		xmlin = inputFile;
		err = xmlparse();
		fclose(xmlin);
		if (xmlSyntaxErrorCount != 0)
		{
			cout << endl << "Badformed XSLT : " << xmlSyntaxErrorCount
					<< " syntax errors detected." << endl;
		}
		else if (!err && root != 0)
		{
			Node * xslRoot = root;
			Node* transformed = 0;
			TransformerVisitor transformer(*xslRoot);
			OutputVisitor visitor(cout, ' ');
			transformed = transformer.Transformation(*xmlRoot);
			transformed->accept(visitor);
		}
	}

	delete root;
	root = 0;

	if (validationResult && xmlSyntaxErrorCount == 0)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}
