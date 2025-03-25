#ifndef _ITEM_INCLUDE
#define _ITEM_INCLUDE

using namespace std;

class Item : public Entity {
	Item(const string* name, const string* description, Entity* parent);
	//a lo mejor otro constructor para cuando el parent es const? es decir, los q no son agarrables
	bool can_grab; //si se puede agarrar se puede tirar, dejar en un container...

	bool can_turn_on; //si se puede encender, se puede apagar
	bool is_on; //será siempre false si can_turn_on es false

	bool is_container; //si es container, se podran guardar cosas dentro de el y se podra abrir
	bool is_open; //si is_container es false, esto sera siempre false.

	bool can_move; //si se puede mover
	bool is_moved; //ha sido movido o no

	bool can_break; //si se puede romper o no
	bool is_broken; //si esta roto o no
	~Item();
};

#endif // _ITEM_INCLUDE