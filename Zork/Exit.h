#ifndef _EXIT_INCLUDE
#define _EXIT_INCLUDE

using namespace std;

enum ExitDirection { NORTH, SOUTH, EAST, WEST };

class Exit : public Entity {
public:

	Exit(const string* name, const string* description, Entity* parent, const ExitDirection direction, const Room* source, const Room* destination);
	~Exit();

	ExitDirection direction;
	Room* source;
	Room* destination;
};

#endif // _EXIT_INCLUDE