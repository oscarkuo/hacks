CC=g++
CFLAGS=-Wall
LFLAGS=-Iinc
SOURCES=concept_requires.cc
OUTPUTS=concept_requires
OBJECTS=$(SOURCES:.cc=.o)

all: bin/concept_requires 

bin/%: out/%.o
	-mkdir -p bin
	$(CC) $< -o $@ $(LFLAGS)

out/%.o: src/%.cc
	-mkdir -p out
	$(CC) $(CFLAGS) -c $< -o $@
