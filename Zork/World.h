#ifndef _WORLD_INCLUDE
#define _WORLD_INCLUDE

#include "Entity.h"
#include <vector>

using namespace std;

class World {
public:
	World();
	~World();
	vector<Entity*> entities; // Entidades del juego

	bool Parser(const vector<string>& tokens);
};

#endif // _WORLD_INCLUDE