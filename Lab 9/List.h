#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
using namespace std;

class List {
 private:
  struct Node {
    string str;
    Node* ptrNext;
  };
  Node* m_Head;	

 public:
  List();
  ~List();	
  void Print();
  bool Insert(string str);

  //ToDo:  implement this function to return the number of node from the head station
  // return -1 when cannot find the distance between str and the head
  int Access(string str);
  int AccessIgnoreCase(string str);
};

#endif
