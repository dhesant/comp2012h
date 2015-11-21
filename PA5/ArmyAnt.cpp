#include "ArmyAnt.h"

ArmyAnt::ArmyAnt(Game* game, int player, int position): Animal(game,player,position){
  hp = MAX_HP;
  atk_damage = DEFAULT_ATK_DAMAGE;
  name = "Army Ant";
  type = ANT;
}

ArmyAnt::~ArmyAnt() {
	
}

void ArmyAnt::attack()
{
  if(!enemies[pos]->isDead())
    enemies[pos]->defend(this, atk_damage);
  else {
    for(int i = 1; i < 5; i++)
      {
	if(pos-i >= 0 && !enemies[pos-i]->isDead())
	  {
	    enemies[pos-i]->defend(this, atk_damage);
	    break;
	  }
	else if(pos+i < 5 && !enemies[pos+i]->isDead())
	  {
	    enemies[pos+i]->defend(this, atk_damage);
	    break;
	  }
      }
  }
}

void ArmyAnt::marchAndConquer() {
  if (!isDead()) { // Ensure Ant isn't dead.
    // Deal 2 unblockable damage to each enemy.
    for (int i = 0; i < 5; ++i)
      enemies[i]->takeDamage(3);
  }    
}

void ArmyAnt::heal(int heal_amount) {
  if (!isDead()) { // Ensure Ant isn't dead.
    hp += heal_amount; // Heal by the heal_amount.
    // Ensure HP is not over MAX_HP.
    if (hp > MAX_HP)
      hp = MAX_HP;
  }
}



