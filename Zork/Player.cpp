#include <iostream>
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
	cout << location->name << endl;

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
}

void Player::Inventory() {
	//se describe todo lo del contains
}

void Player::Restart(const vector<string>& tokens)
{
}

void Player::Take(const vector<string>& tokens)
{
}

void Player::Drop(const vector<string>& tokens)
{
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