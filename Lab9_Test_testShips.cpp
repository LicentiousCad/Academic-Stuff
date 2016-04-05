#include "battleship.h"
#include <iostream>
#include <ctime>


using namespace std;


/// this is main function
int main() {

	//
	// checking location object
	// 
	srand(time(nullptr));
	Location mySpot, userShot;
	mySpot.pick(); // selecting a new random location

	cout << "Randomly selected location is: "; mySpot.print();

	cout << "Input location: ";
	userShot.fire(); // having user input a location

	if (compare(mySpot, userShot))
		cout << "Random location matches user input.\n";
	else
		cout << "Random location does not match user input.\n";
	mySpot.print();


	//
	// checking ship object
	//

	// uncomment this part once you are done debugging above code

	Ship myShip;

	myShip.setLocation(mySpot); // placing ship at mySpot location

	if (myShip.match(userShot))
		cout << "myShip\'s location matches user input.\n";
	else
		cout << "myShip's location does not match user input.\n";

	if (!myShip.isSunk()) {
		cout << "myship is not sunk yet, sinking it.\n";
		myShip.sink();
	}

	cout << "myShip\'s status is: "; myShip.printShip();



	//
	// checking fleet object
	// 

	// uncomment this part once you are done debugging above code
	Fleet myFleet;

	myFleet.deployFleet(); // fleet is deployed at random locations

	if (myFleet.operational())
		cout << "Some ships of myFleet are still up.\n";

	if (myFleet.isHitNSink(userShot))
		cout << "there was a ship at userShot location, no it is sunk.\n";
	else
		cout << "there was no ship at userShot location.\n";

	cout << "myFleet\'s status is: "; myFleet.printFleet();

}
