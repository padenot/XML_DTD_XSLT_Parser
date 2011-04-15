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
}

%token EQ SLASH CLOSE END CLOSESPECIAL DOCTYPE
%token <s> ENCODING VALUE DATA COMMENT NAME NSNAME
%token <EName> NSSTART START STARTSPECIAL
%%
document 		: dtd_declarations element misc_seq_opt
			;

dtd_declarations	: /*EMPTY*/
			| dtd_declaration
			;
dtd_declaration		: DOCTYPE NAME NAME VALUE CLOSE
			;

element			: empty_elem_tag
			| stag content etag
			;

misc_seq_opt 		: /*empty*/
			| misc_seq_opt misc
			;
misc 			: COMMENT		
			;

empty_elem_tag		: START NAME attributes SLASH CLOSE
			;

stag			: START NAME attributes END
			;

etag			: END NAME CLOSE
			;

attributes		: attributes NAME EQ VALUE
			| /* EMPTY */
			;

content			: content DATA
			| content element
			| content misc
			| /* empty */
			;
%%
int xmlwrap(void) { return 1; }
void xmlerror(char *msg) { fprintf(stderr, "%s\n", msg); }
