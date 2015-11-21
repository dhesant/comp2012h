#include "Phoenix.h"

Phoenix::Phoenix(Game* game, int player, int position): Animal(game,player,position){
  hp = MAX_HP;
  atk_damage = DEFAULT_ATK_DAMAGE;
  name = "Phoenix";
  type = FLYING;
  is_legendary=true;
  has_revived=false;
}

Phoenix::~Phoenix() {
	
}

void Phoenix::attack()
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

void Phoenix::defend(Animal* opponent, int damage) {
  takeDamage(0.8*damage);
}

void Phoenix::harass() {
  if (!isDead()) {
    for (int i = 0; i < 5; ++i)
      enemies[i]->takeDamage(1);
  }
}

void Phoenix::takeDamage(int damage) {
  hp -=damage;
  if ( hp <= 0 ) {
    if ( has_revived )
      die();
    else {
      hp = MAX_HP;
      has_revived = true;
    }
  }
}

void Phoenix::weatherTheStorm() {
  if (!isDead()) {
    for (int i = 0; i < 5; ++i)
      enemies[i]->takeDamage(3);
  }
}  
