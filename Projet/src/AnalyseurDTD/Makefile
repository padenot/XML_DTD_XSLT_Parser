all: analyseDTD test

analyseDTD: src/*.l src/*.y Makefile
	@flex  src/dtd.l
	@bison  --debug --verbose --defines=src/yy.tab.h src/dtd.y
	@mv *.c src
	@mv *.output bin
	@g++ -g -DYYDEBUG=1 -o bin/analyseDTD src/lex.yy.c src/dtd.tab.c 

test: 
	@cd bin && ./analyseDTD < rap1.dtd | grep "sucess" && ./analyseDTD < rap2.dtd | grep "sucess" && ./analyseDTD < rap3.dtd | grep "sucess"

clean:
	@rm -rf src/*.tab.c src/lex.*.c src/*.tab.h bin/*.output bin/analyseDTD
