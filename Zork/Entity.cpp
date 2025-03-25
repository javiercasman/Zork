#include <iostream>
#include "Entity.h"

using namespace std;

Entity::Entity(const string name, const string description, Entity* parent, EntityType type) : name(name), description(description), parent(parent), type(type)
{
}

void Entity::Update()
{
}