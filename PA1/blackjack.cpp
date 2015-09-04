#include <iostream> 
#include <cstdlib> 
#include <ctime> 
#include <cstring>

const std::string number_lookup[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
const std::string suit_lookup[] = {"D", "C", "H", "S"};

int player_cash = 100;

class Card {
public:
  int number;
  int suit;
  Card() {
    number = (double) rand()/RAND_MAX*13;
    suit = (double) rand()/RAND_MAX*4;
  }
    
  Card(int n, int s) {
    number = n;
    suit = s;
  }

  std::string getString() {
    std::string s;
    s = number_lookup[number];
    s.append(suit_lookup[suit]);
    return s;
  }
};

void new_game(void) {
  int player_bet;

  // Get user input from player for bet amount and subtract it
  std::cout << "Player: $" << player_cash << "\nPay for this round: ";
  std::cin >> player_bet;
  player_cash -= player_bet;

  //  std::cout << player_cash << endl; // Debug print
  Card test_card;
  std::cout << "Debug: " << test_card.getString() << std::endl;
  
}

int main(void){ 
  srand(time(0));  // initialize random number generator
  new_game();
  
  return 0;
}
