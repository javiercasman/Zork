#ifndef _NPC_INCLUDE
#define _NPC_INCLUDE

#include "Creature.h"
#include "Player.h"
#include <cstdlib>
#include <ctime>

using namespace std;

class Npc : public Creature {
public:
	Npc(const string name, const string description, Entity* parent, int health_points, const int damage_points);
	~Npc();

	int damage_points;

	bool probability50() const { //50% de posibilidades de que el NPC se mueva (si puede)
		srand(time(0));
		if (rand() % 100 < 50) return true;
		else return false;
	}

	void Update(Entity* new_parent) override;
	void Look() override;

	void Action(Player* player);
};

#endif //_NPC_INCLUDE