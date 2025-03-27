#include <iostream>
#include <random>
#include <algorithm>
#include "Player.h"
#include "Room.h"
#include "Exit.h"
#include "Npc.h"

using namespace std;

Player::Player(const string name, const string description, Entity* parent, int health_points) : Creature(name, description, parent, health_points, PLAYER)
{
	if (parent != NULL) parent->contains[PLAYER].push_back(this);
}

Player::~Player()
{
}

void Player::Go(const string& direction) //Pre: le enviaremos una direccion (North, South, East, West)
{
	Room* location = static_cast<Room*>(parent); //Parent siempre sera Room para Player.

	list<Entity*>& exits = location->contains[EXIT];
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
			Look();
		}
	}
}

void Player::Look() {
	//se define todo lo que esta en la habitacion
	Room* location = static_cast<Room*>(parent);
	/*cout << location->name << endl;
	cout << location->description << endl;
	for (auto& pair : parent->contains) {
		if (pair.first != PLAYER) {
			list<Entity*>& entities = pair.second;
			for (Entity* entity : entities) {
				if (entity->description != "") cout << entity->description << endl;
			}
		}
	}*/
	location->Look();
}

void Player::Inventory() 
{
	list<Entity*>& inventory = contains[ITEM];
	if (inventory.empty()) cout << "You are empty handed." << endl;
	else {
		cout << "You are carrying:" << endl;
		for (Entity* entity : inventory) {
			//if (entity->description != "") cout << entity->description << endl;
			cout << "A " << entity->name;
			if (!entity->contains[ITEM].empty()) {
				cout << " that contains:\n";
				for (Entity* e : entity->contains[ITEM]) {
					cout << "\tA " << e->name << endl;
				}
			}
			cout << endl;
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
	vector<Entity*> items_copy(items.begin(), items.end()); //sino crashea
	if (items_copy.empty()) cout << "You can't see any such thing." << endl;
	else if (item_name == "all") {
		for (Entity* itemEntity : items_copy) {
			item = static_cast<Item*>(itemEntity);
			if (item->can_grab) {
				item->Update(this);
				cout << item->name << ": Taken." << endl;
			}
			//else if (item->can_contain && item->is_open && !item->contains.empty()) {
			//	list<Entity*>& containing_items = item->contains[ITEM];
			//	Item* containing_item = NULL;
			//	for (Entity* containing_itemEntity : containing_items) {
			//		containing_item = static_cast<Item*>(itemEntity);
			//		if (containing_item->can_grab) {
			//			containing_item->Update(this);
			//			cout << containing_item->name << ": Taken." << endl;
			//		}
			//		else cout << containing_item->name << ": You can\'t take that." << endl;
			//	}
			//}
			//else cout << item->name << ": You can\'t take that." << endl;
			else {
				cout << item->name << ": You can\'t take that." << endl;
				if (item->can_contain && item->is_open && !item->contains.empty()) {
					list<Entity*>& containing_items = item->contains[ITEM];
					vector<Entity*> containing_items_copy(containing_items.begin(), containing_items.end()); //sino crashea
					Item* containing_item = NULL;
					for (Entity* containing_itemEntity : containing_items_copy) {
						containing_item = static_cast<Item*>(containing_itemEntity);
						if (containing_item->can_grab) {
							containing_item->Update(this);
							cout << containing_item->name << ": Taken." << endl;
						}
						else cout << containing_item->name << ": You can\'t take that." << endl;
					}
				}
			}
		}
	}
	else{
		bool item_found = false;
		for (Entity* itemEntity : items) {
			item = static_cast<Item*>(itemEntity);
			if (item->name == item_name) {
				item_found = true;
				if (item->can_grab) {
					item->Update(this);
					cout << "Taken." << endl;
				}
				else cout << "You can\'t take that." << endl;
				break;
			}
			else if (item->can_contain && item->is_open && !item->contains.empty()) {
				list<Entity*>& containing_items = item->contains[ITEM];
				Item* containing_item = NULL;
				for (Entity* containing_itemEntity : containing_items) {
					containing_item = static_cast<Item*>(containing_itemEntity);
					if (containing_item->name == item_name) {
						item_found = true;
						if (containing_item->can_grab) {
							containing_item->Update(this);
							cout << "Taken." << endl;
						}
						else cout << "You can\'t take that." << endl;
						break;
					}
				}
			}
		}
		if(!item_found) cout << "You can't see any such thing." << endl;
	}
}

void Player::Drop(const string& item_name)
{
	Item* item = NULL;
	list<Entity*>& inventory = contains[ITEM];
	vector<Entity*> inventory_copy(inventory.begin(), inventory.end()); //sino crashea
	Room* location = static_cast<Room*>(parent); //al final si q tendra q ser una variable de clase eh
	if (item_name == "all") {
		if (inventory_copy.empty()) cout << "You are empty handed." << endl;
		else {
			for (Entity* entity : inventory_copy) {
				item = static_cast<Item*>(entity);
				item->Update(location);
				cout << item->name << ": Dropped." << endl;
			}
		}
	}
	else {
		auto it = find_if(inventory_copy.begin(), inventory_copy.end(), [&](Entity* e) {return e->name == item_name;});
		if (it != inventory_copy.end()) {
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

void Player::Open(const string& item_name)
{
	//open para los item containers. para las puertas lockeadas, Unlock.
	Item* item = NULL;
	Room* location = static_cast<Room*>(parent);
	list<Entity*>& room_items = location->contains[ITEM];

	auto it = find_if(room_items.begin(), room_items.end(), [&](Entity* e) {return e->name == item_name; });
	if (it != room_items.end()) {
		item = static_cast<Item*>(*it);
		if (item->can_contain) {
			if (!item->is_open) {
				item->is_open = true;
				cout << "You open the " << item->name << "." << endl;
			}
			else cout << "That\'s already open." << endl;
		}
		else cout << "That\'s not something you can open." << endl;
	}
	else {
		//comprobamos si esta en el inventario, sino no hay
		list<Entity*>& inventory = contains[ITEM];
		auto it = find_if(inventory.begin(), inventory.end(), [&](Entity* e) {return e->name == item_name; });
		if (it != inventory.end()) {
			item = static_cast<Item*>(*it);
			if (item->can_contain) {
				if (!item->is_open) {
					item->is_open = true;
					cout << "You open the " << item->name << "." << endl;
					if (!item->contains[ITEM].empty()) {
						list<Entity*>& contained_items = item->contains[ITEM];
						vector<Entity*> items_copy(contained_items.begin(), contained_items.end()); //sino crashea
						for (Entity* itemEntity : items_copy) {
							item = static_cast<Item*>(itemEntity);
							if (item->can_grab) {
								item->Update(this);
								cout << "There was a " << item->name <<" inside. You took it" << endl;
							}
						}
					}
				}
				else cout << "That\'s already open." << endl;
			}
			else cout << "That\'s not something you can open." << endl;
		}
		else cout << "You can\'t see any such thing." << endl;
	}
}

void Player::Unlock(const string& exit_name) 
{
	Room* location = static_cast<Room*>(parent); //al final si q tendra q ser una variable de clase eh
	list<Entity*>& exits = location->contains[EXIT];
	auto it = find_if(exits.begin(), exits.end(), [&](Entity* e) {return e->name == exit_name; });
	Exit* exit;
	if (it != exits.end()) {
		exit = static_cast<Exit*>(*it);
		if (exit->is_locked) {
			list<Entity*>& inventory = contains[ITEM];
			auto it = find_if(inventory.begin(), inventory.end(), [&](Entity* e) {return e->name == exit->key->name; });
			if (it != inventory.end()) {
				exit->is_locked = false;
				cout << "The door has opened." << endl;
			}
			else cout << "You don\'t have they required key to open it." << endl;
		}
		else cout << "This door is not locked by a key." << endl;
	}
	else cout << "There is a wall here.\n";
}

void Player::Read(const string& item_name)
{
	list<Entity*>& inventory = contains[ITEM];
	auto it = find_if(inventory.begin(), inventory.end(), [&](Entity* e) {return e->name == item_name; });
	if (it != inventory.end()) {
		Item* item = static_cast<Item*>(*it);
		if (item->can_read) cout << item->read_text << endl;
		else cout << "You can't read that." << endl;
	}
	else cout << "You don't have any such item." << endl;
}

void Player::Move(const string& item_name)
{
	Room* location = static_cast<Room*>(parent); //al final si q tendra q ser una variable de clase eh
	list<Entity*>& items = location->contains[ITEM];
	Item* item = NULL;
	auto it = find_if(items.begin(), items.end(), [&](Entity* e) {return e->name == item_name; });
	if (it != items.end()) {
		item = static_cast<Item*>(*it);
		if (item->can_move) {
			if (!item->is_moved) {
				item->is_moved = true;
				if (item_name == "bookshelf") {
					Exit* aux = static_cast<Exit*>(location->contains[EXIT].back()); //no me ha dado tiempo a hacerlo mejor, he tenido que hacer esto de manera rapida para que funcione todo
					aux->is_blocked = false;
				}
				cout << "The " << item->name << " has been moved." << endl;
			}
			else cout << "The " << item->name << " is already moved" << endl;
		}
		else cout << "You can't move this." << endl;
	}
	else cout << "You can't see any such thing." << endl;

}

void Player::Kill(const string& npc_name, const string& item_name)
{
	Room* location = static_cast<Room*>(parent); //al final si q tendra q ser una variable de clase eh
	list<Entity*>& npcs = location->contains[NPC];
	Npc* npc = NULL;
	auto it = find_if(npcs.begin(), npcs.end(), [&](Entity* e) {return e->name == npc_name; });
	if (it != npcs.end()) {
		npc = static_cast<Npc*>(*it);
		list<Entity*>& inventory = contains[ITEM];
		Item* item = NULL;
		auto it = find_if(inventory.begin(), inventory.end(), [&](Entity* e) {return e->name == item_name; });
		if (it != inventory.end()) {
			item = static_cast<Item*>(*it);
			// Attack probability: 70/30
			if (probability70()) {//acierta
				cout << "You hitted the " << npc->name << " with your " << item->name << "!" << endl;
				npc->health_points -= item->damage_points;
			}
			else {//falla
				cout << "Oh, you missed the attack!" << endl;
			}
		}
		else cout << "You don't have any such item." << endl;
	}
	else cout << "You can't see any such creature." << endl;
}

void Player::Turn_on(const string& item_name)
{
	list<Entity*>& inventory = contains[ITEM];
	auto it = find_if(inventory.begin(), inventory.end(), [&](Entity* e) {return e->name == item_name; });
	if (it != inventory.end()) {
		Item* item = static_cast<Item*>(*it);
		if (item->can_turn_on) {
			if (!item->is_on) {
				item->is_on = true;
				cout << "The " << item->name << " is now on";
			}
			else cout << "The " << item->name << " is already on";
		}
		else cout << "You can't turn on that." << endl;
	}
	else cout << "You don't have any such item." << endl;
}

void Player::Put_in(const string& item_name, const string& container_name)
{
	Room* location = static_cast<Room*>(parent); //al final si q tendra q ser una variable de clase eh
	list<Entity*>& items = location->contains[ITEM];
	Item* item_container = NULL;
	auto it = find_if(items.begin(), items.end(), [&](Entity* e) {return e->name == container_name; });
	if (it != items.end()) {
		item_container = static_cast<Item*>(*it);
		if (item_container->can_contain) {
			if (item_container->is_open) {
				Item* item = NULL;
				list<Entity*>& inventory = contains[ITEM];
				auto it = find_if(inventory.begin(), inventory.end(), [&](Entity* e) {return e->name == item_name; });
				if (it != inventory.end()) {
					item = static_cast<Item*>(*it);
					item->Update(item_container);
					cout << "Done." << endl;
				}
				else cout << "You don't have that item." << endl;
			}
			else cout << "It is not open." << endl;
		}
		else cout << "You can't put anything in there." << endl;
	}
	else{
		list<Entity*>& items = contains[ITEM];
		Item* item_container = NULL;
		auto it = find_if(items.begin(), items.end(), [&](Entity* e) {return e->name == container_name; });
		if (it != items.end()) {
			item_container = static_cast<Item*>(*it);
			if (item_container->can_contain) {
				if (item_container->is_open) {
					Item* item = NULL;
					list<Entity*>& inventory = contains[ITEM];
					auto it = find_if(inventory.begin(), inventory.end(), [&](Entity* e) {return e->name == item_name; });
					if (it != inventory.end()) {
						item = static_cast<Item*>(*it);
						item->Update(item_container);
						cout << "Done." << endl;
					}
					else cout << "You don't have that item." << endl;
				}
				else cout << "It is not open." << endl;
			}
			else cout << "You can't put anything in there." << endl;
		}
		else cout << "There is no item to put it in there." << endl;
	}
}

void Player::Use(const string& item_name)
{
	list<Entity*>& inventory = contains[ITEM];
	auto it = find_if(inventory.begin(), inventory.end(), [&](Entity* e) {return e->name == item_name; });
	if (it != inventory.end()) {
		Room* location = static_cast<Room*>(parent);
		if (item_name != "amulet") {
			cout << "You can't use this.\nMaybe try with something magical..." << endl;
		}
		else if (location->name != "Garden") {
			cout << "You can't use this here. \nMaybe try somewhere with a strange obstacle..." << endl;
		}
		else {
			Exit* exit_end = static_cast<Exit*>(location->contains[EXIT].back());
			exit_end->is_locked = false; //ya no esta locked
			cout << "You have unlocked the escape door!\n";
		}
	}
	else {
		cout << "You don't have any such item" << endl;
	}
}

void Player::Update(Entity* new_parent) {
	parent->contains[PLAYER].remove(this);
	parent = new_parent;
	parent->contains[PLAYER].push_back(this);
}