# Paths
BINNAME=parser
ISLIBRARY=no

BINPATH=./bin
LIBPATH=./lib
OBJPATH=./obj
SRCPATH=./src
STATICLIBS=../xml/bin/libxmlstruct.a ../dtd/bin/libdtdstruct.a ../AnalyseurXML/bin/libxmlparser.a ../AnalyseurDTD/bin/libdtdparser.a ../xsl/bin/libxslstruct.a
TESTPATH=./tests
TESTBINNAME=./do_test.sh

EXTRA_INCLUDES=./libs_rebuild.mk

# Build
CXX=g++
CXXFLAGS=-ansi -pedantic -W -Wall -I../AnalyseurXML/src -I../AnalyseurDTD/src -I../xml/src -I../dtd/src -I../xsl/src
LD=g++
LDFLAGS=-L$(LIBPATH)
LIBLD=ar
LIBLDFLAGS=cr

SRCS=$(shell find $(SRCPATH) -type f -regex '.*\.cpp')

