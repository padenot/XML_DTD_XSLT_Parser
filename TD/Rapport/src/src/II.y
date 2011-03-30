%{
	#include <stdio.h>
%}

%token DOCTYPE ENCODING EQ
%token START CLOSE END 
%token VALUE DATA NAME
%token STARTSPECIAL CLOSESPECIAL
%token NSNAME NSSTART 

%%
document		:	/* EMPTY */
			| 	document element
			;

element			: 	START markup CLOSE
			|	NSSTART markup CLOSE
			|	STARTSPECIAL attributes CLOSESPECIAL
			;

markup			: 	SLASH
			|	attributes complete_markup
			;

complete_markup		:	CLOSE content END custom_name
			;

custom_name 		:	NAME
			|	NSNAME
			;

attributes		:	/* EMPTY */
			|	attributes NAME EQ VALUE
			;
			
content			:	/* EMPTY */
			|	content element
			|	content DATA
			;
%%
