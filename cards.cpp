//cards.cpp
//Authors: Chris Stasiowski
//Implementation of the classes defined in cards.h
#include "cards.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// CARDLIST CLASS

// constructor sets up empty list

// creates list of cards given a .txt file name
void CardList::createHand(string filename){
  ifstream file;
  string line;
  file.open(filename);
  while(1){
    getline(file, line);
    if(!file){
      break;
    }
    append(line);
  }
  file.close();
  return;
}

// cycles through card list and deletes every node
CardList::~CardList() {
    Card* next = first;
    while(next){
        first = first->next;
        delete next;
        next = first;
    }
}

// cycles through card list and checks if desired card is in list
bool CardList::contains(string search) const{
  Card* p = first;
  while(p){
    if(p->cardType == search){
      return true;
    }
    p = p->next;
  }
  return false;
}

// removes desired card from list
void CardList::erase(string del){
  if (contains(del) == false){
    return;
  }
  Card* p = first;
  if(p->cardType == del){
    first = p->next;
    delete p;
    return;
  }
  while(p){
    if(p->next->cardType == del){
      Card* temp = p->next;
      p->next = temp->next;
      delete temp;
      return;
    }
    p = p->next;
  }
}

// adds card to end of list
void CardList::append(string card) {
    if (first == 0) { // empty list
        
        first = new Card;
        first->cardType = card;
        first->next = 0;

    }
    else {
        Card *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Card;
        n->next->cardType = card;
        n->next->next = 0;
    }
}

// prints cards on one line (for testing)
void CardList::print() const {
    Card *n = first;
    cout << '[';
    while (n) {
        cout << n->cardType;
        if (n->next)
            cout << ", ";
        n = n->next;
    }
    cout << ']';
}

// prints each card in hand on new line (for game)
ostream& operator<<(ostream &output, const CardList& c){
  Card* n = c.first;
  while(n){
    cout << n->cardType << endl;
    n = n->next;
  }
  return output;
}

// PLAYER CLASS

// constructor (gives name and hand to player)
Player::Player(string n, CardList& h){
  name = n;
  hand = h;
}

// prints each card in hand on new line
void Player::printHand(){
  cout << name << "'s cards:" << endl;
  cout << hand;
}

// destructor for player class
Player::~Player(){
  hand.first = NULL;
}


