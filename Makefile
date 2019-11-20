CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := main
CFLAGS := -g -Wall -O3 -std=c++14 -I include/


all: main

poker:
	@mkdir build/poker/
	$(CC) $(CFLAGS) -c #src/classes/Pote.cpp -o build/classes/Pote.o

main: poker
	$(CC) $(CFLAGS) #build/classes/Pote.o src/main.cpp -o main


clean:
	$(RM) -r $(BUILDDIR)/* $(TARGET)