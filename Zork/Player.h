#ifndef _PLAYER_INCLUDE
#define _PLAYER_INCLUDE

#include <vector>
#include "Creature.h"

using namespace std;

class Player : public Creature {
public:
	Player(const string name, const string description, Entity* parent, int health_points);
	~Player();

	void func() override; //es posible que la funcion sea attack? sino lo dejamos asi y ya, es q tiene mas sentido q Creature sea abstracta a q no lo sea

	//funciones provisionales, no creo q en todas haga falta pasar los tokens
	void Move(const string& direction);
	void Look(const vector<string>& tokens);
	void Inventory(const vector<string>& tokens);
	void Restart(const vector<string>& tokens);
	void Take(const vector<string>& tokens);
	void Drop(const vector<string>& tokens);
	void Open(const vector<string>& tokens);
	void Read(const vector<string>& tokens);
	void Move(const vector<string>& tokens);
	void Kill(const vector<string>& tokens);
	void Turn_on(const vector<string>& tokens);
	void Put_in(const vector<string>& tokens);
};

#endif // _PLAYER_INCLUDE