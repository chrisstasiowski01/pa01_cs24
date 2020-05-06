// testcards.h
//Authors: Chris Stasiowski
//All test declarations go here

// This is not exhaustive list of tests. You can remove / edit tests if it doesn't suit your design but you should definitelty add more
// You should test all possible cornere cases of your public functions

#ifndef TESTCARDS_H
#define TESTCARDS_H

#include <iostream>
#include <string>

using namespace std;

// runs all tests
void runAll();

// CardList tests
void test_append_empty_list();
void test_append_single_element_list();
void test_createHand();
void test_contains();
void test_CardList_destructor();
void test_erase();
void test_cout_overload();

// Player Tests
void test_player_print_hand();

void assertEqualsBool(bool expected, bool actual){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: " << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}

#endif
