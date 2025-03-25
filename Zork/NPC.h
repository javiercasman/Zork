#ifndef _NPC_INCLUDE
#define _NPC_INCLUDE

using namespace std;

class NPC : public Creature {
	NPC(const string* name, const string* description, Entity* parent);
	~NPC();
};

#endif //_NPC_INCLUDE