#ifndef _CREATURE_INCLUDE
#define _CREATURE_INCLUDE

#include "Entity.h"
#include <cstdlib>
#include <ctime>

using namespace std;

class Creature : public Entity{
protected:
public:
	Creature(const string name, const string description, Entity* parent, int health_points, EntityType type);
	virtual void Update(Entity* new_parent) = 0;

	virtual bool probability70() const { //70% probabilidad del Player de acertar, 70% de probabilidad del NPC de fallar.
		srand(time(0));
		if (rand() % 100 < 70) return true;
		else return false;
	}

	virtual ~Creature() {}
	int health_points;
	bool is_dead;
};

#endif // _CREATURE_INCLUDE