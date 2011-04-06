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

	#include "Node.hh"
	#include "TextNode.hh"
	#include "MarkupNode.hh"
	#include "CompositeMarkupNode.hh"


	void xmlerror(char *msg);
	int xmlwrap(void);
	int xmllex(void);

	int handleDTD(char*);

	xml::CompositeMarkupNode** parent;
%}

%error-verbose
%union {
	char * s;
	ElementName * en;  /* le nom d'un element avec son namespace */
	list<void*>* children;
}

%token EQ SLASH CLOSE END CLOSESPECIAL DOCTYPE
%token <s> ENCODING VALUE DATA COMMENT NAME NSNAME
%token <en> NSSTART START STARTSPECIAL

%type <children> content
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

element			: start attributes empty_or_content 		
			| STARTSPECIAL attributes CLOSESPECIAL
			;

attributes		: /* EMPTY */
			| attributes NAME EQ VALUE
			;

start 			: START							
			| NSSTART	
			;

empty_or_content 	: SLASH CLOSE						
			| close_content_and_end name_or_nsname_opt CLOSE 
			;

name_or_nsname_opt 	: NAME     
			| NSNAME  
			| /* empty */
			;

close_content_and_end 	: CLOSE content END 
			;

content 		: content DATA						{ $$ = $1; $1->push_back( (void*)(new xml::TextNode( *parent, string($2) )) ); }
			| content misc        
			| content element      
			| /*empty*/         					{ $$ = (list<void*>*)new list<xml::Node*>(); }
			;
%%
int xmlwrap(void) { return 1; }
void xmlerror(char *msg) { fprintf(stderr, "%s\n", msg); }
