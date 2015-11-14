#include "ArmyAntQueen.h"

ArmyAntQueen::ArmyAntQueen(Game* game, int player, int position): Animal(game,player,position){
  hp = MAX_HP;
  atk_damage = DEFAULT_ATK_DAMAGE;
  name = "Army Ant(Queen)";
  type = ANT;
}

ArmyAntQueen::~ArmyAntQueen() {
	
}

void ArmyAntQueen::attack()
{

}

void ArmyAntQueen::defend(Animal* opponent, int damage) {
  takeDamage(damage);
  for (int i = 0; i < 5; ++i) {
    if (allies[i]->getName() == "Army Ant" && !(allies[i]->isDead()))
      opponent->takeDamage(2);
  }
}

void ArmyAntQueen::marchAndConquer() {
  for (int i = 0; i < 5; ++i) {
    if (i != pos)
      allies[i]->heal(2);
  }
}

void ArmyAntQueen::heal(int heal_amount) {
  if (!isDead()) {
    hp += heal_amount;
    if (hp > MAX_HP)
      hp = MAX_HP;
  }
}
