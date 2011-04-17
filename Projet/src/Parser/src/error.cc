extern int xmllineno;

int UnmatchedNames(char* openingName, char* closingName) {
	if ( strcmp( openingName, closingName) != 0 )
		printf("Syntax error ( line %d ) : Opening & closing markup name don't match ( %s != %s )\n", xmllineno, openingName, closingName);
}
