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

	#include "DTD.hh"

	#include "AttributesList.hh"
	#include "Attribute.hh"

	#include "EmptyContent.hh"
	#include "AnyContent.hh"

	#include "MixedContent.hh"
	#include "TextContent.hh"
	#include "ElementReference.hh"

	using namespace std;

	void dtderror(char *msg);
	int dtdwrap(void);
	int dtdlex(void);

	dtd::DTD* rootDTD = new dtd::DTD();
%}

%union { 
	char *s; 

	int t_quantifier;

	std::list<void*>* t_attlist; /* list<Attribute*> */
	void* t_attribut;

	void* t_any_or_empty;

	void* t_mixed;
	void* t_simple_list_choice;
}

%token ELEMENT ATTLIST CLOSE OPENPAR CLOSEPAR COMMA PIPE FIXED EMPTY ANY PCDATA AST QMARK PLUS CDATA NAME TOKENTYPE DECLARATION STRING

%type <s> NAME TOKENTYPE DECLARATION STRING

%type <t_quantifier> quantifier

%type <t_attlist> att_definition
%type <t_attribut> attribut 

%type <t_any_or_empty> any_or_empty

%type <t_mixed> mixed
%type <t_simple_list_choice> simple_list_choice
%%

root			: dtd 						
    			;

dtd			: dtd attlist CLOSE					
			| dtd element CLOSE					
   			| /* empty */
   			;

attlist			: ATTLIST NAME att_definition					{ rootDTD->addAttributesList("", $2, *( list< dtd::Attribute* > * )($3) ); }  
			;

element 		: ELEMENT NAME mixed 						{ rootDTD->addElement("", $2, *(dtd::Content*)($3) ); }
			| ELEMENT NAME any_or_empty 					{ rootDTD->addElement("", $2, *(dtd::Content*)($3) ); }
			| ELEMENT NAME choice_or_sequence quantifier			{ printf("Sequence ou choix\n"); }
			| ELEMENT NAME OPENPAR primary_type CLOSEPAR 			{ printf("primary type\n"); }
			;

any_or_empty		: EMPTY								{ $$ = new dtd::EmptyContent(); }
			| ANY								{ $$ = new dtd::AnyContent(); }
			;

mixed			: OPENPAR PCDATA PIPE simple_list_choice CLOSEPAR quantifier 	{ $$ = new dtd::MixedContent( *new dtd::TextContent(), *(dtd::MixedContent::ChoosableSet*)($4) );  }
			| OPENPAR PCDATA CLOSEPAR quantifier				{ $$ = new dtd::MixedContent( *new dtd::TextContent(), *new dtd::MixedContent::ChoosableSet() );  }
			;

simple_list_choice	: NAME								{ 
				  								dtd::MixedContent::ChoosableSet* newSet = new dtd::MixedContent::ChoosableSet(); 
												newSet->insert( new dtd::ElementReference(*rootDTD, "", $1) ); 
												$$ = newSet;
			  								}
			| simple_list_choice PIPE NAME					{ 
												(dtd::MixedContent::ChoosableSet*)$$->insert( new dtd::ElementReference(*rootDTD, "", $3 ) ); 
												$$ = $1; 
											}
			;

att_definition 		: att_definition attribut					{ $1->push_back( (dtd::Attribute*)($2) ); $$ = $1; } 
			| /* empty */							{ $$ = (list<void*>*)( new list<dtd::Attribute*>() ); }
			;

attribut 		: NAME att_type defaut_declaration				{ $$ = new dtd::Attribute($1); }
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
