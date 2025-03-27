#include <iostream>
#include "Entity.h"
#include "Item.h"

using namespace std;

Entity::Entity(const string name, const string description, Entity* parent, EntityType type) : name(name), description(description), parent(parent), type(type)
{
}
//
//void Entity::Look()
//{
//	cout << description << endl;
//	if (type == ITEM) {
//		Item* item = static_cast<Item*>(this);
//		if (!item->is_open);
//	}
//
//	if (!contains.empty()) {
//		cout << "The " << name << " contains:" << endl;
//		for (auto& pair : contains) {
//			if (pair.first != PLAYER) {
//				list<Entity*>& entities = pair.second;
//				for (Entity* entity : entities) {
//					if (entity->description != "") {
//							cout << "\t";
//							entity->Look();
//					}
//				}
//			}
//		}
//	}
//}