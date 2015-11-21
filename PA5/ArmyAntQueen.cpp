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
  // Army ants do not have any attack, and do not trigger the opponents defend function.
}

void ArmyAntQueen::defend(Animal* opponent, int damage) {
  takeDamage(damage);
  // Implement revenge function, all other Ants deal 2 unblockable damage.
  for (int i = 0; i < 5; ++i) {
    if (allies[i]->getName() == "Army Ant" && !(allies[i]->isDead()))
      opponent->takeDamage(2);
  }
}

void ArmyAntQueen::marchAndConquer() {
  if (!isDead()) { // Ensure Ant Queen is not dead.
    // Heal all ants by 2 health.
    for (int i = 0; i < 5; ++i) {
      if (i != pos) // Ant Queen cannot heal herself
	allies[i]->heal(2);
    }
  }
}

// This function should not be used in game, since there cannot be 2 queens on one team at once.
void ArmyAntQueen::heal(int heal_amount) {
  if (!isDead()) { // Ensure Ant queen is not dead.
    // Heal by heal_amount.
    hp += heal_amount;
    // Ensure HP does not exceed MAX_HP.
    if (hp > MAX_HP)
      hp = MAX_HP;
  }
}
