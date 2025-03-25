#ifndef _PLAYER_INCLUDE
#define _PLAYER_INCLUDE

#include "Creature.h"

using namespace std;

class Player : public Creature {
public:
	Player(const string name, const string description, Entity* parent, int health_points);
	~Player();

	void func() override;
};

#endif // _PLAYER_INCLUDE