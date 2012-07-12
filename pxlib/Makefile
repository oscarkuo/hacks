CC=gcc
CFLAGS=-std=c11 -Iinc -Wall
LFLAGS=-Llib -lpx -liconv -lgettextlib -lintl
SOURCES=pxrc.c
OUTPUTS=pxrc
OBJECTS=$(SOURCES:.c=.o)

all: bin/pxrc

bin/%: out/%.o
	$(CC) $< -o $@ $(LFLAGS)

out/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@
