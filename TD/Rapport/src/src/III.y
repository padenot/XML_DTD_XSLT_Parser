%{
	#include <stdio.h>
%}

%token ELEMENT ATTLIST CLOSE
%token NAME CDATA DECLARATION
%token OPENPAR CLOSEPAR
%token PLUS PIPE QUESTIONMARK AST

%%
markup			:	ELEMENT NAME 
			;

seq_choice		:	OPENPAR enumerations CLOSEPAR quantificator
			;

enumerations		:	enum_members quantificator
			;

enum_members		:	NAME
			|	enum_members separator NAME
			| 	sequence
			|	/* EMPTY */
			;

separator		:	COMMA
			|	PIPE
			;

quantificator		:	/* EMPTY */
			|	AST
			|	PLUS
			|	QUESTIONMARK
			;	
%%
