#include <iostream>
#include "Player.h"

using namespace std;

Player::Player(const string name, const string description, Entity* parent, int health_points) : Creature(name, description, parent, health_points, PLAYER)
{
}

Player::~Player()
{
}

void Player::func()
{
}