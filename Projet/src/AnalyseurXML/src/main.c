#include <cstdio>
#include <iostream>

#include "commun.h"

int xmlparse();

int main(int argc, char **argv)
{
	int err;

	err = xmlparse();
	if (err != 0) printf("Parse ended with %d error(s)\n", err);
	else  printf("Parse ended with sucess\n", err);

	return 0;
}
