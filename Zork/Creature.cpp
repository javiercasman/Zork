#include <iostream>
#include "Creature.h"

using namespace std;

Creature::Creature(const string name, const string description, Entity* parent, int health_points, EntityType type) : Entity(name, description, parent, type), health_points(health_points)
{
	is_dead = false;
}