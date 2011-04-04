all: bin/analyseXML
bin/analyseXML: src/*.l src/*.y Makefile
	flex  src/xml.l
	bison --debug --verbose --defines=src/yy.tab.h src/xml.y
	mv lex.yy.c xml.tab.c xml.output src/
	g++ -g -DYYDEBUG=1 -o bin/analyseXML src/lex.yy.c src/xml.tab.c 
clean:
	-rm -rf src/*.tab.c src/lex.*.c src/*.tab.h src/*.output bin/analyseXML

