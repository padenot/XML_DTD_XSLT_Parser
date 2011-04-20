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
	#include "OptionalContent.hh"
	#include "RepeatableContent.hh"
	#include "RepeatedContent.hh"
	#include "Sequence.hh"
	#include "Choice.hh"

	using namespace std;
	using namespace dtd;

	void dtderror(DTD & rootDTD, char *msg);
	int dtdwrap(void);
	int dtdlex(void);

	QuantifiableContent* handleQuantifier(QuantifiableContent*, int);
%}

%union { 
	char *s; 

	int t_quantifier;

	AttributesList* t_attlist;			 			
	Attribute* t_attribut;						

	Content* t_any_or_empty;		

	QuantifiableContent* t_mixed;
	MixedContent::ChoosableSet* t_simple_list_choice;

	ElementContent* t_choice_or_sequence;				

	Choice* t_choice;						
	Choice::ChoosableSet* t_list_choice;
	Choice::ChoosableSet* t_list_choice_transition;

	Sequence* t_sequence;						
	Sequence::OrderedContent* t_list_sequence;						

	ElementContent* t_item;					
}

%parse-param {dtd::DTD & rootDTD}
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
%type <t_list_choice> list_choice
%type <t_list_choice_transition> list_choice_transition

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

attlist			: ATTLIST NAME att_definition					{ rootDTD.addAttributesList(string(""), string($2), *$3 ); }  
			;

element 		: ELEMENT NAME mixed 						{ rootDTD.addElement("", $2, *$3 ); }
			| ELEMENT NAME any_or_empty 					{ rootDTD.addElement("", $2, *$3 ); }
			| ELEMENT NAME choice_or_sequence quantifier			{ rootDTD.addElement("", $2, *handleQuantifier( $3, $4 ) ); }
			;

any_or_empty		: EMPTY								{ $$ = new EmptyContent(); }
			| ANY								{ $$ = new AnyContent(); }
			;

mixed			: OPENPAR PCDATA PIPE simple_list_choice CLOSEPAR quantifier 	{ $$ = handleQuantifier( new MixedContent( *new TextContent(), *$4 ), $6 );  }
			| OPENPAR PCDATA CLOSEPAR quantifier				{ $$ = handleQuantifier( new MixedContent( *new TextContent(), *new MixedContent::ChoosableSet() ), $4 );  }
			;

simple_list_choice	: NAME								{ 
				  								MixedContent::ChoosableSet* newSet = new MixedContent::ChoosableSet(); 
												newSet->insert( new dtd::ElementReference(rootDTD, "", $1) ); 
												$$ = newSet;
			  								}
			| simple_list_choice PIPE NAME					{ 
												$1->insert( new ElementReference(rootDTD, "", $3 ) ); 
												$$ = $1; 
											}
			;

att_definition 		: att_definition attribut					{ $1->insert($2); $$ = $1; } 
			| /* empty */							{ $$ = new AttributesList(); }
			;

attribut 		: NAME att_type defaut_declaration				{ $$ = new Attribute($1); }
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

choice_or_sequence	: choice							{ $$ = $1; }
			| sequence							
			; 

sequence		: OPENPAR list_sequence CLOSEPAR				{ $$ = new dtd::Sequence( *$2 ); }
			; 

list_sequence		: item 								{ 
				  								Sequence::OrderedContent* itemList = new Sequence::OrderedContent();
				  								itemList->push_back( $1 );
												$$ = itemList;
			  								}	
			| list_sequence COMMA item					{ $1->push_back($3) ; $$ = $1; }
			; 

choice			: OPENPAR list_choice CLOSEPAR					{ $$ = new Choice( *$2 ); }
			; 

list_choice		: list_choice_transition PIPE item				{ $1->insert($3); $$ = $1; }
			; 

list_choice_transition	: list_choice_transition PIPE item				{ $1->insert($3); $$ = $1; }
			| item								{ Choice::ChoosableSet* newSet = new Choice::ChoosableSet(); newSet->insert($1); $$ = newSet; }
			; 

item 			: choice_or_sequence quantifier					{ $$ = (ElementContent*)handleQuantifier( $1, $2 ); }
			| NAME quantifier						{ $$ = (ElementContent*)handleQuantifier( new ElementReference( rootDTD, "", $1 ), $2 ); }
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
QuantifiableContent* handleQuantifier(QuantifiableContent* currentContent, int quantifier)
{
	switch(quantifier)
	{
		case (QTF_NONE): return currentContent;
		case (QTF_PLUS): return new RepeatedContent(*currentContent);
		case (QTF_AST): return new RepeatableContent(*currentContent);
		case (QTF_QMARK): return new OptionalContent(*currentContent);
		default : return currentContent;
	}
}
