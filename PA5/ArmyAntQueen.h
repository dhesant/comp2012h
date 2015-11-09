#ifndef ARMYANTQUEEN_H_
#define ARMYANTQUEEN_H_

#include "Animal.h"

class ArmyAntQueen: public Animal {
 public:
  ArmyAntQueen(Game* game, int player, int position);
  virtual ~ArmyAntQueen();

  virtual void attack();

 private:
  static const int MAX_HP = 15;
  static const int DEFAULT_ATK_DAMAGE = 0;
};

#endif /* ARMYANTQUEENo_H_ */
