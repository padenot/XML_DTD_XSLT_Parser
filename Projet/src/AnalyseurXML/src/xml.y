%{
	using namespace std;

#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include "commun.h"
#include "yy.tab.h"

	int yywrap(void);
	void yyerror(char *msg);
	int yylex(void);

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
document
: declarations element misc_seq_opt 
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
: DOCTYPE NAME NAME VALUE CLOSE { dtdReference.assign($4); }
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

int main(int argc, char **argv)
{
	int err;

	err = yyparse();
	if (err != 0) printf("Parse ended with %d error(s)\n", err);
	else  printf("Parse ended with sucess\n", err);

	if(!dtdReference.empty()) {
		printf("\nAnalyse du fichier DTD (%s)...\n", dtdReference.c_str());

		string path = "./analyseDTD < " + dtdReference;
		printf("%s\n", path.c_str());

		char* argv[2]; 
		system(path.c_str());
	}

	return 0;
}

int yywrap(void)
{
	return 1;
}

void yyerror(char *msg)
{
	fprintf(stderr, "%s\n", msg);
}

