# Makefile

CXX_FLAG = --std=c++11 -g

all: testcards game

testcards: testcards.o cards.o
	g++ $(CXX_FLAG) -o testcards testcards.o cards.o

game: main.o cards.o
	g++ -c $(CXX_FLAG) game cards.o main.o

cards.o: cards.cpp
	g++ -c $(CXX_FLAG) cards.cpp

testcards.o: testcards.cpp
	g++ -c $(CXX_FLAG) testcards.cpp

main.o: main.cpp
	g++ -c $(CXX_FLAG) main.cpp

clean:
	rm -f testcards game *.o