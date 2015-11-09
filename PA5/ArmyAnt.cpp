#include "ArmyAnt.h"

ArmyAnt::ArmyAnt(Game* game, int player, int position): Animal(game,player,position){
  hp = MAX_HP;
  atk_damage = DEFAULT_ATK_DAMAGE;
  name = "Army Ant";
  type = Type::ANT;
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
  for (int i = 0; i < 5; ++i) {
    enemies[i]->takeDamage(3);
  }    
}

void ArmyAnt::heal(int heal_amount) {
  if (!isDead()) {
    hp += heal_amount;
    if (hp > MAX_HP)
      hp = MAX_HP;
  }
}



