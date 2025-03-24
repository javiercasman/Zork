#ifndef _ENTITY_INCLUDE
#define _ENTITY_INCLUDE

#include <string>
#include <list>

using namespace std;

enum EntityType { NPC, PLAYER, EXIT, ROOM, ITEM };

class Entity {
public:
	EntityType type;
	string name;
	string description;
	list<Entity*> contains;

	Entity* parent; //Cada entidad tiene un padre, que representa a qué vector de entidades pertenece (ver ideas.txt).
	virtual void Update();
};

#endif // _ENTITY_INCLUDE