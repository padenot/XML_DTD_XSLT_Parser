BINPATH=bin
DEBUG_DEFINE=DEBUG=yes

all: | $(BINPATH)
	@cd Parser/ && make && cp bin/parser ../$(BINPATH)
#	@cd xsl/ && make
	
test:
	@cd xml/ && make test $(DEBUG_DEFINE)
	@cd dtd/ && make test $(DEBUG_DEFINE)
	#@cd AnalyseurXML/ && make test
	#@cd AnalyseurDTD/ && make test
	@cd Parser/ && make test
	@cd xsl/ && make test
	
$(BINPATH) :
	mkdir $@

mrproper:
	@rm $(BINPATH)/*
