#include <iostream>
#include <cstdlib> //these 2 include statements are required to generate random numbers
#include <ctime>

#define UPPER_BOUND 100
#define LOWER_BOUND 1

void game(void) {
  int secretNumber;
  int guessValue = 0;
  int attempts = 0;
  int lowerBound = LOWER_BOUND;
  int upperBound = UPPER_BOUND;

  srand(time(0));	// sets the random seed
  secretNumber = (double) rand() / RAND_MAX * (UPPER_BOUND-LOWER_BOUND+1)
    + LOWER_BOUND;  // generate a random number with the seed between LOWER_BOUND and UPPER_BOUND

  while (true) {
    std::cout << "Guess a number between " << lowerBound << " and " << upperBound << ": ";
    std::cin >> guessValue;
    attempts++;
    
    if (guessValue == secretNumber) {
      std::cout << "Congratulations, you guessed " << secretNumber << " correctly.\n"
		<< "You took " << attempts << " attempts.\n";
      return;
    }
    else if (guessValue < lowerBound || guessValue > upperBound) {
      std::cout << "Error: Input out of bounds. Input another number\n.";
    }
    else {
      std::cout << "Wrong guess. Try again\n";
      if (guessValue >= lowerBound && guessValue <= secretNumber) {
	lowerBound = guessValue;
      }
      else if (guessValue <= upperBound && guessValue >= secretNumber) {
	upperBound = guessValue;
      }
    }
  }
}

int main(void) {
  while (true) {
    game();
    std::cout << "Do you want to play again (Y/n): ";
    char ch;
    std::cin >> ch;
    ch = tolower(ch);
    if (ch != 'y') {
      return 0;
    }
  }
}
