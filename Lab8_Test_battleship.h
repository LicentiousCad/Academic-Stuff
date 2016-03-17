// structure definitions and function prototypes
// 3/16/2016

#ifndef BATTLESHIP_H_
#define BATTLESHIP_H_

// data structures definitions

const int FLEET_SIZE = 5;	// number of battleships
const int FIELD_SIZE = 5;	// the field (ocean) is FIELD_SIZExFIELD_SIZE

// coordinates (Location) of the ship and shots
struct Location {
	int x;					// 1 through FIELD_SIZE
	char y;					// 'a' through FIELD_SIZE
};

// contains ship's coordinates (Location) and whether is was sunk
struct Ship {
	Location loc;
	bool sunk;
};

// initialization functions

void initialize(Ship[]);					// places every Ship in a Location where x-coordinate is -1 and y-coordinate is '*' (a star) to signify that the Ship is not deployed

Location pick();							// generates a random Location
bool match(Ship, Location);					// returns true if this Location matches the Location of the Ship returns false otherwise
int check(const Ship[], Location);		// returns the index of element of the array that matches the Location returns -1 if none do

// uses match()

void deploy(Ship[]);						// places an array of battleships in random Locations in the ocean

// display functions

void printShip(Ship);						// prints the Location and status (sunk or not) of a single ship
void printFleet(const Ship[]);				// prints the Locations of all the ships and  whether they are sunk

							   
// battle functions
							   
bool operational(const Ship[]);				// returns true if at least one ship in the array is not sunk
Location fire();							// asks the user to input the coordinates of the next shot
											// note that check() is also used in the battle

void sink(Ship&);							// sets "sunk" member variable of the ship to true

#endif BATTLESHIP_H_
