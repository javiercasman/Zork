#ifndef _PLAYER_INCLUDE
#define _PLAYER_INCLUDE

#include <vector>
#include "Creature.h"

using namespace std;

class Player : public Creature {
public:
	Player(const string name, const string description, Entity* parent, int health_points);
	~Player();

	void Update(Entity* new_parent) override; //es posible que la funcion sea attack? sino lo dejamos asi y ya, es q tiene mas sentido q Creature sea abstracta a q no lo sea

	//funciones provisionales, no creo q en todas haga falta pasar los tokens
	void Go(const string& direction);
	void Look() override;
	void Inventory();
	void Restart(const vector<string>& tokens);
	void Take(const string& item_name); //Pre: los objetos solo son de una palabra
	void Drop(const string& item_name);
	void Open(const string& item_name);
	void Unlock(const string& exit_name);
	void Read(const string& item_name);
	void Move(const string& item_name);
	void Kill(const string& npc_name, const string& item_name);
	void Turn_on(const string& item_name);
	void Put_in(const string& item_name, const string& container_name);
	void Use(const string& item_name); //solo para el Amuleto en el Garden
};

#endif // _PLAYER_INCLUDE