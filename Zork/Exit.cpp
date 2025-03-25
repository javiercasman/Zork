#include <iostream>
#include "Exit.h"

using namespace std;

Exit::Exit(const string name, const string description, const Entity* parent, /*const ExitDirection direction, */const Room* destination) : Entity(name, description, parent), destination(destination)
{
}

Exit::~Exit()
{
}
