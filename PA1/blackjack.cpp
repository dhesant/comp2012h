/**********************************************************************
 *  blackjack.cpp

Name: Dhesant Jogi Nakka  
Nickname or English name: Dhesant
Major: ECE
Course: COMP2012H
Email address: djnakka@connect.ust.hk
Programming assignment #: 1
OS: Ubuntu 14.04
Compiler: g++ 4.8.4
Hours spent: 20? (Can't remember)

**********************************************************************/

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

// Split lookup values
const std::string deck_string[] = {"Player", "Split", "Split 2", "Split 3"};

// Test case values
const int test_case_number[] = {1, 1, 2, 6, 4, 8, 9, 1, 3, 2, 3, 10};
const int test_case_suit[] = {0, 2, 1, 0, 1, 0, 2, 1, 0, 3, 2, 0};
bool test_case = false;
int test_case_int = 0;

// Class declarations
class Card;
class Hand;
class Player;
class Game;

// Function declarations
int checkWin(Hand player, Hand dealer);
bool dealerDraw(Hand dealer, Player player);

// Classes
class Card {
public:
  int number;
  int suit;

  Card() {
    if (test_case && test_case_int < 12) {
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

class Hand {
public:
  std::vector<Card> hand;
  int hand_count;

  Hand() {
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

  bool hasAce() {
    for (std::vector<Card>::iterator it = hand.begin() ; it != hand.end(); ++it) {
      if (it->number == 0) {
	return true;
      }
    }
    return false;
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

  bool isDoubles() {
    if (hand_count == 2) {
      return (hand[0].number == hand[1].number);
    }
    else {
      return false;
    }
  }
};

class Player {
public:
  std::vector<Hand> deck;
  int splitLevel, currentLevel;

  Player() {
    splitLevel = 0;
    currentLevel = 0;
    for (int i = 0; i < 4; i++) {
      Hand hand;
      deck.push_back(hand);
    }
  }
  
  void checkSplit(int& player_cash, int player_bet) {
    if (deck[0].isDoubles() && askSplit(player_cash, player_bet)) {
      splitHandler(deck[0], deck[1]);
      splitLevel = 1;
      if (deck[1].isDoubles() && askSplit(player_cash, player_bet)) {
	splitHandler(deck[1], deck[2]);
	splitLevel = 2;
	if (deck[0].isDoubles() && askSplit(player_cash, player_bet)) {
	  splitHandler(deck[2], deck[3]);
	  splitLevel = 3;
	}
      }
    }
  }

  bool askSplit(int& player_cash, int player_bet) {
    if (player_cash < player_bet) {
      std::cout << "Cannot split. Insufficient Cash\n";
      return false;
    }
    
    if (splitLevel < 1) {
      std::cout << "Split? (y/n): ";
    }
    else {
      std::cout << "Split again? (y/n): ";
    }

    char ch;
    while (true) { // Loop input until valid response
      std::cin >> ch;
      ch = tolower(ch);
      if (ch == 'y') {
	player_cash -= player_bet;
	return true;
      }
      else if (ch == 'n') {
	return false;
      }
    }
  }
  
  void splitHandler(Hand& h1, Hand& h2) {
    printHand();

    h2.hand.push_back(h1.hand[1]); // Push new card to new hand, and delete from old hand
    h1.hand.pop_back();
    h1.hand_count--;

    h1.drawCard(); // Draw new cards for both split hands
    h2.drawCard();
  }
  
  void printHand() {
    for (int i = 0; i <= splitLevel; i++) {
      std::cout << deck_string[i] << ": " << deck[i].getHand(false) << "\n";
    }    
  }
  
  void drawCard() {
    deck[currentLevel].drawCard();
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
    Player player;
    Hand dealer;
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

    player.drawCard(); // Draw cards for player and dealer
    player.drawCard();
    player.printHand();

    dealer.drawCard();
    dealer.drawCard();

    player.checkSplit(player_cash, player_bet);
    playRound(player, dealer);
  }

  void playRound(Player player, Hand dealer) {
    char ch;
    
    if (player.deck[player.currentLevel].getScore() >= 21 || player.deck[player.currentLevel].hand_count >= 5) { // End game if player gets 21 or over
      endGame(player, dealer);
      return;
    }

    std::cout << "Dealer : * " << dealer.getHand(true) << "\n";
    player.printHand();
    if (player.currentLevel == 0) {
      std::cout << "Draw? (y/n) ";
    }
    else {
      std::cout << "Draw for " << deck_string[player.currentLevel] << "? (y/n) ";
    }

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

  void endGame(Player player, Hand dealer) {
    if (player.currentLevel < player.splitLevel) {
      player.currentLevel++;
      playRound(player, dealer);
      return;
    }
    while (dealerDraw(dealer, player)) {
      dealer.drawCard();
    }
  
    std::cout << "Dealer : " << dealer.getHand(false) << "\n";
    player.printHand();

    std::cout << "Dealer: " << dealer.getScore() << "\tPlayer: ";
    for (int i = 0; i < player.splitLevel; i++) {
      std::cout << player.deck[i].getScore() << " and "; // Display points
    }
    std::cout << player.deck[player.splitLevel].getScore() << " points\n";

    for (int i = 0; i <= player.splitLevel; i++) {
      if (player.splitLevel > 0) {
	std::cout << deck_string[i] << ": ";
      }

      switch (checkWin(player.deck[i], dealer)) {
      case 0:
	std::cout << "Dealer wins!\n";
	break;
      case 1:
	std::cout << "Tie game!\n";
	player_cash += player_bet;
	break;
      case 2:
	std::cout << "Player Wins!\n";
	if (player.deck[i].getScore() == 21) {
	  player_cash += player_bet*2.5;
	}
	else {
	  player_cash += player_bet*2;
	}
	break;
      }
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

// Functions
int checkWin(Hand player, Hand dealer) { // 0 = loss, 1 = tie, 2 = win
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

bool dealerDraw(Hand dealer, Player player) {
  bool d = false;
  if (dealer.hand_count >= 5) {
    return 0;
  }
  if (dealer.getScore() >= 21) {
    return 0;
  }
  for (int i = 0; i <= player.splitLevel; i++) {
    if (checkWin(player.deck[i], dealer) > 0) {
      d = true;
    }
  }
  if (d) {
    bool r = (dealer.getScore() < 17 || (dealer.getScore() == 17 && dealer.hasAce()));
    return r;
  }
  return 0;
}
