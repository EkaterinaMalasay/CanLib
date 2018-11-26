CC = g++

INCLUDE = -I../include
BINDIR = -I../build

all: CanLib

caninterface.o: caninterface.cpp
	$(CC) -c -o caninterface.o caninterface.cpp
canframe.o: canframe.cpp
	$(CC) -c -o canframe.o canframe.cpp
main.o: main.cpp caninterface.cpp canframe.cpp
	$(CC) -c -o main.o main.cpp
CanLib: main.o caninterface.o canframe.o
	$(CC) -o CanLib main.o caninterface.o canframe.o

clean:
	rm -f *.o