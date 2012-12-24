CC=gcc
CFLAGS=-std=c11 -Iinc -Wall
LFLAGS=-Llib -lpx -liconv -lgettextlib -lintl
SOURCES=pxrc.c
OUTPUTS=pxrc
OBJECTS=$(SOURCES:.c=.o)

all: bin/pxrc bin/pxst bin/pxgt

bin/%: out/%.o
	-mkdir -p bin
	$(CC) $< -o $@ $(LFLAGS)

out/%.o: src/%.c
	-mkdir -p out
	$(CC) $(CFLAGS) -c $< -o $@
