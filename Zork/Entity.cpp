#include <iostream>
#include "entity.h"

using namespace std;

Entity::Entity(const string name, const string description, Entity* parent)
{
	type = NULL;
}

Entity::~Entity()
{
}