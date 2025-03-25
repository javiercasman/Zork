#include <iostream>
#include "NPC.h"

using namespace std;

Npc::Npc(const string name, const string description, Entity* parent, int health_points, const int damage_points) : Creature(name, description, parent, health_points), damage_points(damage_points)
{
}

Npc::Npc()
{
}