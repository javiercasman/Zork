#include <iostream>
#include "Item.h"

using namespace std;

Item::Item(const string name, const string description, Entity* parent, const bool can_grab, const bool can_read, const string read_text, const bool can_turn_on,
	const bool can_contain, const bool can_move, const bool can_use, const int damage_points) : Entity(name, description, parent, ITEM), can_grab(can_grab), can_read(can_read), read_text(read_text),
	can_turn_on(can_turn_on), can_contain(can_contain), can_move(can_move), can_use(can_use), damage_points(damage_points)
{
	if(parent != NULL) parent->contains[ITEM].push_back(this);
	is_moved = false;
	is_on = false;
	is_open = false;
}

Item::~Item()
{
}

void Item::Update(Entity* new_parent)
{
	parent->contains[ITEM].remove(this);
	parent = new_parent;
	parent->contains[ITEM].push_back(this);
}

void Item::Look()
{
	cout << description << endl;
	if (can_contain) {
		if (is_open && !contains[ITEM].empty()) {
			Item* item = NULL;
			cout << "Contains:" << endl;
			for (auto& pair : contains) {
				if (pair.first != PLAYER) {
					list<Entity*>& entities = pair.second;
					for (Entity* entity : entities) {
						item = static_cast<Item*>(entity);
						if (item->description != "") {
							cout << "\t";
							item->Look();
						}
					}
				}
			}
		}
	}
}

