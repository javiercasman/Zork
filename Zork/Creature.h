#ifndef _CREATURE_INCLUDE
#define _CREATURE_INCLUDE

using namespace std;

class Creature : public Entity{
public:
	Room* location; // Ubicación de la criatura
};

#endif // _CREATURE_INCLUDE