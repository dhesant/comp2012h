#include "List.h"

List::List()
{
	m_Head = NULL;
}

List::~List()
{
	Node *ptrTemp;
	while (m_Head != NULL)
	{
		ptrTemp = m_Head;
		m_Head = m_Head->ptrNext;
		delete ptrTemp;
	}
}


void List::Print()
{
	Node *ptrTemp = m_Head;
	while(ptrTemp != NULL)
	{
		cout << ptrTemp->str << "->";
		ptrTemp = ptrTemp->ptrNext;
	}
    cout << "NIL" << endl;
}

int List::Access(string str)
{
	if (m_Head == NULL)		// empty list
		return -1;
	else {
		if (m_Head->str == str) {
			return 0;
		}
		else {
            // Assessment
            // To add some code here

			//
		}
		return -1;
	}
}

bool List::Insert(string str)
{
	if (str == "q") {
		cerr << "invalid string\n";
		return false;
	}

	if (m_Head == NULL) {	// empty list
		m_Head = new Node;
		m_Head->str = str;
		m_Head->ptrNext = NULL;
	}
	else {
		//Create new node
		Node *ptrNew = new Node;
		ptrNew->str = str;
		ptrNew->ptrNext = NULL;

		Node *ptrTemp = m_Head;
		while (ptrTemp->ptrNext != NULL)
		{
			if (ptrTemp->str == str)	// discard duplicated node
				return false;
			ptrTemp = ptrTemp->ptrNext;
		}
		if (ptrTemp->str == str)	// checking the last node
			return false;

		//Append to last
		ptrTemp->ptrNext = ptrNew;
	}
	return true;
}
