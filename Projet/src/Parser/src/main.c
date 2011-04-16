#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>

#include "Node.hh"
#include "TextNode.hh"
#include "MarkupNode.hh"
#include "CompositeMarkupNode.hh"
#include "OutputVisitor.hh"
#include "OutputDTDVisitor.hh"
#include "DotOutputVisitor.hh"
#include "DTD.hh"

#include "Content.hh"
#include "ElementContent.hh"
#include "QuantifiableContent.hh"
#include "RepeatedContent.hh"
#include "RepeatableContent.hh"
#include "OptionalContent.hh"

#define QTF_AST		1
#define QTF_PLUS	2
#define QTF_QMARK	4
#define QTF_NONE	0

int xmlparse(void);
int dtdparse(void);

extern xml::CompositeMarkupNode* root;
extern std::string* dtdName;
extern dtd::DTD* rootDTD;

extern FILE * xmlin;
extern FILE * dtdin;

int exportMode;

using namespace std;

/**********************************************************************************/
int handleDTD(string filename) {
	int err;
	FILE* inputFile = (FILE*)fopen(filename.c_str(), "r");
	if(!exportMode) cout << "** Parsing de " << filename << "..." << endl;
	if(inputFile == NULL) {
		cout << "Fichier inexistant." << endl;
		exit(1);
	}

	dtdin = inputFile;	
	err = dtdparse();
	fclose(dtdin);

	if(exportMode) {
		dtd::OutputDTDVisitor visitor(cout, '\t');
		rootDTD->accept(visitor);
	}


	if (err != 0) cout << err << " erreurs de syntaxe détectées !" << endl; 
	else if(!exportMode) 
		cout << "Aucune erreur détectée." << endl; 

	return 0;
}

dtd::QuantifiableContent* handleQuantifier(dtd::QuantifiableContent* currentContent, int quantifier) {
	switch(quantifier) {
		case (QTF_NONE): return currentContent;
		case (QTF_PLUS): return new dtd::RepeatedContent(*currentContent);
		case (QTF_AST): return new dtd::RepeatableContent(*currentContent);
		case (QTF_QMARK): return new dtd::OptionalContent(*currentContent);
	}
}

/**********************************************************************************/

int main(int argc, char** argv) {
	int err;

	if(argc < 2){
		cout << "Veuillez entrez un nom de fichier." << endl;
		exit(0);
	}

	exportMode = (argc == 3);

	FILE* inputFile = (FILE*)fopen(argv[1], "r");
	if(!exportMode) cout << "** Parsing de " << argv[1] << "..." << endl;
	if(inputFile == NULL) {
		cout << "Fichier inexistant." << endl;
		exit(1);
	}

	xmlin = inputFile;	
	err = xmlparse();
	fclose(xmlin);

	if(exportMode) {
		xml::DotOutputVisitor dvisitor(cout, "xmlTree");
//		dvisitor.writeDot(root);

		xml::OutputVisitor visitor(cout, ' ');
		root->accept(visitor);
	}

	if (err != 0) cout << err << " erreurs de syntaxe détectées !" << endl; 
	else if(!exportMode) cout << "Aucune erreur détectée." << endl; 

	if (dtdName != 0)
	{
		handleDTD(*dtdName);
		if(rootDTD->isValid(*root)) cout << "Fichier XML valide" << endl;
		else cout << "Fichier XML invalide" << endl;
	}

	delete root;
	root = 0;
	delete rootDTD;
	rootDTD = 0;

	return 0;
}
