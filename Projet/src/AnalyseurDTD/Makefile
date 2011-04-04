all: analyseDTD test

analyseDTD: src/*.l src/*.y Makefile
	@flex  src/dtd.l
	@bison  --debug --verbose --defines=src/yy.tab.h src/dtd.y
	@mv *.c *.output src
	@g++ -g -DYYDEBUG=1 -o bin/analyseDTD src/lex.yy.c src/dtd.tab.c 

test: 

clean:
	@rm -rf src/*.tab.c src/lex.*.c src/*.tab.h bin/*.output bin/analyseDTD
