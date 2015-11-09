#ifndef BAT_H_
#define BAT_H_

#include "Animal.h"

class Bat: public Animal {
 public:
  Bat(Game* game, int player, int position);
  virtual ~Bat();

  virtual void attack();

 private:
  static const int MAX_HP = 20;
  static const int DEFAULT_ATK_DAMAGE = 4;
};

#endif /* BAT_H_ */
