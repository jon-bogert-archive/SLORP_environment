#include "lib/Actor.h"

Actor::Actor(Mesh mesh, Vector3 position, Rectangle* boxCollider, bool isSolid, bool isDynamic, Vector3 velocity)
	: mesh(mesh), position(position), boxCollider(boxCollider), isSolid(isSolid), isDynamic(isDynamic), velocity(velocity)
{
}

Mesh Actor::GetMesh() const
{
	return mesh;
}

Rectangle* Actor::GetBoxColliderPtr()
{
	return boxCollider;
}

bool Actor::GetIsSolid() const
{
	return isSolid;
}

Vector3 Actor::GetPosition() const
{
	return position;
}

bool Actor::GetIsDynamic() const
{
	return isDynamic;
}

Vector3 Actor::GetVelocity() const
{
	return velocity;
}
