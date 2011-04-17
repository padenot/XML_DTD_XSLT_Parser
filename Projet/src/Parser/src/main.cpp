#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>

#include "Node.hh"
#include "MarkupNode.hh"
#include "OutputVisitor.hh"
#include "DotOutputVisitor.hh"

#include "DTD.hh"
#include "OutputDTDVisitor.hh"

using namespace std;
using namespace dtd;
using namespace xml;

int xmlparse(void);
int dtdparse(void);

extern MarkupNode* root;
extern string dtdName;
extern string validRootName;
extern DTD* rootDTD;

extern FILE * xmlin;
extern FILE * dtdin;

int exportMode;

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

	if (exportMode)
	{
		dtd::OutputDTDVisitor visitor(cout, '\t');
		rootDTD->accept(visitor);
	}

	if (err != 0)
		cout << err << " erreurs de syntaxe détectées !" << endl;
	else if (!exportMode)
		cout << "Aucune erreur détectée." << endl;

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

	exportMode = (argc == 3);

	FILE* inputFile = (FILE*) fopen(argv[1], "r");
	if (!exportMode)
		cout << "** Parsing de " << argv[1] << "..." << endl;
	if (inputFile == NULL)
	{
		cout << "Fichier inexistant." << endl;
		exit(1);
	}

	xmlin = inputFile;
	err = xmlparse();
	fclose(xmlin);

	if (err != 0)
		cout << err << " erreurs de syntaxe détectées !" << endl;
	else
	{
		if (!exportMode)
		{
			cout << "Aucune erreur détectée." << endl;
		}
		else
		{
			DotOutputVisitor dvisitor(cout, "xmlTree");
			//		dvisitor.writeDot(root);

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
					cout << "Fichier XML valide" << endl;
				else
					cout << "Fichier XML invalide" << endl;
			}

			//delete rootDTD;
			//rootDTD = 0;
		}

		delete root;
		root = 0;
	}

	if (validationResult)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}
