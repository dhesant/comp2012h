all: blackjack

blackjack: blackjack.o
	g++ -o blackjack blackjack.o
	rm -f *~ *.o core

blackjack.o: blackjack.cpp
	g++ -c blackjack.cpp -g

clean:
	rm -f *~ *.o blackjack core