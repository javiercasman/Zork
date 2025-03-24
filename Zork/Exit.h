#ifndef _EXIT_INCLUDE
#define _EXIT_INCLUDE

using namespace std;

enum ExitDirection { NORTH, SOUTH, EAST, WEST };

class Exit : public Entity {
public:
	ExitDirection direction;
	Room* source;
	Room* destination;
};

#endif // _EXIT_INCLUDE