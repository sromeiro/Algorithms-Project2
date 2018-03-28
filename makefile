all: main

main: main.o
	g++ -Wall main.o -o main

main.o: main.cpp
	g++ -Wall -c main.cpp

clean:
	rm -rf *o main
