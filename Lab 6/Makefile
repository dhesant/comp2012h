all: reverselist

reverselist: reverselist.o
	g++ -o reverselist reverselist.o
	rm -f *~ *.o core

reverselist.o: reverselist.cpp
	g++ -c reverselist.cpp -g

clean:
	rm -f *~ *.o reverselist core