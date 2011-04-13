%{
	#define QTF_AST		1
	#define QTF_PLUS	2
	#define QTF_QMARK	4
	#define QTF_NONE	0

	#include <stack>
	#include <list>
	#include <cstring>
	#include <cstdio>
	#include <cstdlib>

//	#include "Element.hh"
	#include "DTD.hh"

	using namespace std;

	void dtderror(char *msg);
	int dtdwrap(void);
	int dtdlex(void);

	dtd::DTD rootDTD;
%}

%union { 
	char *s; 

	std::list<void*>* clist;
	int qtf;
}

%token ELEMENT ATTLIST CLOSE OPENPAR CLOSEPAR COMMA PIPE FIXED EMPTY ANY PCDATA AST QMARK PLUS CDATA NAME TOKENTYPE DECLARATION STRING

%type <s> NAME TOKENTYPE DECLARATION STRING
%type <clist> choice_or_sequence
%type <qtf> quantifier
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
			| ELEMENT NAME OPENPAR primary_type CLOSEPAR 			/*{ dtd.addElement("", $2, content); } */
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

quantifier		: AST 								{ $$ = QTF_AST; }
			| QMARK								{ $$ = QTF_QMARK; }
			| PLUS								{ $$ = QTF_PLUS; }
			| /* EMPTY */							{ $$ = QTF_NONE; }
			; 

primary_type		: CDATA							 
			| PCDATA						 
			| FIXED							
			;
%%
int dtdwrap(void) { return 1; }
void dtderror(char *msg) { fprintf(stderr, "%s\n", msg); }
