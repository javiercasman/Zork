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
	void Move(const string& direction);
	void Look();
	void Inventory();
	void Restart(const vector<string>& tokens);
	void Take(const string& item_name); //Pre: los objetos solo son de una palabra
	void Drop(const string& item_name);
	void Open(const vector<string>& tokens);
	void Read(const vector<string>& tokens);
	void Move(const vector<string>& tokens);
	void Kill(const vector<string>& tokens);
	void Turn_on(const vector<string>& tokens);
	void Put_in(const vector<string>& tokens);
};

#endif // _PLAYER_INCLUDE