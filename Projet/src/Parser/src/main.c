#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>

#include "Node.hh"
#include "TextNode.hh"
#include "MarkupNode.hh"
#include "CompositeMarkupNode.hh"
#include "OutputVisitor.hh"

int xmlparse(void);
int dtdparse(void);

extern xml::CompositeMarkupNode* root;

extern FILE * xmlin;
extern FILE * dtdin;

using namespace std;

int handleDTD(char* filename) {
	int err;
	FILE* inputFile = (FILE*)fopen(filename, "r");
	cout << "** Parsing de " << filename << "..." << endl;
	if(inputFile == NULL) {
		cout << "Fichier inexistant." << endl;
		exit(1);
	}

	dtdin = inputFile;	
	err = dtdparse();
	fclose(dtdin);

	if (err != 0) cout << err << " erreurs de syntaxe détectées !" << endl; 
	else cout << "Aucune erreur détectée." << endl; 

	return 0;
}

xml::CompositeMarkupNode* handleElement(xml::CompositeMarkupNode** proxy, string NS, string name, xml::CompositeMarkupNode::Attributes attributes, list<void*>* children) {
	xml::CompositeMarkupNode::Children currentChildren
		=  *((list<xml::Node*>*)children);

	xml::CompositeMarkupNode** newProxy 
		= new xml::CompositeMarkupNode*; newProxy = 0;

	return  new xml::CompositeMarkupNode(newProxy, NS, name, attributes, *proxy, currentChildren);
}

int main(int argc, char** argv) {
	int err;

	if(argc < 2){
		cout << "Veuillez entrez un nom de fichier." << endl;
		exit(0);
	}

	FILE* inputFile = (FILE*)fopen(argv[1], "r");
	cout << "** Parsing de " << argv[1] << "..." << endl;
	if(inputFile == NULL) {
		cout << "Fichier inexistant." << endl;
		exit(1);
	}

	xmlin = inputFile;	
	err = xmlparse();
	fclose(xmlin);

	xml::OutputVisitor visitor(cout);
	root->accept(visitor);

	if (err != 0) cout << err << " erreurs de syntaxe détectées !" << endl; 
	else cout << "Aucune erreur détectée." << endl; 

	return 0;
}
