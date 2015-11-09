#ifndef HAWK_H_
#define HAWK_H_

#include "Animal.h"

class Hawk: public Animal {
 public:
  Hawk(Game* game, int player, int position);
  virtual ~Hawk();

  virtual void attack();

 private:
  static const int MAX_HP = 25;
  static const int DEFAULT_ATK_DAMAGE = 5;
};

#endif /* HAWK_H_ */
