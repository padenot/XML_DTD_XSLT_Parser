all: analyseDTD test

flex: src/dtd.l
	@flex -o src/dtd.yy.c src/dtd.l

bison: src/dtd.y
	@bison -o src/dtd.tab.c --defines=src/dtd.tab.h src/dtd.y

analyseDTD: flex bison Makefile
	@g++ -g -DYYDEBUG=1 -o bin/analyseDTD src/dtd.yy.c src/dtd.tab.c 

test: analyseDTD 
	@cd bin && ./analyseDTD < rap1.dtd | grep "sucess"
	@cd bin && ./analyseDTD < rap2.dtd | grep "sucess"
	@cd bin && ./analyseDTD < rap3.dtd | grep "sucess"
	@cd bin && ./analyseDTD < rap4.dtd | grep "sucess"

clean:
	@rm -rf bin/analyseDTD bin/analyseDTD.dSYM/
	
mrproper: clean
	@rm src/dtd.output
	@rm src/dtd.tab.c src/dtd.tab.h
	@rm src/dtd.yy.c
