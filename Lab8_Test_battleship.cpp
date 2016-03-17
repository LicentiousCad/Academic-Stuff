#include "battleship.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout; using std::cin; using std::endl; 

Location pick() {
	Location location;
	srand(time(nullptr));
	location.x = (rand() % 4) + 1;
	int tmp = (rand() % 4) + 1;
	switch (tmp) {
	case 1: location.y = 'a'; break;
	case 2: location.y = 'b'; break;
	case 3: location.y = 'c'; break;
	case 4: location.y = 'd'; break;
	case 5: location.y = 'e'; break;
	}
	return location;
}

Location fire() {
	Location location;
	cout << "Input x-axis coordinate (1-5)" << endl;
	cin >> location.x;
	cout << endl << "Input y-axis coordinate (a-e)" << endl;
	cin >> location.y;
	return location;
}

void printShip(Ship myShip) {
	cout << "Sunk? "<< myShip.sunk << endl 
		 << "My ship x coord " << myShip.loc.x << endl
		 << "My ship y coord " << myShip.loc.y << endl;
}

bool match(Ship myShip, Location mySpot) {
	if ((myShip.loc.x == mySpot.x ) &&
		(myShip.loc.y == mySpot.y))
		return true;
	else
		return false;
}

void sink(Ship& myShip) {
	myShip.sunk = 1;
}

void initialize(Ship myFleet[]) {
	for (int i = 0; i < FLEET_SIZE; ++i) {
		myFleet[i].loc.x = -1;
	}
}

void deploy(Ship myFleet[]) {
	for (int i = 0; i < FLEET_SIZE; ++i) {
		myFleet[i].sunk = false;
		myFleet[i].loc = pick();
		if (i > 0) {
			bool pass = false;
			while (pass == false) {
				for (int c = 0; c < i; ++c) {
					if (myFleet[i].loc.x != myFleet[c].loc.x)
						pass = true;
					else {
						myFleet[i].loc = pick();
						c = 0;
					}
				}
			}
		}
	}
}

void printFleet(const Ship myFleet[]) {
	for (int i = 0; i < FLEET_SIZE; ++i) {
		cout << "Ship " << i + 1 << " x: " << myFleet[i].loc.x << " "
			 << "Ship " << i + 1 << " y: " << myFleet[i].loc.y << endl;
	}
}

int check(const Ship myFleet[], Location mySpot) {
	for (int i = 0; i < FLEET_SIZE; ++i)
		if ((myFleet[i].loc.x == mySpot.x) &&
			myFleet[i].loc.y == mySpot.y)
			return 1;
		else
			return -1;
}

bool operational(const Ship myFleet[]) {
	for (int i = 0; i < FLEET_SIZE; ++i) {
		if (myFleet[1].sunk == false) {
			return true;
		}
	}
	return false;
}
