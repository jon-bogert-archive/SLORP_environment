#pragma once
#include "pch/pch.h"
class Actor
{
private:
	Mesh mesh;
	Rectangle* boxCollider;
	bool isSolid; // player can collide
	Vector3 position;
	bool isDynamic;
	Vector3 velocity;
	
public:
	Actor(Mesh mesh, Vector3 position, Rectangle* boxCollider = nullptr, bool isSolid = true, bool isDynamic = true, Vector3 velocity = Vector3Zero());
	~Actor() = default;

	Mesh GetMesh() const;
	Rectangle* GetBoxColliderPtr();
	bool GetIsSolid() const;
	Vector3 GetPosition() const;
	bool GetIsDynamic() const;
	Vector3 GetVelocity() const;

};

