#include <iostream> 
#include <cstdlib> 
#include <ctime> 

const char *number_lookup[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
const char suit_lookup[] = "DCHS";

int player_cash = 100;

void get_random_card(int *number, int *suit) {
  srand(time(0));  // initialize random number generator 

  *number = rand()/RAND_MAX * 13;
  *suit = rand()/RAND_MAX * 4;
}

void new_game(void) {
  int player_bet;

  // Get user input from player for bet amount and subtract it
  std::cout << "Player: $" << player_cash << "\nPay for this round: ";
  std::cin >> player_bet;
  player_cash -= player_bet;

  //  std::cout << player_cash << endl; // Debug print

  int cardNumber, cardSuit;
  get_random_card(*cardNumber, *cardSuit);
  
  std::cout << cardNumber << std::endl << cardSuit << std::endl; // Debug print
  
}

int main(void){ 

  new_game();
  
  return 0;
}
