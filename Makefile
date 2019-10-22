CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := main
CFLAGS := -g -Wall -O3 -std=c++14 -I include/


all: main

poker:
	@mkdir build/poker/
	$(CC) $(CFLAGS) -c #src/magic/carta.cpp -o build/magic/carta.o

main: poker
	$(CC) $(CFLAGS) #build/magic/carta.o build/uno/carta.o src/main.cpp -o main


clean:
	$(RM) -r $(BUILDDIR)/* $(TARGET)