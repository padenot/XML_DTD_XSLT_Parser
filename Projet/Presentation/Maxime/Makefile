XML_FILE=rap1.xml
XSL_FILE=rap1_simplifie.xslt

all: xml2dot dot2pdf xslt2html error visual

xml2dot: src/$(XML_FILE)
	@echo "Export de l'arbre XML..."
	@cd src/ && ./parser -e $(XML_FILE) > ../export/$(XML_FILE).dot

dot2pdf: xml2dot export/$(XML_FILE).dot
	@echo "Compilation du fichier DOT..."
	@dot -Tpdf -o img/$(XML_FILE).pdf export/$(XML_FILE).dot

xslt2html: src/$(XML_FILE) src/$(XSL_FILE)
	@echo "Compilation de $(XML_FILE) par $(XSL_FILE)..."
	@cd src/ && ./parser -t $(XSL_FILE) $(XML_FILE) > ../export/$(XML_FILE).html

.PHONY: clean visual error

error:
	-@cd src/ ; cat bad3.xml ; read ; ./parser -cv bad3.xml ; read
	-@cd src/ ; cat bad4.xml ; read ; ./parser -cv bad4.xml ; read
	-@cd src/ ; cat bad5.xml ; read ; ./parser -cv bad5.xml ; read

visual: src/$(XML_FILE)
	@cd src/ && ./parser $(XML_FILE) 

clean:
	@rm -rf export/* >/dev/null
	@rm -rf img/* >/dev/null
