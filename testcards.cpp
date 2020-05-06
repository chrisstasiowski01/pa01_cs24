// This file should contain unit tests for all the 
// public interfaces of the classes that you implement

#include "cards.h"
#include "testcards.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
  runAll();
  return 0;
}

void runAll(){
  cout << endl;
  test_append_empty_list();
  test_append_single_element_list();
  test_createHand();
  test_contains();
  test_CardList_destructor();
  test_erase();
  test_cout_overload();
  test_player_print_hand();
}

// CARDLIST TESTS
void test_append_empty_list(){ 
  cout << "APPEND TEST 1:" << endl;
  CardList empty;
  cout << "Hand before append: ";
  empty.print();
  cout << endl;
  cout << "Hand after appendding 'h 2': ";
  empty.append("h 2");
  empty.print();
  cout << endl << "END APPEND TEST 1" << endl << endl;
}

void test_append_single_element_list(){ 
  cout << "APPEND TEST 2:" << endl;
  cout << "Hand before append: ";
  CardList test1;
  test1.createHand("testHand1.txt");
  test1.print();
  cout << endl;
  cout << "Hand after appending 'h 9': ";
  test1.append("h 9");
  test1.print();
  cout << endl << "END APPEND TEST 2" << endl << endl;
}

void test_createHand(){
  cout << "CREATE HAND TEST:" << endl;
  CardList chtest;
  chtest.createHand("testHand2.txt");
  cout << "Expected hand: [s 3, h 6, d j, c 3]" << endl;
  cout << "Actual hand: ";
  chtest.print();
  cout << endl;
  cout << "END CREATE HAND TEST" << endl << endl;
}

void test_contains(){
  CardList ctest;
  cout << "CONTAINS TEST:" << endl;
  ctest.createHand("testHand2.txt");
  cout << "Contains 'h 2'?: ";
  assertEqualsBool(false, ctest.contains("h 2"));
   cout << "Contains 'h 6'?: ";
  assertEqualsBool(true, ctest.contains("h 6")); // middle card
   cout << "Contains 'c 3'?: ";
  assertEqualsBool(true, ctest.contains("c 3")); // end card
   cout << "Contains 's 3'?: ";
  assertEqualsBool(true, ctest.contains("s 3")); // first card
   cout << "Contains 'c k'?: ";
  assertEqualsBool(false, ctest.contains("c k"));
  cout << "END CONTAINS TEST" << endl << endl;
}

void test_CardList_destructor(){
  CardList dtest;
  dtest.createHand("testHand2.txt");
  cout << "CARDLIST DESTRUCTOR TEST:" << endl;
  cout << "CardList before destructor called: ";
  dtest.print();
  cout << endl;
  cout << "CardList after destructor called: ";
  dtest.~CardList();
  dtest.print();
  cout << endl;
  cout << "END CARDLIST DESTRUCTOR TEST" << endl << endl;
}

void test_erase(){
  cout << "ERASE TEST:" << endl;
  CardList etest;
  etest.createHand("testHand3.txt");
  cout << "Original hand: ";
  etest.print();
  cout << endl;
  cout << "Hand after erasing last card: ";
  etest.erase("s a");
  etest.print();
  cout << endl;
  cout << "Hand after erasing 'c 3' (middle card): ";
  etest.erase("c 3");
  etest.print();
  cout << endl;
  cout << "Hand after erasing first card: ";
  etest.erase("h 3");
  etest.print();
  cout << endl;
  cout << "END ERASE TEST" << endl << endl;
}

void test_cout_overload(){
  cout << "<< OVERLOAD TEST:" << endl;
  CardList cTest;
  cTest.createHand("testHand2.txt");
  cout << "Expected:" << endl;
  cout << "s 3" << endl << "h 6" << endl << "d j" << endl << "c 3" << endl << "Actual:" << endl;
  cout << cTest;
  cout << "END << OVERLOAD TEST" << endl << endl;
}

void test_player_print_hand(){
  cout << "PRINT HAND TEST:" << endl;
  CardList p1Test, p2Test;
  p1Test.createHand("testHand1.txt");
  p2Test.createHand("testHand3.txt");
  Player p1 = Player("Player 1", p1Test);
  Player p2 = Player("Player 2", p2Test);
  cout << "Test 1:" << endl << "Expected:" << endl;
  cout << "Player 1's cards:" << endl << "h 1" << endl << "s 3" << endl;
  cout << "Actual:" << endl;
  p1.printHand();
  cout << "Test 2:" << endl << "Expected:" << endl;
  cout << "Player 2's cards:" << endl << "h 3" << endl << "s 2" << endl
    << "c a" << endl << "c 3" << endl << "h 9" << endl << "s a" << endl;
  cout << "Actual:" << endl;
  p2.printHand();
    cout << "END PRINT HAND TEST" << endl << endl;
}

