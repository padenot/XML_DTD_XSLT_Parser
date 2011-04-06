# Paths
BINNAME=xmlstructtest
ISLIBRARY=no

BINPATH=./bin
LIBPATH=./lib
OBJPATH=./obj
SRCPATH=./src
STATICLIBS=../bin/libxmlstruct.a
TESTPATH=./tests
TESTBINNAME=make run

# Build
CXX=g++
CXXFLAGS=-ansi -pedantic -W -Wall -I../src
LD=g++
LDFLAGS=-L$(LIBPATH)
LIBLD=ar
LIBLDFLAGS=cr

SRCS=$(shell find $(SRCPATH) -type f -regex '.*\.cpp')

