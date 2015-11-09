#ifndef SHARK_H_
#define SHARK_H_

#include "Animal.h"

class Shark: public Animal {
 public:
  Shark(Game* game, int player, int position);
  virtual ~Shark();

  virtual void attack();
  virtual void defend(Animal* opponent, int damage);

  virtual void summonTsunami();

 private:
  static const int MAX_HP = 30;
  static const int DEFAULT_ATK_DAMAGE = 7;
};

#endif /* SHARK_H_ */
