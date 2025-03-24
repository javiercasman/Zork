#ifndef _ENTITY_INCLUDE
#define _ENTITY_INCLUDE

#include <string>
#include <list>

using namespace std;

enum EntityType { CREATURE, EXIT, ROOM, ITEM };

class Entity {
public:
	EntityType type;
	string name;
	string description;
	list<Entity*> contains;

	virtual void Update();
};

#endif // _ENTITY_INCLUDE