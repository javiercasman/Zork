#ifndef _CREATURE_INCLUDE
#define _CREATURE_INCLUDE

using namespace std;

class Creature : public Entity{
public:
	Creature(const string* name, const string* description, Entity* parent);
	virtual void func() = 0; //Creature es abstracta

	virtual ~Creature() {}
};

#endif // _CREATURE_INCLUDE