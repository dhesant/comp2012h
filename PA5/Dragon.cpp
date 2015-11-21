#include "Dragon.h"

Dragon::Dragon(Game* game, int player, int position): Animal(game,player,position){
  hp = MAX_HP;
  atk_damage = DEFAULT_ATK_DAMAGE;
  name = "Dragon";
  type = FLYING;
  is_legendary = true;
}

Dragon::~Dragon() {
	
}

void Dragon::attack()
{
  // Attack the 3 closest enemies in a cone.
  for (int i = -1; i <= 1; ++i) {
    if (pos-i >=0 && pos-i < 5) // Ensure input is in the valid range
      enemies[pos-i]->defend(this, atk_damage);
  }
}

void Dragon::defend(Animal* opponent, int damage) {
  // Only take 80% damage.
  takeDamage(0.8*damage);
}

void Dragon::harass() {
  if (!isDead()) { // Ensure Dragon isn't dead.
    // Deal 2 unblockable damage to each enemy.
    for (int i = 0; i < 5; ++i)
      enemies[i]->takeDamage(2);
  }
}

void Dragon::weatherTheStorm() {
  if (!isDead()) { // Ensure Dragon isn't dead.
    // Deal 3 unblockable damage to each enemy.
    for (int i = 0; i < 5; ++i)
      enemies[i]->takeDamage(3);
  }
}
