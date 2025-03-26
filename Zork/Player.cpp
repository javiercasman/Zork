#include <iostream>
#include "Player.h"
#include "Room.h"
#include "Exit.h"

using namespace std;

Player::Player(const string name, const string description, Entity* parent, int health_points) : Creature(name, description, parent, health_points, PLAYER)
{
}

Player::~Player()
{
}

void Player::func()
{
}

void Player::Move(const string& direction) //Pre: le enviaremos una direccion (North, South, East, West)
{
	Room* location = static_cast<Room*>(parent); //Parent siempre sera Room para Player.

	list<Entity*>& exits = location->contains[EXIT];
	//falta hacer en caso de q la puerta este lock
	bool exit_exists = false;
	for (Entity* exitEntity : exits) {
		Exit* exit = static_cast<Exit*>(exitEntity); // Haz el cast a Exit
		if ((exit->name == "north" && (direction == "north" || direction == "n")) ||
			(exit->name == "south" && (direction == "south" || direction == "s")) ||
			(exit->name == "east" && (direction == "east" || direction == "e")) ||
			(exit->name == "west" && (direction == "west" || direction == "w"))){
			exit_exists = true;
			break;
		}
	}
	if (!exit_exists) {
		//"There is a wall there"
	}
	else {
		// la exit puede estar bloqueada por un objeto, o locked (abrir con llave)
	}
}