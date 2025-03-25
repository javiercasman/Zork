#ifndef _EXIT_INCLUDE
#define _EXIT_INCLUDE

#include "Entity.h"
#include "Room.h"

using namespace std;

enum ExitDirection { NORTH, SOUTH, EAST, WEST }; //esto sirve de algo?

class Exit : public Entity {
public:

	Exit(const string name, const string description, Entity* parent, /*const ExitDirection direction, */Room* destination); //creo q parent no será necesario declararlo, podemos hacer en la constructora parent = source.
	~Exit();

	//ExitDirection direction;
	Room* destination;
};

#endif // _EXIT_INCLUDE