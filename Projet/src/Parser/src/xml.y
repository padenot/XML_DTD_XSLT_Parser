%{
	using namespace std;

	#include <cstring>
	#include <string>
	#include <cstdio>
	#include <cstdlib>
	#include <unistd.h>
	#include "commun.h"
	#include "xml.tab.h"

	void xmlerror(char *msg);
	int xmlwrap(void);
	int xmllex(void);
	int handleDTD(char*);

	string dtdReference;
%}
%error-verbose
%union {
	char * s;
	ElementName * en;  /* le nom d'un element avec son namespace */
}

%token EQ SLASH CLOSE END CLOSESPECIAL DOCTYPE
%token <s> ENCODING VALUE DATA COMMENT NAME NSNAME
%token <en> NSSTART START STARTSPECIAL
%%
document :		declarations element misc_seq_opt 
;

misc_seq_opt 
: misc_seq_opt misc
| /*empty*/
;

misc
: COMMENT		
;

declarations
: declaration
| /*empty*/
;

declaration
: DOCTYPE NAME NAME VALUE CLOSE { handleDTD($4); }
;

element		: start attributes empty_or_content 
| STARTSPECIAL attributes CLOSESPECIAL
;

attributes	:	/* EMPTY */
| 	attributes NAME EQ VALUE
;

start
: START		
| NSSTART	
;

empty_or_content
: SLASH CLOSE	
| close_content_and_end name_or_nsname_opt CLOSE 
;

name_or_nsname_opt 
: NAME     
| NSNAME  
| /* empty */
;

close_content_and_end 	: CLOSE content END 
;

content 		: content DATA		
| content misc        
| content element      
| /*empty*/         
;
%%

int xmlwrap(void)
{
	return 1;
}

void xmlerror(char *msg)
{
	fprintf(stderr, "%s\n", msg);
}

