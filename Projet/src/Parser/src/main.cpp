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

static bool doCheckXML = false;
static bool doExportXML = false;
static bool doExportXMLDot = false;
static bool doExportDTD = false;
static bool doTransform = false;
static bool doTrace = false;
static bool doCheckDTD = false;

void xmlerror(char* msg)
{
	cerr << "Erreur : " << msg << endl;
}

void dtderror(char* msg)
{
	cerr << "Erreur: " << msg << endl;
}
/**********************************************************************************/
static int loadXML(string filename)
{
	int err;
	FILE* inputFile = (FILE*) fopen(filename.c_str(), "r");
	if (doTrace)
		cout << "Chargement de " << filename << "..." << endl;
	if (inputFile == NULL)
	{
		if (doTrace)
			cerr << "Fichier XML inaccessible." << endl;
		err = 1;
	}
	else
	{
		xmlin = inputFile;
		err = xmlparse();
		fclose(xmlin);

		if (xmlSyntaxErrorCount != 0)
		{
			if (doTrace)
			{
				cerr << "XML mal formé : " << xmlSyntaxErrorCount
						<< " erreurs de syntaxe détectées." << endl;
			}
			err = 1;
		}
		else if (doTrace)
		{
			if (err != 0)
			{
				cerr << "Erreur lors de l'analyse du XML." << endl;
			}
			else
			{
				cerr << "Analyse du XML OK." << endl;
			}
		}
	}

	return err;
}

static int loadDTD(string filename)
{
	int err;
	FILE* inputFile = (FILE*) fopen(filename.c_str(), "r");
	if (doTrace)
		cout << "Chargement de " << filename << "..." << endl;
	if (inputFile == NULL)
	{
		if (doTrace)
			cout << "Fichier DTD inaccessible." << endl;
		err = 1;
	}
	else
	{
		dtdin = inputFile;
		err = dtdparse();
		fclose(dtdin);

		if (doTrace)
		{
			if (err != 0)
			{
				cerr << "Erreur lors de l'analyse de la DTD." << endl;
			}
			else
			{
				cerr << "Analyse de la DTD OK." << endl;
			}
		}
	}

	return err;
}

/**********************************************************************************/
static void cleanXML()
{
	dtdName.clear();
	validRootName.clear();
	xmlSyntaxErrorCount = 0;
	delete root;
	root = 0;
}

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

static void cleanDTD()
{
	delete rootDTD;
	rootDTD = 0;
}

static bool checkXML_impl()
{
	bool result = false;

	if (dtdName.empty())
	{
		result = false;
	}
	else
	{
		if (loadDTD(dtdName) != 0)
		{
			result = false;
		}
		else
		{
			if (rootDTD->isValid(*root, validRootName))
			{
				result = true;
			}
			else
			{
				result = false;
			}
		}
	}

	cleanDTD();
	return result;
}

static int checkXML(string xmlPath)
{
	int result = -1;

	if (loadXML(xmlPath) != 0)
	{
		result = -1;
	}
	else
	{
		if (doTrace)
			cerr << "Validation DTD..." << endl;
		if (checkXML_impl())
		{
			if (doTrace)
				cerr << "Validation DTD : OK." << endl;
			result = 0;
		}
		else
		{
			if (doTrace)
				cerr << "Validation DTD : FAIL." << endl;
			result = -1;
		}
	}

	cleanXML();
	cleanDTD();

	return result;
}

static int exportXML(string xmlPath)
{
	int result = -1;

	if (loadXML(xmlPath) != 0)
	{
		result = -1;
	}
	else
	{
		OutputVisitor visitor(cout, ' ');
		root->accept(visitor);
		result = 0;
	}

	cleanXML();

	return result;
}

static int exportXMLDot(string xmlPath)
{
	int result = -1;

	if (loadXML(xmlPath) != 0)
	{
		result = -1;
	}
	else
	{
		DotOutputVisitor visitor(cout, "xmlTree");
		visitor.writeDot(root);
		result = 0;
	}

	cleanXML();

	return result;
}

static int exportDTD(string dtdPath)
{
	int result = -1;

	if (loadDTD(dtdPath) != 0)
	{
		result = -1;
	}
	else
	{
		OutputDTDVisitor visitor(cout);
		rootDTD->accept(visitor);
		result = 0;
	}
	cleanDTD();

	return result;
}

static int transform(string xmlPath, string xsltPath)
{
	int result = -1;

	if (loadXML(xsltPath) != 0/* TODO || !checkXML_impl(dtdName) */)
	{
		if (doTrace)
			cerr << "Erreur : XSLT non utilisable." << endl;
		result = -1;
	}
	else
	{
		Node* xslRoot = root;
		root = 0;
		dtdName.clear();
		validRootName.clear();

		if (loadXML(xmlPath) != 0)
		{
			delete xslRoot;
			result = -1;
		}
		else
		{
			Node* transformed = 0;
			TransformerVisitor transformer(*xslRoot);
			OutputVisitor visitor(cout, ' ');
			transformed = transformer.Transformation(*root);
			transformed->accept(visitor);
			delete xslRoot;
			delete transformed;
			result = 0;
		}
	}

	cleanXML();

	return result;
}

/**********************************************************************************/

int main(int argc, char** argv)
{
	int result;
	string xmlPath;
	string dtdPath;
	string xsltPath;

	int opt;

	// pas d'argument
	if (argc == 1)
	{
		cerr
				<< "<you>\n\t<are>\n\t\t<stupide?>true</stupide?>\n\t</are>\n</you>"
				<< endl << endl;
		print_help(cerr);
		return 1;
	}

	while ((opt = getopt(argc, argv, "hxedt:ck:v:")) != -1)
	{
		switch (opt)
		{
		case 'h':
			cout << "-t" << endl;
			print_help(cout);
			return 0;
		case 'x':
			cout << "-x" << endl;
			doExportXML = true;
			break;
		case 'e':
			cout << "-e" << endl;
			doExportXMLDot = true;
			break;
		case 'd':
			cout << "-d" << endl;
			doExportDTD = true;
			break;
		case 't':
			cout << "-t" << endl;
			doTransform = true;
			xsltPath.assign(optarg);
			break;
		case 'c':
			cout << "-c" << endl;
			doCheckXML = true;
			break;
		case 'k':
			cout << "-k" << endl;
			doCheckDTD = true;
			dtdPath.assign(optarg);
		case 'v':
			cout << "-v" << endl;
			doTrace = true;
			break;
		case '?':
			cerr << "Invalid option" << endl;
			print_help(cerr);
		}
	}

	if (strcmp(argv[optind], "") != 0)
	{
		xmlPath.assign(argv[optind]);

		if (doCheckXML)
		{
			cout << "doCheck" << endl;
			result = checkXML(xmlPath);
		}
		if (doExportXML)
		{
			cout << "doExportXML" << endl;
			result = exportXML(xmlPath);
		}
		if (doExportXMLDot)
		{
			cout << "doExportXMLDot" << endl;
			result = exportXMLDot(xmlPath);
		}
		if (doExportDTD)
		{
			cout << "doExportDTD" << endl;
			result = exportDTD(dtdPath);
		}
		if (doTransform)
		{
			cout << "doTransform" << endl;
			result = transform(xmlPath, xsltPath);
		}
		cout << "Fin if" << endl;
	}
	else
	{
		print_help(cerr);
	}

	return result;
}
