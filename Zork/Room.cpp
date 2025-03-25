#include <iostream>
#include "Room.h"
#include "Entity.h"

using namespace std;

Room::Room(const string name, const string description) : Entity(name, description, NULL);
{
	type = ROOM;
}

Room::~Room()
{
}