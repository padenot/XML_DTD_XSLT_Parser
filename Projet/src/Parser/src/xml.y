%{
	#include <cstring>
	#include <string>
	#include <cstdio>
	#include <cstdlib>
	#include <unistd.h>
	#include "commun.h"

	#include <list>
	#include <map>

	#include "Node.hh"
	#include "TextNode.hh"
	#include "MarkupNode.hh"
	#include "CompositeMarkupNode.hh"

	using namespace std;
	using namespace xml;

	#include "xml.tab.h"

	void xmlerror(char *msg);
	int xmlwrap(void);
	int xmllex(void);

	int handleDTD(char*);
	//MarkupNode* handleElement(CompositeMarkupNode** , string , string , CompositeMarkupNode::Attributes , CompositeMarkupNode::Children* );


	CompositeMarkupNode* root;
	CompositeMarkupNode** proxyPtr;
%}

%error-verbose
%union {
	char * s;
	ElementName* EName;
	xml::Node* element;
	xml::MarkupNode::Attributes* attributes;
	xml::CompositeMarkupNode::Children* children;
}

%token EQ SLASH CLOSE END CLOSESPECIAL DOCTYPE
%token <s> ENCODING VALUE DATA COMMENT NAME NSNAME
%token <EName> NSSTART START STARTSPECIAL
%type <element> element empty_element composite_element
%type <attributes> attributes
%type <children> content
%%
document 	: dtd_declarations element misc_seq_opt
			;

dtd_declarations	: /*EMPTY*/
					| dtd_declaration
					;

dtd_declaration	: DOCTYPE NAME NAME VALUE CLOSE
				{
					// TODO
					delete $2;
					delete $3;
					delete $4;
				}
				;

element		: empty_element
				{$$ = $1;}
			| composite_element
				{$$ = $1;}
			;

misc_seq_opt 	: /*empty*/
				| misc_seq_opt misc
				;
misc 		: COMMENT
				{delete $1;}
			;

empty_element	: START attributes SLASH CLOSE
				{
					$$ = new MarkupNode(proxyPtr, $1->first, $1->second, $2);
					delete $1;
					delete $2;
				}
				;

composite_element	: START attributes CLOSE content END NAME CLOSE
					{
						$$ = new CompositeMarkupNode(proxyPtr, $1->first, $1->second, $2,
						$4);
						delete $1;
						delete $2;
						delete $4;
					}
			;

attributes		: attributes NAME EQ VALUE
				{
					$1->insert(pair<string,string>($2,$4));
					$$ = $1;
					delete $2;
					delete $4;
				}
				| /* EMPTY */
					{$$ = new MarkupNode::Attributes();}
				;

content			: content DATA
				{
					$1->push_back(new TextNode($2));
					$$ = $1;
					delete $2;
				}
				| content element
					{$1->push_back($2); $$ = $1;}
				| content misc
					{$$ = $1}
				| /* empty */
					{$$ = new CompositeMarkupNode::Children();}
			;
%%
int xmlwrap(void) { return 1; }
void xmlerror(char *msg) { fprintf(stderr, "%s\n", msg); }
