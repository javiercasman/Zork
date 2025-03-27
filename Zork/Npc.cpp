#include <iostream>
#include "NPC.h"
#include "Item.h"

using namespace std;

Npc::Npc(const string name, const string description, Entity* parent, int health_points, const int damage_points) : Creature(name, description, parent, health_points, NPC), damage_points(damage_points)
{
	if (parent != NULL) parent->contains[NPC].push_back(this);
}

Npc::~Npc()
{
}

void Npc::Update(Entity* new_parent)
{
	//hay q meter lo de si se mueve de habitacion o no
	parent->contains[NPC].remove(this);
	parent = new_parent;
	parent->contains[NPC].push_back(this);
}

void Npc::Look()
{
	cout << description << endl;
	if (!contains.empty()) {
		Item* item = NULL;
		cout << "The " << name << " carries:" << endl;
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
