#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

  struct node* getRoot() {
    return root;
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

  std::vector<linkedList> lists;
  std::vector<linkedList> lists2;
  //  int i;
  std::string s;
  while(getline(infile, s)) {
    linkedList list; // Create a new list and save it in a vector
    lists.push_back(list);

    //    std::cout << i << ";";

    while (s != eol) {
      std::string chunk = s.substr(0, s.find(delim));
      list.set(chunk[0]);
      s.erase(0, s.find(delim) + delim.length());
      //      std::cout << chunk << ";" << s << ";";
      if (s == eol) {
	break;
      }
      list.increment();
    }
    //    std::cout << "End of Line" << std::endl;
    //    i++;
  }

  for(std::vector<linkedList>::iterator it = lists.begin(); it != lists.end(); ++it) {
    linkedList list2; // Create new reversed list and save it in a vector
    lists2.push_back(list2);

    it->end();
    while(!(it->isBegin())) {
      list2.push_back(it->pop_back());
    }
    list2.push_back(it->get());
  }      

  for(std::vector<linkedList>::iterator it = lists2.begin(); it != lists2.end(); ++it) {
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

  /*
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
  */

  std::cout << std::endl;
  
  return 0;
}
