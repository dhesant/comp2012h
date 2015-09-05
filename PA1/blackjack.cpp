#include <iostream> 
#include <cstdlib> 
#include <ctime> 
#include <cstring>
#include <vector>
#include <limits>

// Card lookup values
const std::string number_lookup[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
const std::string suit_lookup[] = {"D", "C", "H", "S"};
const int face_value[] = { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

// Test case constants
const int test_case_number[] = {1, 1, 2, 6, 4, 8, 9, 1, 3, 2, 3, 10};
const int test_case_suit[] = {0, 2, 1, 0, 1, 0, 2, 1, 0, 3, 2, 0};
bool test_case = false;
int test_case_int = 0;

class Card {
public:
  int number;
  int suit;

  Card() {
    if (test_case) {
      number = test_case_number[test_case_int];
      suit = test_case_suit[test_case_int];
      test_case_int++;
    }
    else {
      number = (double) rand()/RAND_MAX*13;
      suit = (double) rand()/RAND_MAX*4;
    }
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
  
  int getValue() {
    return face_value[number];
  }
};

class Player {
public:
  std::vector<Card> hand;
  int hand_count;

  Player() {
    hand_count = 0;
  }

  int getScore() {
    int score = 0;
    int hasAce = 0;
    for (std::vector<Card>::iterator it = hand.begin() ; it != hand.end(); ++it) {
      if (it->number == 0) {
	hasAce++;
      }
      score += it->getValue();
    }

    while (hasAce && score > 21) {
      hasAce--;
      score -= 10;
    }
    return score;
  }

  std::string getHand(bool ignoreFirst) {
    std::string s = "";
    for (std::vector<Card>::iterator it = hand.begin() ; it != hand.end(); ++it) {
      if (!ignoreFirst) {
	s.append(it->getString());
	s.append(" ");
      }
      ignoreFirst = false;
    }
    return s;
  }

  void drawCard() {
    Card card;
    hand.push_back(card);
    hand_count++;
  }

  bool isSplit() {
    std::vector<Card>::iterator it = hand.begin();
    int i = it->number;
    it++;
    return (i == it->number);
  }
};


class Game {
public:  
  int player_bet;
  int player_cash;

  Game() {
    player_cash = 100;
  }

  void newGame() {
    Player player, dealer;
    char ch;

    player_bet = 0; // Reset player bet to known value

    std::cout << "Player: $" << player_cash << "\nRound bet: "; // Get player bet amount and deduct it
    std::cin >> player_bet;

    while (player_cash < player_bet || player_bet == 0) { // Ensure valid bet amount
      std::cin.clear(); // Fix looping error with invalid input
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear read buffer
      std::cout << "Invalid bet. Round bet: ";
      std::cin >> player_bet;
    }

    player_cash -= player_bet;

    /*
    std::cout << "Test case? (y/n): ";
    while (true) {
      std::cin >> ch;
      ch = tolower(ch);

      if (ch == 'y') {
	test_case = true;
	break;
      }
      else if (ch == 'n') {
	break;
      }
    }
    */

    player.drawCard(); // Draw cards for player and dealer
    player.drawCard();
    dealer.drawCard();
    dealer.drawCard();
    
    playRound(player, dealer);
  }
    
  void playRound(Player player, Player dealer) {
    char ch;
    
    if (player.getScore() >= 21 || player.hand_count >= 5) { // End game if player gets 21 or over
      endGame(player, dealer);
      return;
    }

    std::cout << "Dealer : * " << dealer.getHand(true) << "\nPlayer : " << player.getHand(false) << "\nDraw? (y/n) ";

    while (true) {
      std::cin >> ch;
      ch = tolower(ch);

      if (ch == 'y') {
	player.drawCard();
	playRound(player, dealer);
	break;
      }
      else if (ch == 'n') {
	endGame(player, dealer);
	break;
      }
    }
  }

  void endGame(Player player, Player dealer) {
    while (dealer.getScore() < 17 && dealer.hand_count < 5) {
      dealer.drawCard();
    }
  
    std::cout << "Dealer : " << dealer.getHand(false) << "\nPlayer : " << player.getHand(false) // Display hands
	      << "\nDealer: " << dealer.getScore() << "\tPlayer: "  << player.getScore() << "\n"; // Display points
  
    switch (checkWin(player, dealer)) {
      case 0:
	std::cout << "Dealer wins!\n";
	break;
      case 1:
	std::cout << "Tie game!\n";
	player_cash += player_bet;
	break;
      case 2:
	std::cout << "Player Wins!\n";
	if (player.getScore() == 21) {
	  player_cash += player_bet*2.5;
	}
	else {
	  player_cash += player_bet*2;
	}
	break;
      }
  }
    
  int checkWin(Player player, Player dealer) { // 0 = loss, 1 = tie, 2 = win
    if (player.getScore() > 21) {
      return 0;
    }
    else if (dealer.getScore() > 21) {
      return 2;
    }
    else if (dealer.getScore() == player.getScore()) {
      return 1;
    }
    else if (dealer.getScore() > player.getScore()) {
      return 0;
    }
    else {
      return 2;
    }
  }
};

int main() {
  Game game;
  char ch;

  srand(time(0));  // initialize random number generator

  game.newGame(); // start new game
 
  while (true) { // Wait for valid input
    if (game.player_cash <= 0) { // Make sure the player has cash to continue playing
      std::cout << "Sorry, You have no more money left.\n";
      break;
    }
    std::cout << "Again? (y/n): ";
    std::cin >> ch;
    ch = tolower(ch);
    if (ch == 'y') {
      game.newGame(); // Start new game
    }
    else if (ch == 'n') {
      break; // Exit loop
    }
  }
  return 0;
}
