#include <iostream>
#include "Room.h"

using namespace std;

Room::Room(const string name, const string description) : Entity(name, description, NULL, ROOM)
{
}

Room::~Room()
{
}