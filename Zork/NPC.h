#ifndef _NPC_INCLUDE
#define _NPC_INCLUDE

#include "Creature.h"

using namespace std;

class Npc : public Creature {
public:
	Npc(const string name, const string description, Entity* parent, int health_points, const int damage_points);
	~Npc();

	void func() override;

	int damage_points;
};

#endif //_NPC_INCLUDE