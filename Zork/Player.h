#ifndef _PLAYER_INCLUDE
#define _PLAYER_INCLUDE

using namespace std;

class Player : public Creature {
	Player(const string name, const string description, Entity* parent, int health_points);
	~Player();
};

#endif // _PLAYER_INCLUDE