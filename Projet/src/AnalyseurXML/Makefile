all: analyseXML test

flex: src/xml.l
	@flex -Pxml -o src/xml.yy.cpp src/xml.l

bison: src/xml.y
	@bison -p xml -o src/xml.tab.cpp --defines=src/xml.tab.h src/xml.y

analyseXML: flex bison 
	@g++ -Wno-write-strings -g -I../xml/src -DYYDEBUG=1 -o bin/analyseXML src/xml.yy.cpp src/xml.tab.cpp src/main.cpp

test: analyseXML
	@echo "TESTING AnalyseXML..." 
	@cd bin && ./analyseXML < rap1.xml &> /dev/null && echo "rap1.xml : OK"
	@cd bin && ./analyseXML < rap2.xml &> /dev/null && echo "rap2.xml : OK" 
	@cd bin && ./analyseXML < rap3.xml &> /dev/null && echo "rap3.xml : OK" 
	@cd bin && ./analyseXML < rap4.xml &> /dev/null && echo "rap4.xml : OK" 
	@cd bin && ./analyseXML < rap5.xml &> /dev/null && echo "rap5.xml : OK" 

clean:
	@rm -rf bin/analyseXML bin/analyseXML.dSYM/
	
mrproper: clean
	@rm src/xml.tab.cpp src/xml.tab.h
	@rm src/xml.yy.cpp
