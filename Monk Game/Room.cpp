#include "Room.h"

Room::Room(string roomType, string roomDrawing, string roomColor)
{
	this->roomType = roomType;
	this->roomDrawing = roomDrawing;
	this->roomColor = roomColor;
}
/*int Room::generateRandomNumber(int min, int max) { // Generates a 0 or 1; Used for successful/failed attack & defend 
	srand(time(0));
	int n = max - min + 1;
	int remainder = RAND_MAX % n;
	int x;
	do {
		x = rand();
	} while (x >= RAND_MAX - remainder);
	return min + x % n;
} */

int Room::generateRandomNumber(int min, int max) { // Generates a 0 or 1; Used for successful/failed attack & defend
	random_device device;
	default_random_engine engine(device());
	uniform_int_distribution<int> r(min, max);
	return r(engine);
} 