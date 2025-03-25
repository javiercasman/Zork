#ifndef _ENTITY_INCLUDE
#define _ENTITY_INCLUDE

#include <string>
#include <list>

using namespace std;

enum EntityType { NPC, PLAYER, EXIT, ROOM, ITEM };

class Entity {
public:
	Entity(const string name, const string description, Entity* parent, EntityType type);
	virtual ~Entity() {};

	EntityType type;
	string name;
	string description;
	Entity* parent; //Cada entidad tiene un padre, que representa a qué vector de entidades pertenece (ver ideas.txt).
	list<Entity*> contains;

	virtual void Update();
};

#endif // _ENTITY_INCLUDE