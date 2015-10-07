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
  linkedList() {
    root = (struct node *)malloc(sizeof(struct node));
    iterator = root;
    return;
  }

  linkedList(char ch) {
    root = (struct node *)malloc(sizeof(struct node));
    iterator = root;
    iterator->ch = ch;
    return;
  }

  void push_back(char ch) {
    end();
    iterator->next = (struct node *)malloc(sizeof(struct node));
    iterator = iterator->next;
    iterator->ch = ch;
    iterator->next = 0;
    return;
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

    iterator = prev;

    return ch;
  }

  void begin() {
    iterator = root;
    return;
  }

  void end() {
    while(iterator->next != 0) {
      iterator = iterator->next;
    }
    return;
  }
  
  void set(char ch) {
    iterator->ch = ch;
    return;
  }
  
  char get() {
    return iterator->ch;
  }

  void increment() {
    iterator = iterator->next;
  }
  
  bool isEnd() {
    return (iterator->next == 0);
  }
  
  bool isBegin() {
    return (iterator == root);
  }
};

// Variables
const char in_name[] = "input.txt";
const char out_name[] = "output.txt";

const char eol[] = "null;";
const char delim[] = "->";

int main() {
  std::ifstream infile; // Open input file
  infile.open(in_name, std::ios::in);
  if(infile.fail()) {
    std::cout << "An error has occured while opening 'input.txt'" << std::endl;
    return 1;
  }

  linkedList list(infile.get());
  while(!infile.eof()) {
    list.push_back(infile.get());
  }

  list.end();
  linkedList list2(list.pop_back()); // Initialize reveresed list with last element
  while(!list.isBegin()) {
    list2.push_back(list.pop_back()); // Push back all elements
  }
  list2.push_back(list.get()); // Push back first element

  list2.begin(); // Print all chars in the linked list
  while(true) {
    std::cout << list2.get();
    if(list2.isEnd()) {
      break;
    }
    list2.increment();
  }

  std::cout << std::endl;
  
  return 0;
}
