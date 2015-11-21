#include <iostream>
#include <fstream>

// Load all the necessary headerf files
#include "Game.h"
#include "Dog.h"
#include "Cat.h"
#include "Hawk.h"
#include "Bat.h"
#include "Turtle.h"
#include "Shark.h"
#include "ArmyAnt.h"
#include "ArmyAntQueen.h"
#include "Dragon.h"
#include "Phoenix.h"
#include "Cerebus.h"

using namespace std;

Game::Game(std::string file) {
  load(file);
}

Game::~Game() {
  for(int i = 0; i < 10; i++)
    delete animals[i/5][i%5];
}

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
	  animals[c/5][c%5] = new Cat(this, c/5, c%5);
	  break;
	case HAWK:
	  animals[c/5][c%5] = new Hawk(this, c/5, c%5);
	  break;
	case BAT:
	  animals[c/5][c%5] = new Bat(this, c/5, c%5);
	  break;
	case TURTLE:
	  animals[c/5][c%5] = new Turtle(this, c/5, c%5);
	  break;
	case SHARK:
	  animals[c/5][c%5] = new Shark(this, c/5, c%5);
	  break;
	case ARMY_ANT:
	  animals[c/5][c%5] = new ArmyAnt(this, c/5, c%5);
	  break;
	case ARMY_ANT_QUEEN:
	  animals[c/5][c%5] = new ArmyAntQueen(this, c/5, c%5);
	  break;
	case DRAGON:
	  animals[c/5][c%5] = new Dragon(this, c/5, c%5);
	  break;
	case PHOENIX:
	  animals[c/5][c%5] = new Phoenix(this, c/5, c%5);
	  break;
	case CEREBUS:
	  animals[c/5][c%5] = new Cerebus(this, c/5, c%5);
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

      // After the attack phase, check and run the special moves.

      // Harass special move, requires >2 flying animals.
      if (countFlying(currentPlayer) > 2) {
	std::cout << "Player " << currentPlayer+1 << " has harassed the other player." << std::endl; // Send message to cout for effect.
	for (int i = 0; i < 5; ++i)
	  animals[currentPlayer][i]->harass();
      }
      
      // Summon Tsunami special move, requires >2 swimming animals.
      if (countSwimming(currentPlayer) > 2) {
	std::cout << "Player " << currentPlayer+1 << " has summoned a Tsunami." << std::endl; // Send message to cout for effect.
	for (int i = 0; i < 5; ++i)
	  animals[currentPlayer][i]->summonTsunami();
      }
      
      // March and Conquer special move, requires 5 Ants.
      if (countArmyAnt(currentPlayer) >= 5) {
	std::cout << "Player " << currentPlayer+1 << "'s Ant Army has marched and conquered." << std::endl; // Send message to cout for effect.
	for (int i = 0; i < 5; ++i)
	  animals[currentPlayer][i]->marchAndConquer();
      }

      // Frenzy special move, requires >2 Dogs with at least 1 Cerebus.
      if (countDog(currentPlayer) > 2) {
	std::cout << "Player " << currentPlayer+1 << "'s Dogs have entered a frenzy." << std::endl; // Send message to cout for effect.
	for (int i = 0; i < 5; ++i)
	  animals[currentPlayer][i]->frenzy();
      }

      // Weather the storn special move, requires >2 legendary animals.
      if (countLegendary(currentPlayer) > 2) {
	std::cout << "Player " << currentPlayer+1 << "'s Legendary Animals have kicked up a storm." << std::endl; // Send message to cout for effect.
	for (int i = 0; i < 5; ++i)
	  animals[currentPlayer][i]->weatherTheStorm();
      }

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

/*
 * Helper functions
 */

// Count flying animals using getType()
int Game::countFlying(int player) {
  int count = 0;
  for (int i = 0; i < 5; ++i) {
    if (animals[player][i]->getType() == Animal::FLYING && !animals[player][i]->isDead())
      count++;
  }
  return count;
}

// Count swimming animals using getType()
int Game::countSwimming(int player) {
  int count = 0;
  for (int i = 0; i < 5; ++i) {
    if (animals[player][i]->getType() == Animal::SWIMMING && !animals[player][i]->isDead())
      count++;
  }
  return count;
}

// Count Ants using getType()
int Game::countArmyAnt(int player) {
  int count = 0;
  for (int i = 0; i < 5; ++i) {
    if (animals[player][i]->getType() == Animal::ANT && !animals[player][i]->isDead())
      count++;
  }
  return count;
}

// Count legendary animals using getType()
int Game::countLegendary(int player) {
  int count = 0;
  for (int i = 0; i < 5; ++i)
    count += (animals[player][i]->isLegendary() && !animals[player][i]->isDead());
  return count;
}

// Count dog animals using getType()
int Game::countDog(int player) {
  int count = 0;
  // Check to see whether there is at least one Cerebus.
  for (int i = 0; i < 5; ++i) {
    if (animals[player][i]->getName() == "Cerebus") {
      for (int j = 0; j < 5; ++j) {
	if (animals[player][j]->getType() == Animal::DOG && !animals[player][j]->isDead())
	  count++;
      }
      // Return here to ensure that the loop does not repeat.
      return count;
    }
  }
  return count;
}

