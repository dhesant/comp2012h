#include <iostream>
#include <fstream>

#include "Game.h"
#include "Dog.h"

/*
 * Remember to include the header file of the animal classes here
 */

using namespace std;

Game::Game(std::string file) {
	load(file);
}

Game::~Game() {
	for(int i = 0; i < 10; i++)
		delete animals[i/5][i%5];
}

/**
 * You should instantiate the animal objects here
 * Please refer to the example of "Dog" 
 */
void Game::load(std::string file)
{
	ifstream in(file.c_str());
	int c = 0;
	int id;
	while(in >> id)
	{
		switch(id)
		{
		case DOG:
			animals[c/5][c%5] = new Dog(this, c/5, c%5);
			break;
		case CAT:
			break;
		case HAWK:
			break;
		case BAT:
			break;
		case TURTLE:
			break;
		case SHARK:
			break;
		case ARMY_ANT:
			break;
		case ARMY_ANT_QUEEN:
			break;
		case DRAGON:
			break;
		}

		c++;
	}

}

/**
 * Do NOT modify this function
 */
bool Game::isEnd()
{
	int deadCount1 = 0;
	int deadCount2 = 0;
	for(int i = 0; i < 5; i++)
	{
		deadCount1 += animals[P1][i]->isDead();
		deadCount2 += animals[P2][i]->isDead();
	}

	if(deadCount1 == 5 && deadCount2 == 5)
	{
		cout << "Draws!" << endl;
	}else if (deadCount1 == 5)
	{
		cout << "Player " << P2+1 << " Wins!" << endl;
	} else if (deadCount2 == 5)
	{
		cout << "Player " << P1+1 << " Wins!" << endl;
	} else {
		return false;
	}
	return true;

}

void Game::start()
{
	Player currentPlayer = P1;
	int turnCount = 1;
	while(!isEnd())
	{
		for(int i = 0; i < 5; i++)
		{
			if(!animals[currentPlayer][i]->isDead())
				animals[currentPlayer][i]->attack();
		}

		/**
		 * To-Do 2: Codes for Special moves (if any) should be written here
		 * Hint: You should use dynamic binding, you may add data members/ functions in the Game class to help you implement this part
		 */


		//Output turn info
		cout << "Turn " << turnCount++ << " Player " << currentPlayer+1 << " attacks:" << endl;
		cout << "Player 1" << endl;
		for(int i = 0; i < 5; i++)
		{
			if(!animals[P1][i]->isDead())
				cout << animals[P1][i]->getName() << ":"
				<< animals[P1][i]->getCurrentHP() << " ";
			else
				cout << animals[P1][i]->getName() << ":"
				<< "DEAD" << " ";
		}
		cout << endl;
		cout << "Player 2" << endl;
		for(int i = 0; i < 5; i++)
		{
			if(!animals[P2][i]->isDead())
				cout << animals[P2][i]->getName() << ":"
				<< animals[P2][i]->getCurrentHP() << " ";
			else
				cout << animals[P2][i]->getName() << ":"
				<< "DEAD" << " ";
		}
		cout << endl;


		//Switch player turn
		if(currentPlayer == P1)
			currentPlayer = P2;
		else
			currentPlayer = P1;
	}
}
