#include <cstdlib>
#include <iostream>
#include <vector>
#include <limits>
#include <cstring>
#include <algorithm>

// Definitions
#define MAX_ELEMENTS 10

// Class prototypes
class Array;

// Function prototypes
char* swapPlace(char* a, int i, int j);

// Classes
class Array {
private:
  int size;
  char array[MAX_ELEMENTS];
  std::vector<std::string> perm;

public:
  Array() {
    size = 0; // Initialize size correctly
    for (int i = 0; i < MAX_ELEMENTS; i++) {
      array[i] = '\0';
    }
  }

  void askSize() {
    std::cout << "Please input array size (1-" << MAX_ELEMENTS << "): ";
    std::cin >> size;

    while(size < 1 || size > MAX_ELEMENTS) { // Loop to ensure valid input
      std::cin.clear(); // Clear cin buffer
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore existing cin buffer
      std::cout << "Invalid number. Please input array size (1-10): ";
      std::cin >> size;
    }
    return;
  }

  void askArray() {
    int currentSize = 0;
    char ch;

    std::cout << "Please input array elements: ";
    while(currentSize < size) {
      std::cin >> ch;
      if (isalpha(ch)) {
	array[currentSize] = ch;
	currentSize++;
      }
    }
    //    std::cout << array << std::endl; // Debug: Print final array
    return;
  }

  void printPerm() {
    calcPerm(array, 0);
    removeDuplicates();
    std::cout << "The permutations are: \n";
    for (std::vector<std::string>::iterator it = perm.begin() ; it != perm.end(); ++it) {
      std::cout << *it << std::endl;
    }
  }

  void removeDuplicates() { // Not working
    for (std::vector<std::string>::iterator it = perm.begin() ; it != perm.end(); ++it) {
      for (std::vector<std::string>::iterator it2 = ++it ; it2 != perm.end(); ++it2) {
	if (*it == *it2) {
	  perm.erase(it2);
	}
      }
    }
    std::cout << std::endl;
  }

  // Wishlist: find a way to do this function non-destructivly
  void calcPerm(char* p, int depth) {
    if (depth == size) {
      perm.push_back(std::string(p));
    }
    else {
      for (int i = depth; i < size; i++) {
	//	std::cout << depth << ", " << i << ", "; // Debug: print swap position
	swapPlace(p, depth, i);
	calcPerm(p, depth+1);
	swapPlace(p, depth, i);
      }
    }
  }
};

// Functions
// Wishlist: find a way to do this function non-destructivly
char* swapPlace(char* a, int i, int j) {
  char temp;
  temp = a[i];
  a[i] = a[j];
  a[j] = temp;
  return a;
}

int main() {

  while(1) { // Main looping command
    Array array;
    array.askSize();
    array.askArray();
    array.printPerm();

    std::cout << "Continue to use this program (y/n): ";
    char ch;
    while(1) {
      std::cin >> ch;
      if (ch == 'y') {
	break;
      }
      else if (ch == 'n') {
	return 0;
      }
    }
  }
  return 0;
}
