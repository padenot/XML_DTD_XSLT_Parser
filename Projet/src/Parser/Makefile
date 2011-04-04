all: bin/parser

bin/parser: Makefile src/xml.l src/dtd.l
	@flex -Pxml -o src/xml.yy.c src/xml.l
	@flex -Pdtd -o src/dtd.yy.c src/dtd.l
	@bison -o src/xml.tab.c --debug --verbose -p xml --define=src/xml.yy.h src/xml.y
	@bison -o src/dtd.tab.c --debug --verbose -p xml --define=src/dtd.yy.h src/dtd.y
	@g++ -g -DYYDEBUG=1 -o bin/Parser src/xml.yy.c src/dtd.yy.c src/dtd.tab.c src/xml.tab.c src/main.c 

clean:

