all: bin/analyseXML test

bin/analyseXML: src/*.l src/*.y Makefile
	@flex  src/xml.l
	@bison --debug --verbose --defines=src/yy.tab.h src/xml.y
	@mv lex.yy.c xml.tab.c xml.output src/
	@g++ -g -Wwrite-strings -DYYDEBUG=1 -o bin/analyseXML src/lex.yy.c src/xml.tab.c 

test: bin/analyseXML
	@cd bin && ./analyseXML < rap1.xml | grep "sucess" && ./analyseXML < rap2.xml | grep "sucess" && ./analyseXML < rap3.xml | grep "sucess"

clean:
	@rm -rf src/*.tab.c src/lex.*.c src/*.tab.h src/*.output bin/analyseXML

