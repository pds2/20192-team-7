#CC := g++
#SRCDIR := src
#BUILDDIR := build
#TARGET := main
#CFLAGS := -g -Wall -O3 -std=c++14 -I include/


CC := g++
SRCDIR := src
TSTDIR := tests
OBJDIR := build
BINDIR := bin

MAIN := classes/dealer.cpp
#TESTER := program/tester.cpp

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
#TSTSOURCES := $(shell find $(TSTDIR) -type f -name *.$(SRCEXT))

CFLAGS := -g -Wall -O3 -std=c++14
INC := -I include/ -I

$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

#main: $(OBJECTS)
#	@mkdir -p $(BINDIR)
#	$(CC) $(CFLAGS) $(INC) $(MAIN) $^ -o $(BINDIR)/main

#tests: $(OBJECTS)
#	@mkdir -p $(BINDIR)
#	$(CC) $(CFLAGS) $(INC) $(TESTER) $(TSTSOURCES) $^ -o $(BINDIR)/tester
#	$(BINDIR)/tester

#all: main

#run: main
#	$(BINDIR)/main

clean:
	$(RM) -r $(OBJDIR)/* $(BINDIR)/*

.PHONY: clean coverage