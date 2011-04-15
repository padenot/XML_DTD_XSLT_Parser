%{
	#define QTF_AST		1
	#define QTF_PLUS	2
	#define QTF_QMARK	4
	#define QTF_NONE	0

	#include <stack>
	#include <list>
	#include <set>
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

	#include "QuantifiableContent.hh"
	#include "Sequence.hh"
	#include "Choice.hh"

	using namespace std;

	void dtderror(char *msg);
	int dtdwrap(void);
	int dtdlex(void);

	dtd::QuantifiableContent* handleQuantifier(dtd::ElementContent*, int);

	dtd::DTD* rootDTD = new dtd::DTD();
%}

%union { 
	char *s; 

	int t_quantifier;

	std::set<void*>* t_attlist; 	/* list<Attribute*> */
	void* t_attribut;		/* Attribute* */

	void* t_any_or_empty;		

	void* t_mixed;
	void* t_simple_list_choice;

	void* t_choice_or_sequence;	/* ElementContent* */

	void* t_choice;			/* Choice* */

	void* t_sequence;		/* Sequence* */
	void* t_list_sequence;		/* List< ElementContent* > */

	void* t_item;			/* QuantifiableContent* */
}

%token ELEMENT ATTLIST CLOSE OPENPAR CLOSEPAR COMMA PIPE FIXED EMPTY ANY PCDATA AST QMARK PLUS CDATA NAME TOKENTYPE DECLARATION STRING

%type <s> NAME TOKENTYPE DECLARATION STRING

%type <t_quantifier> quantifier

%type <t_attlist> att_definition
%type <t_attribut> attribut 

%type <t_any_or_empty> any_or_empty

%type <t_mixed> mixed
%type <t_simple_list_choice> simple_list_choice

%type <t_choice_or_sequence> choice_or_sequence

%type <t_choice> choice

%type <t_sequence> sequence 
%type <t_list_sequence> list_sequence

%type <t_item> item
%%

root			: dtd 						
    			;

dtd			: dtd attlist CLOSE					
			| dtd element CLOSE					
   			| /* empty */
   			;

attlist			: ATTLIST NAME att_definition					{ rootDTD->addAttributesList(string(""), string($2), *( dtd::AttributesList* )($3) ); }  
			;

element 		: ELEMENT NAME mixed 						{ rootDTD->addElement("", $2, *(dtd::Content*)($3) ); }
			| ELEMENT NAME any_or_empty 					{ rootDTD->addElement("", $2, *(dtd::Content*)($3) ); }
			| ELEMENT NAME choice_or_sequence quantifier			{ rootDTD->addElement("", $2, handleQuantifier( *(dtd::ElementContent*)($3), $4 ) ); }
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
												((dtd::MixedContent::ChoosableSet*)$1)->insert( new dtd::ElementReference(*rootDTD, "", $3 ) ); 
												$$ = $1; 
											}
			;

att_definition 		: att_definition attribut					{ $1->insert( (dtd::Attribute*)($2) ); $$ = $1; } 
			| /* empty */							{ $$ = (set<void*>*)( new dtd::AttributesList() ); }
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

choice_or_sequence	: choice							{ $$ = NULL; }	
			| sequence							{ $$ = (dtd::ElementContent*)($1); } 
			; 

sequence		: OPENPAR list_sequence CLOSEPAR				{ $$ = new dtd::Sequence( *(dtd::Sequence::OrderedContent*)$2 ); }
			; 

list_sequence		: item 								{ 
				  								dtd::Sequence::OrderedContent* itemList = new dtd::Sequence::OrderedContent();
				  								itemList->push_back( (dtd::QuantifiableContent*) $1 );
												$$ = (void*)itemList;
			  								}	
			| list_sequence COMMA item					{ ((dtd::Sequence::OrderedContent*)$1)->push_back( (dtd::QuantifiableContent*) $3 ); $$ = $1; }
			; 

choice			: OPENPAR list_choice CLOSEPAR					
			; 

list_choice		: list_choice_transition PIPE item				
			; 

list_choice_transition	: item
			| list_choice_transition PIPE item
			; 

item 			: NAME quantifier						{ $$ = handleQuantifier( new dtd::ElementReference( *rootDTD, "", $1 ), $2 ); }
			| choice_or_sequence quantifier					{ $$ = handleQuantifier( (dtd::ElementContent*) $1, $2 ); }
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
