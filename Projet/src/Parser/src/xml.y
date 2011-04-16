%{
	using namespace std;

	#include <cstring>
	#include <string>
	#include <cstdio>
	#include <cstdlib>
	#include <unistd.h>
	#include "commun.h"
	#include "xml.tab.h"

	#include <list>
	#include <map>

	#include "Node.hh"
	#include "TextNode.hh"
	#include "MarkupNode.hh"
	#include "CompositeMarkupNode.hh"

	void xmlerror(char *msg);
	int xmlwrap(void);
	int xmllex(void);

	int handleDTD(char*);
	xml::MarkupNode* handleElement(xml::CompositeMarkupNode** proxy, string NS, string name, xml::MarkupNode::Attributes attbs, xml::CompositeMarkupNode::Children* children);

	xml::CompositeMarkupNode* root;
	xml::CompositeMarkupNode** proxyPtr;
%}

%error-verbose
%union {
	char * s;
	ElementName * en;  /* le nom d'un element avec son namespace */

	list<void*>* children;
	void* ats;
	void* cmn;
}

%token EQ SLASH CLOSE END CLOSESPECIAL DOCTYPE
%token <s> ENCODING VALUE DATA COMMENT NAME NSNAME
%token <en> NSSTART START STARTSPECIAL
%type <en> start

%type <children> content empty_or_content close_content_and_end
%type <cmn> element
%type <ats> attributes
%%

document 		: declarations element misc_seq_opt 
			;

misc_seq_opt 		: misc_seq_opt misc
			| /*empty*/
			;

misc 			: COMMENT		
			;

declarations 		: declaration
			| /*empty*/
			;

declaration 		: DOCTYPE NAME NAME VALUE CLOSE 			{ handleDTD($4); }
			;

element			: start attributes empty_or_content			{ 
				  							$$ = handleElement(proxyPtr, $1->first, $1->second, *((xml::MarkupNode::Attributes*)$2), (xml::CompositeMarkupNode::Children*)($3));
											root = (xml::CompositeMarkupNode*)$$;
			  							}
			| STARTSPECIAL attributes CLOSESPECIAL
			;

attributes		: /* EMPTY */						{ $$ = (void*)(new xml::MarkupNode::Attributes()); }
			| attributes NAME EQ VALUE				{ ((xml::MarkupNode::Attributes*)$1)->insert( pair<string, string>($2, $4) ); $$ = $1; }
			;

start 			: START							{ $$ = $1; }
			| NSSTART						{ $$ = $1; } 
			;

empty_or_content 	: SLASH CLOSE						{ $$ = (list<void*>*)new list<xml::Node*>(); }
			| close_content_and_end name_or_nsname_opt CLOSE	{ $$ = $1; } 
			;

name_or_nsname_opt 	: NAME     
			| NSNAME  
			| /* empty */
			;

close_content_and_end 	: CLOSE content END 					{ $$ = $2; }
			;

content 		: content DATA						{ 	
				  							$1->push_back( (void*)(new xml::TextNode( proxyPtr, string($2) )) );
				 							$$ = $1; 
			  							}
			| content misc       					{ $$ = $1; }
			| content element 					{ $1->push_back( (void*)($2) ); $$ = $1; }
			| /*empty*/         					{ 
											$$ = (list<void*>*)new list<xml::Node*>();
											proxyPtr = new xml::CompositeMarkupNode*;
										}
			;
%%
int xmlwrap(void) { return 1; }
void xmlerror(char *msg) { fprintf(stderr, "%s\n", msg); }
