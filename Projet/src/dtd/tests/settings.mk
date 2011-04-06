# Paths
BINNAME=dtdstructtest
ISLIBRARY=no

BINPATH=./bin
LIBPATH=./lib
OBJPATH=./obj
SRCPATH=./src
STATICLIBS=../bin/libdtdstruct.a
TESTPATH=./tests
TESTBINNAME=

# Build
CXX=g++
CXXFLAGS=-ansi -pedantic -W -Wall -I../src -I../../xml/src
LD=g++
LDFLAGS=-L$(LIBPATH)
LIBLD=ar
LIBLDFLAGS=cr

SRCS=$(shell find $(SRCPATH) -type f -regex '.*\.cpp')

