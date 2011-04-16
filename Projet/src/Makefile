BINPATH=bin
DEBUG_DEFINE=DEBUG=yes

all: | $(BINPATH)
	@cd xml/ && make $(DEBUG_DEFINE)
	@cd dtd/ && make $(DEBUG_DEFINE)
#	@cd AnalyseurXML/ && make && cp bin/analyseXML ../$(BINPATH)
#	@cd AnalyseurDTD/ && make && cp bin/analyseDTD ../$(BINPATH)
	@cd Parser/ && make && cp bin/parser ../$(BINPATH)
#	@cd xsl/ && make
	
test:
	@cd xml/ && make test $(DEBUG_DEFINE)
	@cd dtd/ && make test $(DEBUG_DEFINE)
	#@cd AnalyseurXML/ && make test
	#@cd AnalyseurDTD/ && make test
	@cd Parser/ && make test
#	@cd xsl/ && make test
# TODO : ajouter tests d'intégration
	
$(BINPATH) :
	mkdir $@

mrproper:
	@rm $(BINPATH)/*
