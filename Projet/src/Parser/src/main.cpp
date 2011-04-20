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

void xmlerror(char* msg) {  }
void dtderror(char* msg) { printf("Erreur"); }
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

	if (err != 0) cout << endl << "Badformed XML : " << xmlSyntaxErrorCount << " syntex errors detected." << endl;
	else if (!exportMode) cout << endl << "Wellformed XML." << endl;

	return 0;
}

/**********************************************************************************/

int main(int argc, char** argv)
{
	int err;
	bool validationResult = true;

	if (argc < 2)
	{
		cout << "Veuillez entrez un nom de fichier." << endl;
		exit(0);
	}

	if (argc >= 3)
	{
		exportMode = (string(argv[2]) == "--export");
		transformMode = (argc >= 4 && string(argv[2]) == "--xsl");
		if(transformMode) exportMode = true;
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

	if (xmlSyntaxErrorCount != 0) cout << endl << "Badformed XML : " << xmlSyntaxErrorCount << " syntax errors detected." << endl;
	else
	{
		if (exportMode && !transformMode )
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
			handleDTD(dtdName);

			if (err == 0 && !exportMode)
			{
				validationResult = rootDTD->isValid(*root, validRootName);
				if (validationResult)
					cout << "DTD Validation : OK." << endl;
				else
					cout << "DTD Validation : FAIL." << endl;
			}

			//delete rootDTD;
			//rootDTD = 0;
		}

	}

	if (validationResult && transformMode)
	{
		Node* xmlRoot = root;
		FILE* inputFile = (FILE*) fopen(argv[3], "r");

		xmlin = inputFile;
		err = xmlparse();
		fclose(xmlin);

		if (!err && root != 0)
		{
			Node * xslRoot = root;
			Node* transformed = 0;
			TransformerVisitor transformer(*xslRoot);
			OutputVisitor visitor(cout,' ');
			transformed = transformer.Transformation(*xmlRoot);
			transformed->accept(visitor);
		}
	}

	delete root;
	root = 0;

	if (validationResult)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}
