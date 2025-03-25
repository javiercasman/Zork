#ifndef _NPC_INCLUDE
#define _NPC_INCLUDE

using namespace std;

class NPC : public Creature {
	NPC(const string name, const string description, Entity* parent, const int damage_points);
	~NPC();
	int damage_points;
};

#endif //_NPC_INCLUDE