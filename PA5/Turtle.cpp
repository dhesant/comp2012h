#include "Turtle.h"

Turtle::Turtle(Game* game, int player, int position): Animal(game,player,position){
  hp = MAX_HP;
  atk_damage = DEFAULT_ATK_DAMAGE;
  name = "Turtle";
  type = Type::SWIMMING;
}

Turtle::~Turtle() {
	
}

void Turtle::attack()
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

void Turtle::defend(Animal* opponent, int damage) {
  takeDamage(0.5*damage);
}

void Turtle::summonTsunami() {
  for (int i = 0; i < 5; ++i)
    enemies[i]->takeDamage(1);
}
