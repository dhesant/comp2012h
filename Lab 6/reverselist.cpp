#include <cstdlib>
#include <iostream>
#include <fstream>

// Structures prototypes
struct node;

// Function prototypes

// Structures
struct node {
  char ch;
  struct node *next;
};

// Functions

// Variables
const char in_name[] = "input.txt";
const char out_name[] = "output.txt";

int main() {
  std::ifstream infile;
  infile.open(in_name, std::ios::in);
  if(infile.fail()) {
    std::cout << "An error has occured while opening 'input.txt'" << std::endl;
    return 1;
  }
  
  struct node *root;
  struct node *iterator;

  root = (struct node *)malloc(sizeof(struct node));

  iterator = root;

  while(!infile.eof()) {
    infile>>iterator->ch;
    iterator->next = (struct node *)malloc(sizeof(struct node));
    iterator = iterator->next;
  }
  iterator->next = 0;

  iterator = root;
  while (iterator->next != 0) {
    std::cout << iterator->ch;
    iterator = iterator->next;
  }

  return 0;
}
