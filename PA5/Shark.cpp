#include "Shark.h"

Shark::Shark(Game* game, int player, int position): Animal(game,player,position){
  hp = MAX_HP;
  atk_damage = DEFAULT_ATK_DAMAGE;
  name = "Shark";
  type = SWIMMING;
}

Shark::~Shark() {
	
}

void Shark::attack()
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

  // Deal itself 1 damage.
  takeDamage(1);
}

void Shark::defend(Animal* opponent, int damage) {
  takeDamage(damage);
  //  Deal 2 unblockable damage as revenge.
  if (!isDead())
    opponent->takeDamage(2);
}

void Shark::summonTsunami() {
  if (!isDead()) { // Ensure shark isn't dead
    // Deal 2 unblockable damage to each enemy.
    for (int i = 0; i < 5; ++i)
      enemies[i]->takeDamage(2);
    takeDamage(2); // Deal itself 1 damage.
  }
}
