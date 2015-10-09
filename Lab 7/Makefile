all: main

main: main.o date.o
	g++ -o main main.o date.o
	rm -f *~ *.o core

main.o: main.cpp
	g++ -c main.cpp -g

date.o: date.h date.cpp
	g++ -c date.cpp -g

clean:
	rm -f *~ *.o main core