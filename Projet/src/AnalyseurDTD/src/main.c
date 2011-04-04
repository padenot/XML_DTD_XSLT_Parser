#include <iostream>
#include <cstdio>

int dtdparse(void);

int main(int argc, char **argv)
{
  int err;

  err = dtdparse();
  if (err != 0) printf("Parse ended with %d error(s)\n", err);
        else  printf("Parse ended with sucess\n", err);
  return 0;
}
