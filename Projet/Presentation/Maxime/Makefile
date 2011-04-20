XML_FILE=rap1.xml
XSL_FILE=rap1_simplifie.xslt

xml2dot: src/$(XML_FILE)
	@echo "Export de l'arbre XML..."
	@cd src/ && ./parser $(XML_FILE) --export > ../export/$(XML_FILE).dot

dot2pdf: xml2dot export/$(XML_FILE).dot
	@echo "Compilation du fichier DOT..."
	@dot -Tpdf -o img/$(XML_FILE).pdf export/$(XML_FILE).dot

xslt2html: src/$(XML_FILE) src/$(XSL_FILE)
	@echo "Compilation de $(XML_FILE) par $(XSL_FILE)..."
	@cd src/ && ./parser $(XML_FILE) --xsl $(XSL_FILE) > ../export/$(XML_FILE).html

.PHONY: clean visual

visual: src/$(XML_FILE)
	@cd src/ && ./parser $(XML_FILE) 

clean:
	@rm -rf export/* >/dev/null
	@rm -rf img/* >/dev/null
