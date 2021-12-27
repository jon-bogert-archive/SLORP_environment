#include "lib/World.h"

const int WORLD_WIDTH_DEFAULT = 128; // X
const int WORLD_HEIGHT_DEFAULT = 128; // Y
const int WORLD_LENGTH_DEFAULT = 128;  // Z

World::World()
{
	dimentions = { WORLD_WIDTH_DEFAULT, WORLD_HEIGHT_DEFAULT, WORLD_LENGTH_DEFAULT };
	//list<Player> otherPlayers; // TODO include Connected Players
	floor.push_back(GenMeshCube(WORLD_WIDTH_DEFAULT, 1.f, WORLD_LENGTH_DEFAULT)); // temp
	//list<Mesh> objects;
}