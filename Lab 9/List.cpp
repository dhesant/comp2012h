#include "List.h"

List::List() {
  m_Head = NULL;
  m_Tail = NULL;
}


List::~List() {
  Node *ptrTemp;
  while (m_Head != NULL)
    {
      ptrTemp = m_Head;
      m_Head = m_Head->ptrNext;
      delete ptrTemp;
    }
  m_Tail = NULL;
}

void List::Print() {
  Node *ptrTemp = m_Head;
  while(ptrTemp != NULL) {
      cout << ptrTemp->str << "->";
      ptrTemp = ptrTemp->ptrNext;
   }
  cout << "NIL" << endl;
}

void List::PrintReverse() {
  Node *ptrTemp = m_Tail;

  while (ptrTemp != NULL) {
      cout << ptrTemp->str << "->";
      ptrTemp = ptrTemp->ptrPrev;
   }
  cout << "NIL" << endl;
}

int List::Access(string str) {
  if (m_Head == NULL)		// empty list
    return -1;
  else {
    // Assessment
    // To add some code here
    int count = 0;
    Node *ptrTemp = m_Head;
    while(ptrTemp->str != str) {
      count++;
      ptrTemp = ptrTemp->ptrNext;
      if (ptrTemp == NULL) {
	return -1;
      }
    }
    return count;
    //
    return -1;
  }
}

int List::AccessIgnoreCase(string str) {
  if (m_Head == NULL)		// empty list
    return -1;
  else {
    // Assessment
    // To add some code here
    int count = 0;
    Node *ptrTemp = m_Head;
    while(strToLower(ptrTemp->str) != strToLower(str)) {
      count++;
      ptrTemp = ptrTemp->ptrNext;
      if (ptrTemp == NULL) {
	return -1;
      }
    }
    return count;
    //
    return -1;
  }
}

bool List::Insert(string str) {
  if (str == "q") {
    cerr << "invalid string\n";
    return false;
  }

  if (m_Head == NULL) {	// empty list
    m_Head = new Node;
    m_Head->str = str;
    m_Head->ptrNext = NULL;
    m_Head->ptrPrev = NULL;
    m_Tail = m_Head;
  }
  else {
    //Create new node
    Node *ptrNew = new Node;
    ptrNew->str = str;
    ptrNew->ptrNext = NULL;

    Node *ptrTemp = m_Head;
    while (ptrTemp->ptrNext != NULL) {
      if (ptrTemp->str == str) {	// discard duplicated node
	return false;
      }
      ptrTemp = ptrTemp->ptrNext;
    }
    if (ptrTemp->str == str) { // checking the last node
      return false;
    }
 
    ptrTemp->ptrNext = ptrNew; // Append to last

    ptrNew->ptrPrev = m_Tail; // Update ptrPrev

    m_Tail = ptrNew; // Update Tail node
  }
  return true;
}

string strToLower(string str) {
  std::transform(str.begin(), str.end(), str.begin(), ::tolower);
  return str;
}
