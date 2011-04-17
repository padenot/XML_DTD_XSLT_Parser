#include <cstdlib>
#include <cstring>
#include <cstdio>

extern int xmllineno;

int UnmatchedNames(const char* openingName, const char* closingName) {
	if ( strcmp( openingName, closingName) != 0 ) {
		printf("\tSyntax error ( line %d ) : Opening & closing markup name don't match ( %s != %s ), maybe you forgot to close the markup ?\n", xmllineno, openingName, closingName);
		return 1;
	}

	return 0;
}
