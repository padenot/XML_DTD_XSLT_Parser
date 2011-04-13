BINPATH=bin

all: | $(BINPATH)
	@cd AnalyseurXML/ && make && cp bin/analyseXML ../$(BINPATH)
	@cd AnalyseurDTD/ && make && cp bin/analyseDTD ../$(BINPATH)
	@cd Parser/ && make && cp bin/parser ../$(BINPATH)
	@cd xml/ && make
	@cd dtd/ && make
	@cd xsl/ && make
	
test: all
	@cd AnalyseurXML/ && make test
	@cd AnalyseurDTD/ && make test
	@cd Parser/ && make test
	@cd xml/ && make test
	@cd dtd/ && make test
	@cd xsl/ && make test
	# TODO : ajouter tests d'intégration
	
$(BINPATH) :
	mkdir $@

mrproper:
	@rm $(BINPATH)/*
