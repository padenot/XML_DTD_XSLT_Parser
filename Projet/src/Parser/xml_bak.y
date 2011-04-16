element			: start attributes content_group			{ 
				  							$$ = (CompositeMarkupNode*)handleElement(proxyPtr, $1->first, $1->second, *$2, $3);
											root = $$;
			  							}
			| start attributes empty				{
				  							$$ = handleElement(proxyPtr, $1->first, $1->second, *$2, $3);
											root = $$;
										}
			| STARTSPECIAL attributes CLOSESPECIAL			
			;

attributes		: /* EMPTY */						{ $$ = new MarkupNode::Attributes(); }
			| attributes NAME EQ VALUE				{ $1->insert( pair<string, string>($2, $4) ); $$ = $1; }
			;

start 			: START							{ $$ = $1; }
			| NSSTART						{ $$ = $1; } 
			;

empty			: SLASH CLOSE
			;

content_group		: close_content_and_end name_or_nsname_opt CLOSE	{ $$ = $1; } 
			;

name_or_nsname_opt 	: NAME     
			| NSNAME  
			| /* empty */
			;

close_content_and_end 	: CLOSE content END 					{ $$ = $2; }
			;

content 		: content DATA						{ 	
				  							$1->push_back( new TextNode( proxyPtr, string($2) ) );
				 							$$ = $1; 
			  							}
			| content misc       					{ $$ = $1; }
			| content element 					{ $1->push_back( $2 ); $$ = $1; }
			| /*empty*/         					{ 
											$$ = new list<Node*>();
											proxyPtr = new CompositeMarkupNode*;
										}
			;

