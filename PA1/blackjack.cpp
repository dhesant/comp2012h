#include <iostream> 
#include <stdlib> 
#include <time> 
using namespace std;

int main(){ 
  int cardNumber;

  srand(time(0));  // initialize random number generator 
  cardNumber = (double) rand()/RAND_MAX * 13;  // picks a random card number between 1 and 13 
}

