#include <iostream>
#include "Item.h"

using namespace std;

Item::Item(const string name, const string description, Entity* parent, const bool can_grab, const bool can_read, const bool can_turn_on, 
	const bool can_contain, const bool can_move, const bool can_break, const bool can_use, const int damage_points) : Entity(name, description, parent, ITEM), can_grab(can_grab), can_read(can_read),
	can_turn_on(can_turn_on), can_contain(can_contain), can_move(can_move), can_break(can_break), can_use(can_use), damage_points(damage_points)
{
	if(parent != NULL) parent->contains[ITEM].push_back(this);
	is_broken = false;
	is_moved = false;
	is_on = false;
	is_open = false;
}

Item::~Item()
{
}

void Item::Update(Entity* new_parent)
{
	parent->contains[PLAYER].remove(this);
	parent = new_parent;
	parent->contains[PLAYER].push_back(this);
}

