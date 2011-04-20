#include <cstdlib>
#include <cstring>
#include <cstdio>

extern int xmllineno;

int LexerAdvice(int line, char c)
{
	printf("\tLex error (line %d) : ", line);

	if (c == '"' || c == '\'')
		fprintf(stderr, "\tUnclosed attribut string value, %c expected.\n", c);
	else
		printf("\n");

	return 0;
}

int noAttributeValue(const char* attributName)
{
	fprintf(stderr,
			"\tSyntax error ( line %d ) : No value for attribut \'%s\'\n",
			xmllineno, attributName);
	return 1;
}

int UnmatchedNames(const char* openingName, const char* closingName)
{
	if (strcmp(openingName, closingName) != 0)
	{
		fprintf(
				stderr,
				"\tSyntax error ( line %d ) : Opening & closing markup name don't match ( %s != %s ), maybe you forgot to close the markup ?\n",
				xmllineno, openingName, closingName);
		return 1;
	}

	return 0;
}
