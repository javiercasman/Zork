#include <iostream>
#include "Exit.h"

using namespace std;

Exit::Exit(const string name, const string description, Entity* parent, /*const ExitDirection direction, */Room* destination, bool is_locked, Item* key, bool is_blocked, Item* block) : Entity(name, description, parent, EXIT), destination(destination), is_locked(is_locked), key(key), is_blocked(is_blocked), block(block)
{
	if (parent != NULL) parent->contains[EXIT].push_back(this);
}

Exit::~Exit()
{
}

void Exit::Update(Entity* new_parent) {

}
