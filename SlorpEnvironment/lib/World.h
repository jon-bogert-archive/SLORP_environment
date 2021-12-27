#pragma once
#include <list>

#include "raylib.h"
#include "Player.h"

class World
{
private:
	Vector3 dimentions;
	list<Player> otherPlayers;
	list<Mesh> floor;
	list<Mesh> objects;

public:
	World();
};