#include <iostream> 
#include <cstdlib> 
#include <ctime> 
#include <cstring>
#include <vector>

const std::string number_lookup[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
const std::string suit_lookup[] = {"D", "C", "H", "S"};
const int face_value[] = { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

#define INITIAL_CASH 100

class Card {
private:
  int number;
  int suit;

public:
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
  
  int getValue() {
    return face_value[number];
  }
  
  bool isAce() {
    return (number == 0);
  }  
};

class Player {
public:
  int hasAce;
  std::vector<Card> hand;

  Player() {
    hasAce = 0;
  }

  int getScore() {
    int score;

    for (std::vector<Card>::iterator it = hand.begin() ; it != hand.end(); ++it) {
      if (it->isAce()) {
	hasAce = true;
      }
      score += it->getValue();
    }

    while (hasAce && score > 21) {
      score -= 10;
    }
    return score;
  }

  std::string getHand() {
    std::string s = "";
    for (std::vector<Card>::iterator it = hand.begin() ; it != hand.end(); ++it) {
      s.append(it->getString());
      s.append(" ");
    }
    std::cout << s << std::endl;
    return s;
  }

  void drawCard() {
    Card card;
    if (card.isAce()) {
      hasAce++;
    }
    hand.push_back(card);
  }
};


class Game {
public:
  int player_cash;
  Player player, dealer;

  void newGame() {
    player_cash = 100;
    int player_bet;

    std::cout << "Player: $" << player_cash << "\nPay for this round: "; // Get player bet amount and deduct it
    std::cin >> player_bet;
    player_cash -= player_bet;

    player.drawCard(); // Draw cards for player and dealer
    player.drawCard();
    dealer.drawCard();
    playRound();
  }
    
  void playRound() {
    char ch;
    
    std::cout << "Dealer : * " << dealer.getHand() << "\nPlayer : " << player.getHand() << "\nDraw? (Y/N) ";

    while (ch != 'y' || ch != 'n') {
      std::cin >> ch;
      ch = tolower(ch);

      if (ch == 'y') {
	player.drawCard();
	playRound();
	break;
      }
      else if (ch == 'n') {
	finishRound();
	break;
      }
    }
  }

  void finishRound() {
    std::cout << "Debug: finish_round" << std::endl;
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
 
  while (ch != 'y' || ch != 'n') { // Wait for valid input
    std::cout << "Again? (Y/N): ";
    std::cin >> ch;
    ch = tolower(ch);
    if (ch == 'y') {
      Game game; // Start new game instance
      game.newGame(); // Start new game
    }
    else if (ch == 'n') {
      break; // Exit loop
    }
  }
  return 0;
}
