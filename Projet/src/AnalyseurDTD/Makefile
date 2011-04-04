all: analyseDTD test

flex: src/dtd.l
	@flex -Pdtd -o src/dtd.yy.c src/dtd.l

bison: src/dtd.y
	@bison -p dtd -o src/dtd.tab.c --defines=src/dtd.tab.h src/dtd.y

analyseDTD: flex bison Makefile
	@g++ -Wno-write-strings -g -DYYDEBUG=1 -o bin/analyseDTD src/dtd.yy.c src/dtd.tab.c src/main.c 

test: analyseDTD 
	@echo "TESTING AnalyseDTD..."
	@cd bin && ./analyseDTD < rap1.dtd &>/dev/null && echo "rap1.dtd : OK" 
	@cd bin && ./analyseDTD < rap2.dtd &>/dev/null && echo "rap2.dtd : OK" 
	@cd bin && ./analyseDTD < rap3.dtd &>/dev/null && echo "rap3.dtd : OK" 
	@cd bin && ./analyseDTD < rap4.dtd &>/dev/null && echo "rap4.dtd : OK" 

clean:
	@rm -rf bin/analyseDTD bin/analyseDTD.dSYM/
	
mrproper: clean
	@rm src/dtd.tab.c src/dtd.tab.h
	@rm src/dtd.yy.c
