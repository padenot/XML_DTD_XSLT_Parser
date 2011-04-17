%{
	#include <cstring>
	#include <string>
	#include <cstdio>
	#include <cstdlib>
	#include <unistd.h>
	#include "commun.h"

	#include <stack>

	#include "xml.tab.h"

	using namespace xml;
	using namespace std;

	void xmlerror(char *msg);
	int xmlwrap(void);
	int xmllex(void);

	int handleDTD(char*);

	string dtdName;
	string validRootName;
	MarkupNode* root = 0;
	static stack<CompositeMarkupNode**> proxy(deque<CompositeMarkupNode**>(1,
		static_cast<CompositeMarkupNode**>(0)));
%}

%error-verbose
%union {
	char * s;
	ElementName* en;
	DtdSpecs* dtdSpecs;
	xml::MarkupNode* element;
	xml::MarkupNode::Attributes* attributes;
	xml::CompositeMarkupNode::Children* children;
}

%token EQ SLASH CLOSE END CLOSESPECIAL DOCTYPE
%token <s> ENCODING VALUE DATA COMMENT NAME NSNAME
%token <en> NSSTART START STARTSPECIAL
%type <dtdSpecs> dtd_declarations dtd_declaration
%type <element> element empty_element composite_element
%type <attributes> attributes
%type <children> content
%%
document	: dtd_declarations element misc_seq_opt
			{
				if ($1 != 0)
				{
					dtdName = $1->first;
					validRootName = $1->second;
					delete $1;
				}
				root = $2;
			}
			;

dtd_declarations	: /*EMPTY*/
				 		{$$ = 0;}
					| dtd_declaration
						{$$ = $1;}
					;

dtd_declaration	: DOCTYPE NAME NAME VALUE CLOSE
				{
					$$ = new DtdSpecs($4,$2);
					delete $2;
					delete $3;
					delete $4;
				}
				;

element		: empty_element
				{$$ = $1;}
			| composite_element
				{$$ = $1;}
			;

misc_seq_opt 	: /*empty*/
				| misc_seq_opt misc
				;
misc 		: COMMENT
				{delete $1;}
			;

empty_element	: START attributes SLASH CLOSE
				{
					$$ = new MarkupNode(proxy.top(), $1->first, $1->second, *$2);
					delete $1;
					delete $2;
				}
				| NSSTART attributes SLASH CLOSE
				{
					$$ = new MarkupNode(proxy.top(), $1->first, $1->second, *$2);
					delete $1;
					delete $2;
				}
				;

composite_element	: START attributes CLOSE content END NAME CLOSE
					{
						CompositeMarkupNode** selfProxy = proxy.top();
						proxy.pop();
						CompositeMarkupNode** parentProxy = proxy.top();
						$$ = new CompositeMarkupNode(parentProxy, $1->first,
							$1->second, *$2, *selfProxy, *$4);
						delete $1;
						delete $2;
						delete $4;
					}
					| NSSTART attributes CLOSE content END NAME CLOSE
					{
						CompositeMarkupNode** selfProxy = proxy.top();
						proxy.pop();
						CompositeMarkupNode** parentProxy = proxy.top();
						$$ = new CompositeMarkupNode(parentProxy, $1->first,
							$1->second, *$2, *selfProxy, *$4);
						delete $1;
						delete $2;
						delete $4;
					}
					;

attributes		: attributes NAME EQ VALUE
				{
					$1->insert(pair<string,string>($2,$4));
					$$ = $1;
					delete $2;
					delete $4;
				}
				| /* EMPTY */
					{$$ = new MarkupNode::Attributes();}
				;

content			: content DATA
				{
					$1->push_back(new TextNode(proxy.top(), string($2)));
					$$ = $1;
					delete $2;
				}
				| content element
					{$1->push_back($2); $$ = $1;}
				| content misc
					{$$ = $1}
				| /* empty */
				{
					proxy.push(new CompositeMarkupNode*);
					$$ = new CompositeMarkupNode::Children();
				}
%%
int xmlwrap(void) { return 1; }
void xmlerror(char *msg) { fprintf(stderr, "%s\n", msg); }
