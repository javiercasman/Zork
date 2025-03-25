#include <iostream>
#include "Exit.h"
#include "Room.h"

using namespace std;

Exit::Exit(const string name, const string description, Entity* parent, /*const ExitDirection direction, */Room* destination) : Entity(name, description, parent, EXIT), destination(destination)
{
}

Exit::~Exit()
{
}
