#ifndef ARMY_ANT_H_
#define ARMY_ANT_H_

#include "Animal.h"

class ArmyAnt: public Animal {
 public:
  ArmyAnt(Game* game, int player, int position);
  virtual ~ArmyAnt();

  virtual void attack();

  virtual void marchAndConquer();
  void heal(int heal_amount);

 private:
  static const int MAX_HP = 15;
  static const int DEFAULT_ATK_DAMAGE = 1;
};

#endif /* ARMY_ANT_H_ */
