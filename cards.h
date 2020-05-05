//cards.h
//Authors: Chris Stasiowski
//All class declarations go here
#include <iostream>
using namespace std;
#ifndef CARDS_H
#define CARDS_H
/*
class Card{

  public:

    Card(); // constructor
    void print() const; // prints card
    friend bool operator==(const Card& card1, const Card& card2); // compares two cards
    ~Card(); // destructor

  private:
    string cardType;
    Card* next;
};
*/

struct Card{
  string cardType;
  Card* next;
};

class CardList{

    public:
      CardList() : first(0) {}// constructor
      ~CardList(); // destructor
      bool contains(string search) const; // returns true if hand contains desired card
      void erase(string del); // erases desired value from list
      void append(string card); // appends desired card to end of list
      void createHand(string filename); // creates hand from input text file
      void print() const; //prints hand
      friend ostream& operator<<(ostream& output, const CardList& c);
      Card* first;
      
    private:
      



};

class Player{
  
  public:
    Player(string n, CardList& h); // constructor
    void printHand(); // prints each card in hand on a new line
  
  private:
    string name;
    CardList hand;
};

#endif

// Use this file to define all your classes and public functions
// You should design your program with OOP prinicples using classes
// An example of class design would be having Card, CardList and Player as Classes.
// Card represent Node in your LinkedList which has some data in it
// CardList can be your LinkedList Class which has operations such as append, remove etc
// Player class represents your game player
// Think about the public functions that should be part of each class. (All public function need to be tested in unit testing)
// One of the important functions is search / find which is essential for players to find cars in their opponent's "hand"
// Make sure you overload the desired operators
// This is not the fixed design. We are not expecting exactly 3 classes. You can do with less or more.
// Important thing to consider is abstraction.
