#ifndef _WORLD_INCLUDE
#define _WORLD_INCLUDE

using namespace std;

class World {
public:
	World();
	~World();
	vector<Entity*> entities; // Entidades del juego
};

#endif // _WORLD_INCLUDE