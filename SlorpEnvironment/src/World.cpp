#include "pch/pch.h"
#include "lib/World.h"

World::World(Player* playerRef)
	: playerRef(playerRef)
{
}

void World::AddActor(Actor* newActor)
{
	allActors.push_back(newActor);
}

ActorList World::GetActorList()
{
	return allActors; // TODO - find and return proper list based on position
}

ActorList World::GetAllActorList()
{
	return allActors;
}
