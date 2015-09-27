all: permutation

permutation: permutation.o
	g++ -o permutation permutation.o
	rm -f *~ *.o core

permutation.o: permutation.cpp
	g++ -c permutation.cpp -g

clean:
	rm -f *~ *.o permutation core