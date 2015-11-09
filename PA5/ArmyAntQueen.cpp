#include "ArmyAntQueen.h"

ArmyAntQueen::ArmyAntQueen(Game* game, int player, int position): Animal(game,player,position){
  hp = MAX_HP;
  atk_damage = DEFAULT_ATK_DAMAGE;
  name = "Army Ant Queen";

}

ArmyAntQueen::~ArmyAntQueen() {
	
}

void ArmyAntQueen::attack()
{

}

void ArmyAntQueen::defend(Animal* opponent, int damage) {
  takeDamage(damage);
  for (int i = 0; i < 5; ++i) {
    if (allies[pos]->getName() == "Army Ant" && !(allies[pos]->isDead()))
      opponent->takeDamage(2);
  }
}
