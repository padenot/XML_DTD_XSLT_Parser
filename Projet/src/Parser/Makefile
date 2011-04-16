XMLSTRUCT_PATH=../xml
DTDSTRUCT_PATH=../dtd
XMLSTRUCT=$(XMLSTRUCT_PATH)/bin/libxmlstruct.a
DTDSTRUCT=$(DTDSTRUCT_PATH)/bin/libdtdstruct.a
STATICLIBS=$(XMLSTRUCT) $(DTDSTRUCT)

all: parser test

flex: src/dtd.l src/xml.y
	flex -Pdtd -o src/dtd.yy.c src/dtd.l
	flex -Pxml -o src/xml.yy.c src/xml.l

bison: src/dtd.y src/xml.y
	bison --verbose --debug -p dtd -o src/dtd.tab.c --defines=src/dtd.tab.h src/dtd.y
	bison --verbose --debug -p xml -o src/xml.tab.c --defines=src/xml.tab.h src/xml.y

parser: flex bison Makefile
	g++ -g -Wno-write-strings -g -DYYDEBUG=1 -I../xml/src/ -I../dtd/src/ -o bin/parser src/dtd.yy.c src/dtd.tab.c src/xml.yy.c src/xml.tab.c src/main.c ../xml/bin/libxmlstruct.a ../dtd/bin/libdtdstruct.a

$(XMLSTRUCT):
	@cd $(XMLSTRUCT_PATH) && make

$(DTDSTRUCT):
	@cd $(DTDSTRUCT_PATH) && make

test: parser 
	@echo "TESTING Parser..."
	@cd bin && ./parser 'rap1.xml' &>/dev/null && echo "rap1.xml : OK"
	@cd bin && ./parser 'rap2.xml' &>/dev/null && echo "rap2.xml : OK"
	@cd bin && ./parser 'rap3.xml' &>/dev/null && echo "rap3.xml : OK"
	@cd bin && ./parser 'rap4.xml' &>/dev/null && echo "rap4.xml : OK"

clean:
	rm -rf bin/parser bin/parser.dSYM/
	rm -rf ../xml/bin/libxmlstruct.a
	rm -rf ../dtd/bin/libdtdstruct.a
	cd ../xml/ && make mrproper && make
	cd ../dtd/ && make mrproper && make
	
mrproper: clean
	@rm src/dtd.tab.c src/dtd.tab.h
	@rm src/xml.tab.c src/xml.tab.h
	@rm src/dtd.yy.c
	@rm src/xml.yy.c

rebuild: mrproper all
