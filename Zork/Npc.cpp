#include <iostream>
#include "NPC.h"
#include "Item.h"
#include "Room.h"
#include "Exit.h"

using namespace std;

Npc::Npc(const string name, const string description, Entity* parent, int health_points, const int damage_points) : Creature(name, description, parent, health_points, NPC), damage_points(damage_points)
{
	if (parent != NULL) parent->contains[NPC].push_back(this);
}

Npc::~Npc()
{
	//cuando el npc muere, sus objetos pasan a formar parte de la habitacion, y luego se deletea
	Item* item = NULL;
	list<Entity*>& inventory = contains[ITEM];
	vector<Entity*> inventory_copy(inventory.begin(), inventory.end());
	Room* location = static_cast<Room*>(parent);
	if (!inventory_copy.empty()){
		for (Entity* entity : inventory_copy) {
			item = static_cast<Item*>(entity);
			item->Update(location);
			cout << item->name << ": Dropped." << endl;
		}
	}
	parent->contains[NPC].remove(this);
}

void Npc::Update(Entity* new_parent)
{
	parent->contains[NPC].remove(this);
	parent = new_parent;
	parent->contains[NPC].push_back(this);
	cout << "Me he movido a " << parent->name << endl;
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

void Npc::Action(Player* player)
{
	Entity* player_parent = player->parent;
	//1. comprobar si sigue vivo o no
	if (health_points > 0) {
		//2. determinar si se tiene q mover, esperar, o atacar
		Room* player_location = static_cast<Room*>(player_parent);
		Room* npc_location = static_cast<Room*>(parent);
		if (player_location != npc_location) {
			list<Entity*>& exits = npc_location->contains[EXIT];
			Exit* exit = NULL;
			bool can_move = true;
			for (Entity* exitEntity : exits) {
				exit = static_cast<Exit*>(exitEntity);
				if (exit->destination == player_location) can_move = false;
			}
			if (can_move) {
				for (Entity* exitEntity : exits) {
					exit = static_cast<Exit*>(exitEntity);
					if(exit->destination->name == "Cellar" || 
						exit->destination->name == "Studio" ||
						exit->destination->name == "Gallery")
					if (probability50()) {
						Update(exit->destination);
						break;
					}
				}
			}
		}
		else { //pelea
			if (!probability70()) {//acierta
				cout << "The " << name << " hitted you!" << endl;
				player->health_points -= damage_points;
			}
			else {//falla
				cout << "The " << name << " missed the attack!" << endl;
			}
		}
	}
	else {
		cout << "You defeated the " << name << "!" << endl;
		delete this;
	}
}
