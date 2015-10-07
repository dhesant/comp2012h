#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Structures
struct node {
  char ch;
  struct node *next;
};

// Classes
class linkedList {
private:
  struct node *root;
  struct node *iterator;
public:
  linkedList() {
    root = (struct node *)malloc(sizeof(struct node));
    iterator = root;
    iterator->next = 0;
    return;
  }

  linkedList(char ch) {
    root = (struct node *)malloc(sizeof(struct node));
    iterator = root;
    iterator->ch = ch;
    iterator->next = 0;
    return;
  }

  void push_back(char ch) {
    end();
    increment();
    set(ch);
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
    char ch = get();
    prev->next = 0;
    
    if (iterator != root) { // Ensure not erasing root node
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
    if(iterator->next == 0) {
      iterator->next = (struct node *)malloc(sizeof(struct node));
      iterator = iterator->next;
      iterator->next = 0;
    }
    else {
      iterator = iterator->next;
    }
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

const std::string eol = "null;";
const std::string delim = "->";

int main() {
  std::ifstream infile; // Open input file
  infile.open(in_name, std::ios::in);
  if(infile.fail()) {
    std::cout << "An error has occured while opening 'input.txt'" << std::endl;
    return 1;
  }

  // Vectors to hold the different linked lists
  std::vector<linkedList> lists;
  std::vector<linkedList> lists2;

  std::string s;
  while(getline(infile, s)) {
    linkedList list; // Create a new list and save it in a vector
    lists.push_back(list);

    while (s != eol) {
      std::string chunk = s.substr(0, s.find(delim)); // Get first value and add it to linked list
      list.set(chunk[0]);
      s.erase(0, s.find(delim) + delim.length()); // remove first value from string

      if (s == eol) { // Do not generate extra node if null is reached
	break;
      }
      list.increment();
    }
  }

  for(std::vector<linkedList>::iterator it = lists.begin(); it != lists.end(); ++it) { // Recursivly reverse all lists in lists
    linkedList list2; // Create new reversed list and save it in a vector
    lists2.push_back(list2);

    it->end();
    while(!(it->isBegin())) {
      list2.push_back(it->pop_back());
    }
    list2.push_back(it->get());
  }      

  for(std::vector<linkedList>::iterator it = lists2.begin(); it != lists2.end(); ++it) { // Recursivly print all lists in lists2
    it->begin();
    while(true) {
      if (it->get() != '\0') {
	std::cout << it->get() << "->";
      }
      if(it->isEnd()) {
	break;
      }
      it->increment();
    }
    std::cout << "null;" << std::endl;
  }
  
  return 0;
}
