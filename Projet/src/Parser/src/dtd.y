%{
	using namespace std;
	#include <stack>
	#include <list>
	#include <cstring>
	#include <cstdio>
	#include <cstdlib>

	#include "Element.hh"

	void dtderror(char *msg);
	int dtdwrap(void);
	int dtdlex(void);
%}

%union { 
	char *s; 
}

%token ELEMENT ATTLIST CLOSE OPENPAR CLOSEPAR COMMA PIPE FIXED EMPTY ANY PCDATA AST QMARK PLUS CDATA
%token <s> NAME TOKENTYPE DECLARATION STRING
%%

root			: dtd
    			;

dtd			: dtd attlist CLOSE
			| dtd element CLOSE
   			| /* empty */                     
   			;

attlist			: ATTLIST NAME att_definition
			;

element 		: ELEMENT NAME choice_or_sequence quantifier
			| ELEMENT NAME OPENPAR primary_type CLOSEPAR
			;

att_definition 		: att_definition attribut
			| /* empty */
			;

attribut 		: NAME att_type defaut_declaration
			;

att_type 		: CDATA    
			| TOKENTYPE
			| type_enumere
			;

type_enumere 		: OPENPAR liste_enum_plus CLOSEPAR
			;

liste_enum_plus 	: liste_enum PIPE item_enum
			;

liste_enum 		: item_enum               
			| liste_enum PIPE item_enum
			;

item_enum 		: NAME
			;

defaut_declaration 	: DECLARATION 
			| STRING     
			| FIXED STRING 
			;

choice_or_sequence	: choice
			| sequence
			; 

sequence		: OPENPAR list_sequence CLOSEPAR
			; 

list_sequence		: item 
			| list_sequence COMMA item
			; 

choice			: OPENPAR list_choice CLOSEPAR
			; 

list_choice		: list_choice_transition PIPE item
			; 

list_choice_transition	: item
			| list_choice_transition PIPE item
			; 

item 			: NAME quantifier
			| choice_or_sequence quantifier
			; 

quantifier		: AST
			| QMARK
			| PLUS
			| /* EMPTY */
			; 

primary_type		: CDATA
			| PCDATA
			| FIXED
			;
%%

int dtdwrap(void)
{
  return 1;
}

void dtderror(char *msg)
{
  fprintf(stderr, "%s\n", msg);
}


