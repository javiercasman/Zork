#ifndef _CREATURE_INCLUDE
#define _CREATURE_INCLUDE

using namespace std;

class Creature : public Entity{
public:
	Creature(const string name, const string description, Entity* parent, int health_points);
	virtual void func() = 0; //Creature es abstracta

	virtual ~Creature() {}
	int health_points;
	bool is_dead;
};

#endif // _CREATURE_INCLUDE