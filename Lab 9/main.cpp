#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "List.h"
using namespace std;

#define STATION_FILE "station.txt"

void InitList(List &list) {
  ifstream fin(STATION_FILE);
  if ( !fin ) {
    cerr << "error: unable to open input file " << STATION_FILE << "\n";
    exit (-1);
  }

  int intNum;
  fin >> intNum;	
    
  for(int i=0; i<intNum; i++)
    {
      string temp;
      fin >> temp;
      if (!list.Insert (temp))
        {
	  cout << "Some error in input file "  << STATION_FILE << "\n";
	  exit(-1);
        }
    }
}

int main() {
  string strStation;
  int intCost;	
  List list;
  InitList(list);

  cout << "Input the name of station for the distance from the first station (in term of station)\n";
  cout << "Type q to exit \n\n";
  while (true) {
    intCost = -1;		

    list.Print();
    cout << "Station > ";

    cin >> strStation;
		
    //Exit
    if (strStation == "q" || strStation == "Q")
      break;
    intCost = list.Access(strStation);
    if (intCost != -1) {
      cout << intCost <<"\n\n";
    } else {
      cout << "No such station !\n\n";
    }
  }
  return 0;
}
