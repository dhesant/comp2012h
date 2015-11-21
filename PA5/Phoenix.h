#ifndef PHOENIX_H_
#define PHOENIX_H_

#include "Animal.h"

class Phoenix: public Animal {
 public:
  Phoenix(Game* game, int player, int position);
  virtual ~Phoenix();

  virtual void attack();
  virtual void defend(Animal* opponent, int damage);
  virtual void takeDamage(int damage);

  virtual void harass();
  virtual void weatherTheStorm();

 private:
  static const int MAX_HP = 20;
  static const int DEFAULT_ATK_DAMAGE = 4;
  bool has_revived;
};

#endif /* PHOENIX_H_ */
