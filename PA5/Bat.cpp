#include "Bat.h"

Bat::Bat(Game* game, int player, int position): Animal(game,player,position){
  hp = MAX_HP;
  atk_damage = DEFAULT_ATK_DAMAGE;
  name = "Bat";
  type = FLYING;
}

Bat::~Bat() {
	
}

void Bat::attack()
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

  // Heal itself 1 HP if below MAX_HP.
  if (!isDead() && hp < MAX_HP)
    hp++;
}

void Bat::defend(Animal* opponent, int damage) {
  // Only take 80% damage.
  takeDamage(0.8*damage);
}

void Bat::harass() {
  if (!isDead()) { // Ensure Bat isn't dead.
    // Deal 1 unblockable damage to each enemy.
    for (int i = 0; i < 5; ++i)
      enemies[i]->takeDamage(1);
    // Heal itself 1 HP if below MAX_HP.
    if (hp < MAX_HP) 
      hp++;
  }
}
