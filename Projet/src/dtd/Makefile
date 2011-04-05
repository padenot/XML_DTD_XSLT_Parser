## Manual settings

# Paths
BINNAME=dtdstruct
ISLIBRARY=yes

BINPATH=./bin
LIBPATH=./lib
OBJPATH=./obj
SRCPATH=./src
STATICLIBS=
TESTPATH=./test
TESTBINNAME=dtdstructtest

# Build
CXX=g++
CXXFLAGS=-ansi -pedantic -W -Wall
LD=g++
LDFLAGS=-L$(LIBPATH)
LIBLD=ar
LIBLDFLAGS=cr

SRCS=$(shell find $(SRCPATH) -type f -regex '.*\.cpp')

## Auto settings
ifneq ($(ISLIBRARY),yes)
	BIN=$(BINPATH)/$(BINNAME)
else
	BIN=$(BINPATH)/lib$(BINNAME).a
endif

OBJS=$(shell echo $(SRCS) | sed 's,\([^[:space:]]\+/\)\?\([^[:space:]/]\+\)\.[^[:space:]\.]\+,$(OBJPATH)/\2\.o,g')
#OBJS=$(patsubst $(SRCPATH)/%.cpp,$(OBJPATH)/%.o, $(SRCS))

ifdef DEBUG
	CXXFLAGS:=-g $(CXXFLAGS)
else
	CXXFLAGS:=-DNDEBUG $(CXXFLAGS)
endif

## 'all' rule
all: $(BIN)
ifdef DEBUG
	@echo "************ DEBUG ************"
else
	@echo "*********** RELEASE ***********"
endif
	@echo -e 'Binary :\n$(BIN)'


## Tools
cleano:
	rm -f $(OBJPATH)/*.o

cleand:
	rm -f $(OBJPATH)/*.d

cleanbin:
	rm -f $(BIN)

clean: cleano cleand

mrproper: clean cleanbin

rebuild: cleano cleanbin all

run: $(BIN) 
ifneq ($(ISLIBRARY),yes)
	@cd $(BINPATH) && ./$(BINNAME)
else
	@echo "$(BINPATH)/$(BINNAME) is a library and thus cannot be executed."
endif

test: | $(TESTPATH)
	@cd $(TESTPATH) ; make run

.PHONY: all cleano cleand cleanbak cleanbin clean mrproper rebuild run test

## Generic rules
# Binaries dependencies
ifneq ($(ISLIBRARY),yes)
$(BIN): $(OBJS) $(STATICLIBS) | $(BINPATH) $(LIBPATH)
	$(LD) $(LDFLAGS) -o $@ $^
else
$(BIN): $(OBJS) | $(BINPATH)
	$(LIBLD) $(LIBLDFLAGS) $@ $^
endif

# Objects generation
$(OBJPATH)/%.o: $(SRCPATH)/%.cpp | $(OBJPATH)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

# Directories
$(BINPATH) $(OBJPATH) $(LIBPATH) $(TESTPATH):
	mkdir $@

## Dependencies
ifeq ($(DEPENDSFILE),)
# Depends files generation
$(OBJPATH)/%.d: $(SRCPATH)/%.cpp | Makefile $(OBJPATH)
	@echo "Generating prerequisites file for $<"
	@set -e; rm -f $@; \
		$(CXX) -MM $(CXXFLAGS) $< | \
		sed 's,\(^.*\)\.o *:,$$(OBJPATH)/\1.o $@ : \\\n ,g' > $@; \
		rm -f $@.$$$$

-include $(OBJS:.o=.d)
else
# Depends file
include $(DEPENDSFILE)
endif

