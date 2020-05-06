#include "cards.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argv, char** argc){
  if(argv != 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail()){
    cout << "Could not open file " << argc[1];
    return 1;
  }

  if (cardFile2.fail()){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  // Create two objects of the class you defined 
  // to contain two sets of cards in two input files
  CardList list1, list2;
  list1.createHand(argc[1]);
  list2.createHand(argc[2]);

  Player a = Player("Alice", list1);
  Player b = Player("Bob", list2);

  while(1){
    Card* aCycle = a.hand.first;
    while(aCycle){
      if((b.hand).contains(aCycle->cardType) == true){
        cout << "Alice picked matching card " << aCycle->cardType << endl;
        (b.hand).erase(aCycle->cardType);
        (a.hand).erase(aCycle->cardType);
        break;
      }else{
        aCycle = aCycle->next;
      }
    }
    Card* bCycle = b.hand.first;
    while(bCycle){
      if((a.hand).contains(bCycle->cardType) == true){
        cout << "Bob picked matching card " << bCycle->cardType << endl;
        (a.hand).erase(bCycle->cardType);
        (b.hand).erase(bCycle->cardType);
        break;
      }else{
        bCycle = bCycle->next;
      }
    }
    if((aCycle == NULL) && (bCycle == NULL)){
      break;
    }
  }
  cout << endl;
  a.printHand();
  cout << endl;
  b.printHand();

  return 0;
}
