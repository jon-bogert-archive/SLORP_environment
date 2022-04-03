#pragma once
#include "pch/pch.h"
#include "lib/Actor.h"
#include "lib/Player.h"

typedef std::vector<Actor*> ActorList;

class World
{
private:
	ActorList allActors;
	Player* playerRef;

public:
	World(Player* playerRef);
	~World() = default;

	void AddActor(Actor* newActor);

	ActorList GetActorList();
	ActorList GetAllActorList();
};

