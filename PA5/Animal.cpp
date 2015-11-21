/**
 *  You SHOULD NOT modify this file
 */
#include "Animal.h"

Animal::Animal(Game* game, int player, int position) {
  allies = game->animals[player];
  enemies = game->animals[!player];
  pos = position;
  is_dead = false;

  // Additional variables for special moves
  type = NORMAL; // int type is usually NORMAL, replaced by FLYING, SWIMMING, ANT, and DOG depending on animal.
  is_legendary = false; // is usually false, replaced with true for legenday animal.
}

Animal::~Animal() {
	
}


void Animal::defend(Animal* opponent, int damage) {
  takeDamage(damage);
}

void Animal::die() {
  is_dead = true;
}

void Animal::takeDamage(int damage) {
  hp -= damage;
  if( hp <= 0 )
    die();
}

bool Animal::isDead() const {
  return is_dead;
}

std::string Animal::getName() const {
  return name;
}

int Animal::getCurrentHP() const {
  return hp;
}

/*
 * Functions to implement special moves
 */

// Return the type int of the animal.
int Animal::getType() const {
  return type;
}

// Harass special move, usually blank.
void Animal::harass() {
  
}

// Summon Tsunami special move, usually blank.
void Animal::summonTsunami() {

}

// March & Conquer special move, usually blank.
void Animal::marchAndConquer() {

}

// Heal for use with Army Ant March & Conquer, usually blank.
void Animal::heal(int heal_amount) {

}

/*
 * Functions to implement the bonus
 */

// Return whether the animal is a legendary animal or not.
bool Animal::isLegendary() const {
  return is_legendary;
}

// Frenzy special move, usually blank.
void Animal::frenzy() {

}

// Weather the Storm special move, usually blank.
void Animal::weatherTheStorm() {

}
