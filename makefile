CC=g++ -Wall

all: calculator

calculator: calculator.hpp calculator.cpp
	$(CC) -o calculator calculator.cpp

tidy :
	rm -f calculator core

clean :
	rm -f calculator core
