#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string strToLower(string in);

class List {
 private:
  struct Node {
    string str;
    Node* ptrNext;
    Node* ptrPrev;
  };
  Node* m_Head;	
  Node* m_Tail;

 public:
  List();
  ~List();	
  void Print();
  void PrintReverse();
  bool Insert(string str);

  //ToDo:  implement this function to return the number of node from the head station
  // return -1 when cannot find the distance between str and the head
  int Access(string str);
  int AccessIgnoreCase(string str);
};

#endif
