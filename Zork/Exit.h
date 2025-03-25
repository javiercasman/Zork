#ifndef _EXIT_INCLUDE
#define _EXIT_INCLUDE

using namespace std;

enum ExitDirection { NORTH, SOUTH, EAST, WEST }; //esto sirve de algo?

class Exit : public Entity {
public:

	Exit(const string* name, const string* description, const Entity* parent, /*const ExitDirection direction, */const Room* destination); //creo q parent no ser� necesario declararlo, podemos hacer en la constructora parent = source.
	~Exit();

	//ExitDirection direction;
	Room* destination;
};

#endif // _EXIT_INCLUDE