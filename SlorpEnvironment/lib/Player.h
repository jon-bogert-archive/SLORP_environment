#pragma once
#include <iostream>
//Project Headers
#include "raylib.h"
#include "structs.h"
#include "lib/Settings.h"
#include <raymath.h>

extern "C"
{
#include "lib/rlFPCamera.h"
}

#define position translation
 
class Player
{
private:
	Settings* settings;
	Transform transform;
	float speed;
	bool isCrouching;
	bool isSprinting;
	bool isJumping;
	Mesh mesh;
	rlFPCamera camera; // needs to be public to interact with rlFPCamera (in C)

public:
	// Constructor
	//Player(Settings* settings, Vector3 _position = Vector3Zero(), Vector3 _rotation = Vector3Zero(), Vector3 _scale = { 1.f, 1.f, 1.f });
	Player(Settings* settings, Vector3 _position = Vector3Zero(), Quaternion _rotation = {0.f, 0.f, 0.f, 0.f}, Vector3 _scale = { 1.f, 1.f, 1.f });

	// Getter
	Transform GetTransform();
	float GetSpeed();
	bool GetIsCrouching();
	bool GetIsSprinting();
	bool GetIsJumping();
	Mesh GetMesh();
	rlFPCamera GetCamera();

	//Setter
	void SetTransform(Transform _transform);
	void SetPosition(Vector3 _position);
	void SetRotation(Quaternion _rotation);
	void SetScale(Vector3 _scale);
	void SetIsCrouching(bool _state);
	void SetIsSprinting(bool _state);
	void SetIsJumping(bool _state);
	void SetMesh(Mesh _mesh);

	// Functions

	void ToggleIsCrouching();
	void ToggleIsSprinting();
	void ToggleIsJumping();
	void MovePlayer(Vector2 axis);
	void RotatePlayer(Vector2 axis);

private:
	void SetCamera(rlFPCamera camera);// use when updating player transform
};