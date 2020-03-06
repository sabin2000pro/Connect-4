CC = cc
CFLAGS = -std=c99 -pedantic -Wall
OBJECTS = ConnectFour.o test.o

all: ConnectFour.c

clean:
	rm -f *.o ConnectFour.c