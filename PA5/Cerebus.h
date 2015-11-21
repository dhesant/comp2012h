#ifndef CEREBUS_H_
#define CEREBUS_H_

#include "Animal.h"

class Cerebus: public Animal {
 public:
  Cerebus(Game* game, int player, int position);
  virtual ~Cerebus();

  virtual void attack();
  virtual void frenzy();
  virtual void weatherTheStorm();

 private:
  static const int MAX_HP = 40;
  static const int DEFAULT_ATK_DAMAGE = 5;
};

#endif /* CEREBUS_H_ */
