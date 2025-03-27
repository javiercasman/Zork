#include <iostream>
#include "Room.h"

using namespace std;

Room::Room(const string name, const string description) : Entity(name, description, NULL, ROOM)
{
}

Room::~Room()
{
}

void Room::Update(Entity* new_parent)
{
}

void Room::Look()
{
	cout << name << endl;
	cout << description << endl;
	if (!contains.empty()) {
		for (auto& pair : contains) {
			if (pair.first != PLAYER) {
				list<Entity*>& entities = pair.second;
				for (Entity* entity : entities) {
					if (entity->description != "") {
						cout << "\t";
						entity->Look();
					}
				}
			}
		}
	}
}
