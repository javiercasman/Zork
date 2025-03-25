#include <iostream>
#include "room.h"
#include "entity.h"

using namespace std;

Room::Room(const string name, const string description) : Entity(name, description, NULL);
{
	type = ROOM;
}

Room::~Room()
{
}