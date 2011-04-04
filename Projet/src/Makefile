all:
	@cd AnalyseurXML/ && make && cp bin/analyseXML ../bin
	@cd AnalyseurDTD/ && make && cp bin/analyseDTD ../bin
	@cd xml/ && make
	@cd dtd/ && make
	
test: all
	@cd AnalyseurXML/ && make test
	@cd AnalyseurDTD/ && make test
	@cd xml/ && make test
	@cd dtd/ && make test
	# TODO : ajouter tests d'intégration
	
