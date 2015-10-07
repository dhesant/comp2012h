#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

// Structures prototypes
struct node;

// Function prototypes

// Class prototypes
class linkedList;

// Structures
struct node {
  char ch;
  struct node *next;
};

// Functions

// Classes
class linkedList {
private:
  struct node *root;
  struct node *iterator;
public:
  linkedList(char ch) {
    root = (struct node *)malloc(sizeof(struct node));
    iterator = root;
    iterator->ch = ch;
  }

  void push_back(char ch) {
    end();
    iterator->next = (struct node *)malloc(sizeof(struct node));
    iterator = iterator->next;
    iterator->ch = ch;
    iterator->next = 0;
  }

  char pop_back() { // Untested
    struct node *prev;

    iterator = root;
    prev = root;
    while (iterator->next != 0) {
      prev = iterator;
      iterator = iterator->next;
    }
    char ch = iterator->ch;
    prev->next = 0;
    
    if (iterator != root) {
      free(iterator);
    }

    iterator = root;

    return ch;
  }

  void begin() {
    iterator = root;
  }

  void end() {
    iterator = root;
    while(iterator->next != 0) {
      iterator = iterator->next;
    }
  }
  
  char getCurrent() {
    return iterator->ch;
  }

  void increment() {
    iterator = iterator->next;
  }
  
  bool isEnd() {
    return (iterator->next == 0);
  }
};

// Variables
const char in_name[] = "input.txt";
const char out_name[] = "output.txt";

const char eol[] = "null;";
const char delim[] = "->";

int main() {
  std::ifstream infile;
  infile.open(in_name, std::ios::in);
  if(infile.fail()) {
    std::cout << "An error has occured while opening 'input.txt'" << std::endl;
    return 1;
  }

  linkedList list(infile.get());
  

  while(!infile.eof()) {
    list.push_back(infile.get());
  }

  list.begin();
  while(true) {
    std::cout << list.getCurrent();
    list.increment();
    if(list.isEnd()) {
      break;
    }
  }

  return 0;
}
