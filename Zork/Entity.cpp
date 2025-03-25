#include <iostream>
#include "entity.h"

using namespace std;

Entity::Entity(const string name, const string description, Entity* parent) : name(name), description(description), parent(parent)
{
	type = NULL;
}

Entity::~Entity()
{
}