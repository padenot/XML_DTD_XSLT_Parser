../xml/bin/libxmlstruct.a: $(shell find ../xml/src -type f)
	cd ../xml && make

../dtd/bin/libdtdstruct.a: $(shell find ../dtd/src -type f)
	cd ../dtd && make

../AnalyseurXML/bin/libxmlparser.a: $(shell find ../AnalyseurXML/src -type f)
	cd ../AnalyseurXML && make

../AnalyseurDTD/bin/libdtdparser.a: $(shell find ../AnalyseurDTD/src -type f)
	cd ../AnalyseurDTD && make

