CC=gcc
CFLAGS=-I.
AR=ar
FLAGS= -Wall -g
DEPS = myBank.h
OBJECTS_MAIN=main.o
OBJECTS_LIB= myBank.o

all:main

main:$(OBJECTS_MAIN) libmyBank.a
	$(CC) $(FLAGS) -o main $(OBJECTS_MAIN) libmyBank.a

libmyBank.a: $(OBJECTS_LIB) 
	$(AR) -rcs libmyBank.a $(OBJECTS_LIB)

%.o: %.c $(DEPS)
	$(CC) -fPIC $(FLAG) -c -o $@ $< $(CFLAGS)

.PHONY:

clean:
	rm -f *.o *.a results.txt main *.gch *.so exe