all: analyseXML test

flex: src/xml.l
	@flex -o src/xml.yy.c src/xml.l

bison: src/xml.y
	@bison -o src/xml.tab.c --defines=src/xml.tab.h src/xml.y

analyseXML: flex bison 
	@g++ -g -DYYDEBUG=1 -o bin/analyseXML src/xml.yy.c src/xml.tab.c 

test: analyseXML
	@cd bin && ./analyseXML < rap1.xml | grep "sucess"
	@cd bin && ./analyseXML < rap2.xml | grep "sucess"
	@cd bin && ./analyseXML < rap3.xml | grep "sucess"
	@cd bin && ./analyseXML < rap4.xml | grep "sucess"
	@cd bin && ./analyseXML < rap5.xml | grep "sucess"

clean:
	@rm -rf bin/analyseXML bin/analyseXML.dSYM/
	
mrproper: clean
	@rm src/xml.output
	@rm src/xml.tab.c src/xml.tab.h
	@rm src/xml.yy.c
