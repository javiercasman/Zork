#include <iostream>
#include <algorithm>
#include "Player.h"
#include "Room.h"
#include "Exit.h"

using namespace std;

Player::Player(const string name, const string description, Entity* parent, int health_points) : Creature(name, description, parent, health_points, PLAYER)
{
	if (parent != NULL) parent->contains[PLAYER].push_back(this);
}

Player::~Player()
{
}

void Player::Move(const string& direction) //Pre: le enviaremos una direccion (North, South, East, West)
{
	Room* location = static_cast<Room*>(parent); //Parent siempre sera Room para Player.

	list<Entity*>& exits = location->contains[EXIT];
	//falta hacer en caso de q la puerta este lock
	bool exit_exists = false;
	Exit* exit = NULL;
	for (Entity* exitEntity : exits) {
		exit = static_cast<Exit*>(exitEntity); // Haz el cast a Exit
		if ((exit->name == "north" && (direction == "north" || direction == "n")) ||
			(exit->name == "south" && (direction == "south" || direction == "s")) ||
			(exit->name == "east" && (direction == "east" || direction == "e")) ||
			(exit->name == "west" && (direction == "west" || direction == "w"))){
			exit_exists = true;
			break;
		}
	}
	if (!exit_exists) {
		cout << "There is a wall here.\n";
	}
	else {
		// la exit puede estar bloqueada por un objeto, o locked (abrir con llave)
		if (exit->is_locked) {
			cout << "It is locked\n";
		}
		else if (exit->is_blocked) {
			cout << "There is a " << exit->block->name << " blocking the pass.\n";
		}
		else {
			Room* new_room = exit->destination;
			Update(new_room);
		}
	}
}

void Player::Look() {
	//se define todo lo que esta en la habitacion
	Room* location = static_cast<Room*>(parent);
	cout << location->name << endl;
	cout << location->description << endl;
	for (auto& pair : parent->contains) {
		if (pair.first != PLAYER) {
			list<Entity*>& entities = pair.second;
			for (Entity* entity : entities) {
				if (entity->description != "") cout << entity->description << endl;
			}
		}
	}
}

void Player::Inventory() 
{
	list<Entity*>& inventory = contains[ITEM];
	if (inventory.empty()) cout << "You are empty handed." << endl;
	else {
		cout << "You are carrying:" << endl;
		for (Entity* entity : inventory) {
			//if (entity->description != "") cout << entity->description << endl;
			cout << "A " << entity->name << endl;
		}
	}
}

void Player::Restart(const vector<string>& tokens)
{
	//No tiene que ver el player, se elimina el world y se crea uno nuevo.
}

void Player::Take(const string& item_name)
{
	Room* location = static_cast<Room*>(parent); //al final si q tendra q ser una variable de clase eh
	list<Entity*>& items = location->contains[ITEM];
	Item* item = NULL;
	if (items.empty()) cout << "You can't see any such thing" << endl;
	else if (item_name == "all") {
		for (Entity* itemEntity : items) {
			item = static_cast<Item*>(itemEntity); // Haz el cast a Item
			if (item->can_grab) {
				item->Update(this);
				cout << item->name << ": Taken." << endl;
			}
			else cout << item->name << ": You can\'t take this." << endl;
		}
	}
	else {
		auto it = find_if(items.begin(), items.end(), [&](Entity* e) {return e->name == item_name;});
		if (it != items.end()) {
			item = static_cast<Item*>(*it);
			if (item->can_grab) {
				item->Update(this);
				cout << "Taken." << endl;
			}
			else cout << "You can\'t take this." << endl;
		}
		else cout << "You can\'t see any such thing." << endl;
	}
}

void Player::Drop(const string& item_name)
{
	Item* item = NULL;
	list<Entity*>& inventory = contains[ITEM];
	Room* location = static_cast<Room*>(parent); //al final si q tendra q ser una variable de clase eh
	if (item_name == "all") {
		if (inventory.empty()) cout << "You are empty handed." << endl;
		else {
			for (Entity* entity : inventory) {
				item = static_cast<Item*>(entity);
				item->Update(location);
				cout << item->name << ": Dropped." << endl;
			}
		}
	}
	else {
		auto it = find_if(inventory.begin(), inventory.end(), [&](Entity* e) {return e->name == item_name;});
		if (it != inventory.end()) {
			item = static_cast<Item*>(*it);
			item->Update(location);
			cout << "Dropped." << endl;
		}
		else {
			list<Entity*>& room_items = location->contains[ITEM];
			auto it = find_if(room_items.begin(), room_items.end(), [&](Entity* e) {return e->name == item_name; });
			if (it != room_items.end()) cout << "The " << (*it)->name << " is already here." << endl;
			else cout << "You can't see any such thing." << endl;
		}
	}
}

void Player::Open(const vector<string>& tokens)
{
}

void Player::Read(const vector<string>& tokens)
{
}

void Player::Move(const vector<string>& tokens)
{
}

void Player::Kill(const vector<string>& tokens)
{
}

void Player::Turn_on(const vector<string>& tokens)
{
}

void Player::Put_in(const vector<string>& tokens)
{
}

void Player::Update(Entity* new_parent) {
	parent->contains[PLAYER].remove(this);
	parent = new_parent;
	parent->contains[PLAYER].push_back(this);
}