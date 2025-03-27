#ifndef _ROOM_INCLUDE
#define _ROOM_INCLUDE

#include "Entity.h"

using namespace std;

class Room : public Entity {
public:
	Room(const string name, const string description); //Room no tiene parent. No pertenece al contains de ninguna entidad (es el nodo principal de la jerarquia)
	~Room();

	void Update(Entity* new_parent) override;
	void Look() override;
};

#endif // _ROOM_INCLUDE