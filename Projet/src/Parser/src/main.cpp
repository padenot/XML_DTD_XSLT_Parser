#include <unistd.h>
#include <cstring>
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

int xmlparse(MarkupNode *& root, string & dtdName, string & validRootName);
int dtdparse(DTD & rootDTD);

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

void xmlerror(MarkupNode *&, string &, string &, char *msg)
{
	cerr << "Erreur : " << msg << endl;
}

void dtderror(DTD & rootDTD, char* msg)
{
	cerr << "Erreur : " << msg << endl;
}
/**********************************************************************************/
static int loadXML(string filename, MarkupNode *& root, string & dtdName,
		string & validRootName)
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
		err = xmlparse(root, dtdName, validRootName);
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

static int loadDTD(string filename, DTD & rootDTD)
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
		err = dtdparse(rootDTD);
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

void print_help(ostream & out = cout)
{
	out << "Usage : [-xedcv] [-k <dtd_file>] [-t <xslt_file>] <xml_file>"
			<< endl << endl;

	out
			<< "  -x				affiche à la ligne de commande le fichier XML parser"
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

static bool checkXML_impl(Node & root, const string & dtdName,
		const string & validRootName)
{
	bool result = false;

	if (dtdName.empty())
	{
		result = false;
	}
	else
	{
		DTD rootDTD;
		if (loadDTD(dtdName, rootDTD) != 0)
		{
			result = false;
		}
		else
		{
			if (rootDTD.isValid(root, validRootName))
			{
				result = true;
			}
			else
			{
				result = false;
			}
		}
	}

	return result;
}

static int checkXML(string xmlPath)
{
	MarkupNode * root;
	string dtdName;
	string validRootName;

	int result = -1;

	if (loadXML(xmlPath, root, dtdName, validRootName) != 0)
	{
		result = -1;
	}
	else
	{
		if (doTrace)
			cerr << "Validation DTD..." << endl;
		if (checkXML_impl(*root, dtdName, validRootName))
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

	delete root;

	return result;
}

static int exportXML(string xmlPath)
{
	MarkupNode * root;
	string dtdName;
	string validRootName;
	int result = -1;

	if (loadXML(xmlPath, root, dtdName, validRootName) != 0)
	{
		result = -1;
	}
	else
	{
		OutputVisitor visitor(cout, ' ');
		root->accept(visitor);
		result = 0;
	}

	delete root;

	return result;
}

static int exportXMLDot(string xmlPath)
{
	MarkupNode * root;
	string dtdName;
	string validRootName;

	int result = -1;

	if (loadXML(xmlPath, root, dtdName, validRootName) != 0)
	{
		result = -1;
	}
	else
	{
		DotOutputVisitor visitor(cout, "xmlTree");
		visitor.writeDot(root);
		result = 0;
	}

	delete root;

	return result;
}

static int exportDTD(string dtdPath)
{
	DTD rootDTD;
	int result = -1;

	if (loadDTD(dtdPath, rootDTD) != 0)
	{
		result = -1;
	}
	else
	{
		OutputDTDVisitor visitor(cout);
		rootDTD.accept(visitor);
		result = 0;
	}

	return result;
}

static int transform(string xmlPath, string xsltPath)
{
	MarkupNode * xmlRoot = 0, *xsltRoot = 0;
	string xmlDtdName, xsltDtdName;
	string validXmlRootName, validXsltRootName;
	int result = -1;

	if (loadXML(xsltPath, xsltRoot, xsltDtdName, validXsltRootName) != 0
	/* TODO || !checkXML_impl(dtdName) */)
	{
		if (doTrace)
			cerr << "Erreur : XSLT non utilisable." << endl;
		result = -1;
	}
	else
	{
		if (loadXML(xmlPath, xmlRoot, xmlDtdName, validXmlRootName) != 0)
		{
			result = -1;
		}
		else
		{
			Node* transformed = 0;
			TransformerVisitor transformer(*xsltRoot);
			OutputVisitor visitor(cout, ' ');
			transformed = transformer.Transformation(*xmlRoot);
			transformed->accept(visitor);
			delete transformed;
			result = 0;
		}
	}

	delete xsltRoot;
	delete xmlRoot;

	return result;
}

/**********************************************************************************/

int main(int argc, char** argv)
{
	int result = -1;
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
			print_help(cout);
			return 0;
		case 'x':
			doExportXML = true;
			break;
		case 'e':
			doExportXMLDot = true;
			break;
		case 'd':
			doExportDTD = true;
			break;
		case 't':
			doTransform = true;
			xsltPath.assign(optarg);
			break;
		case 'c':
			doCheckXML = true;
			break;
		case 'k':
			doCheckDTD = true;
			dtdPath.assign(optarg);
		case 'v':
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
			result = checkXML(xmlPath);
		}
		if (doExportXML)
		{
			result = exportXML(xmlPath);
		}
		if (doExportXMLDot)
		{
			result = exportXMLDot(xmlPath);
		}
		if (doExportDTD)
		{
			result = exportDTD(dtdPath);
		}
		if (doTransform)
		{
			result = transform(xmlPath, xsltPath);
		}
	}
	else
	{
		print_help(cerr);
	}

	return result;
}
