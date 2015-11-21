/**
 *  You SHOULD NOT modify this file
 */
#ifndef ANIMAL_H_
#define ANIMAL_H_
#include <string>

#include "Game.h"

class Game;

class Animal {
 public:
  virtual ~Animal();

  virtual void attack() = 0;
  virtual void defend(Animal* opponent, int damage);

  virtual void takeDamage(int damage);
  void die();
  bool isDead() const;
  std::string getName() const;
  int getCurrentHP() const;
  bool isLegendary() const;

  // Special moves
  enum AnimalTypes { NORMAL, FLYING, SWIMMING, ANT, DOG };

  virtual void harass();
  virtual void summonTsunami();
  virtual void marchAndConquer();
  virtual void heal(int heal_amount);
  int getType() const;

  // Bonus
  virtual void frenzy();
  virtual void weatherTheStorm();

 protected:
  int hp;
  int atk_damage;
  bool is_dead;
  int pos;
  std::string name;
  Animal** allies;
  Animal** enemies;

  Animal(Game *game, int player, int position);

  // Special move functions
  int type;

  // Bonus Functions
  bool is_legendary;
};

#endif /* ANIMAL_H_ */
