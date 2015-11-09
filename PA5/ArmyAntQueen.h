#ifndef ARMY_ANT_QUEEN_H_
#define ARMY_ANT_QUEEN_H_

#include "Animal.h"

class ArmyAntQueen: public Animal {
 public:
  ArmyAntQueen(Game* game, int player, int position);
  virtual ~ArmyAntQueen();

  virtual void attack();
  virtual void defend(Animal* opponent, int damage);

  void marchAndConquer();
  void heal(int heal_amount);
  
 private:
  static const int MAX_HP = 15;
  static const int DEFAULT_ATK_DAMAGE = 0;
};

#endif /* ARMY_ANT_QUEEN_H_ */
