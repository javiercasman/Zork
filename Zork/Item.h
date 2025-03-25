#ifndef _ITEM_INCLUDE
#define _ITEM_INCLUDE

using namespace std;

class Item : public Entity {
public:

	Item(const string name, const string description, Entity* parent, const bool can_grab, const bool can_read, const bool can_turn_on, const bool can_contain, const bool can_move, const bool can_break, const bool can_use, const int damage_points);
	~Item();
	//a lo mejor otro constructor para cuando el parent es const? es decir, los q no son agarrables
	bool can_grab; //si se puede agarrar se puede tirar, dejar en un container...
	//bool is_grabbed; //no es necesario, bastara con ver si esta en la habitacion o no

	bool can_read;

	bool can_turn_on; //si se puede encender, se puede apagar
	bool is_on; //será siempre false si can_turn_on es false

	bool can_contain; //si es container, se podran guardar cosas dentro de el y se podra abrir
	bool is_open; //si is_container es false, esto sera siempre false.

	bool can_move; //si se puede mover
	bool is_moved; //ha sido movido o no

	bool can_break; //si se puede romper o no
	bool is_broken; //si esta roto o no

	bool can_use; //esto solo para el amuleto

	int damage_points; //si no se puede coger, sera null, porque solo puedes atacar con objetos de tu inventario
};

#endif // _ITEM_INCLUDE