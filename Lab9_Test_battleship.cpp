#include "battleship.h"
#include <iostream>
using namespace std;

void Location::pick() {
	x = rand() % 5 + 1;
	y = 'a' + (rand() % 5 + 1);
}

Location::Location() {
	x = -1;
	y = -1;
}
void Location::fire() {
	cout << endl << "Input x coordinate (1-5): ";
	cin >> x;
	cout << endl << "Input y coordinate (a-e): ";
	cin	>> y;
}

void Location::print(void) const {
	cout << x << y;
}
bool compare(Location one, Location two) {
	if (one.x == two.x && one.y == two.y)
		return true;
	else
		return false;
}

ship::ship() {
	sunk = false;
}
void ship::setLocation(const Location& spot) {
	loc = spot;
}

bool ship::match(const Location& userShot) const {
	return compare(loc, userShot);
}

void ship::printShip(void) const {
	cout << endl;
	loc.print();
	if (sunk == true)
		cout << " Sunk" << endl;
	else
		cout << " Not Sunk" << endl;
}
void ship::sink() {
	sunk = true;
}

void Fleet::deployFleet() {
	for (int i = 0; i<5; i++)
	{
		Location tmp;
		tmp.pick();
		ships[i].setLocation(tmp);
	}
}
bool Fleet::operational() const {
	for (int i = 0; i<5; i++) {
		if (ships[i].isSunk() == false)
			return true;
	}
	return false;
}

bool Fleet::isHitNSink(const Location& shot) {
	for (int i = 0; i<5; i++)
	{
		if (ships[i].match(shot) == true) {
			ships[i].sink();
			return true;
		}
	}
	return false;
}
void Fleet::printFleet(void) const {
	for (int i = 0; i<5; i++) {
		ships[i].printShip();
	}
}
