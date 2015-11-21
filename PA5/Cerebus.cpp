#include "Cerebus.h"

Cerebus::Cerebus(Game* game, int player, int position): Animal(game,player,position){
  hp = MAX_HP;
  atk_damage = DEFAULT_ATK_DAMAGE;
  name = "Cerebus";
  type = DOG;
  is_legendary = true;
}

Cerebus::~Cerebus() {
	
}

void Cerebus::attack()
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

void Cerebus::frenzy() {
  if (!isDead()) { // Ensure Cerebus isn't dead.
    // Deal 2 unblockable damage to each enemy.
    for (int i = 0; i < 5; ++i)
      enemies[i]->takeDamage(2);
  }
}

void Cerebus::weatherTheStorm() {
  if (!isDead()) { // Ensure Cerebus isn't dead.
    // Deal 3 unblockable damage to each enemy.
    for (int i = 0; i < 5; ++i)
      enemies[i]->takeDamage(3);
  }
}  
