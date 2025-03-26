#ifndef _ENTITY_INCLUDE
#define _ENTITY_INCLUDE

#include <string>
#include <list>
#include <unordered_map>

using namespace std;

enum EntityType { NPC, PLAYER, EXIT, ROOM, ITEM };

class Entity {
public:
	Entity(const string name, const string description, Entity* parent, EntityType type);
	virtual ~Entity() {};

	EntityType type;
	string name;
	string description;
	Entity* parent; //Cada entidad tiene un padre, que representa a que vector de entidades pertenece (ver ideas.txt).
	//list<Entity*> contains; mejor crear un map
	unordered_map<EntityType, list<Entity*>> contains;

	virtual void Update();
};

#endif // _ENTITY_INCLUDE