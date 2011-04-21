# Paths
BINNAME=xmlparser
ISLIBRARY=yes

BINPATH=./bin
LIBPATH=./lib
OBJPATH=./obj
SRCPATH=./src
STATICLIBS=
TESTPATH=./tests
TESTBINNAME=make run

EXTRA_INCLUDES=../generic_lex_yacc_makefile

# Build
CXX=g++
CXXFLAGS=-ansi -pedantic -W -Wall -I../xml/src
ifdef DEBUG
	CXXFLAGS:=$(CXXFLAGS) -DYYDEBUG
endif
LD=g++
LDFLAGS=-L$(LIBPATH)
LIBLD=ar
LIBLDFLAGS=cr

# Lex & Yacc
LEX=flex
YACC=bison
LEXPREFIX=xml
YACCPREFIX=xml

include ../generic_lex_yacc_settings

# Sources
SRCS=$(shell find $(SRCPATH) -type f -regex '.*\.cpp') $(LEXTARGET) $(YACCTARGET)
