#ifndef _ITEM_INCLUDE
#define _ITEM_INCLUDE

using namespace std;

class Item : public Entity {
	Item(const string* name, const string* description, Entity* parent);
	~Item();
};

#endif // _ITEM_INCLUDE