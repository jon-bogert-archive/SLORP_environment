// Class Header
#include "lib/Player.h"

//Constants
const float WALK_SPEED = 0.5f; // Speed without sprinting
const float CAMERA_Y_OFFSET = 2.f;

// Constructor
Player::Player(Settings* _settings, Vector3 _position, Vector3 _rotation)
{
	settings = _settings;
	position = _position;
	rotation = _rotation;
	previosMousePosition = GetMousePosition();
	speed = 0.f;
	isCrouching = false;
	isSprinting = false;
	isJumping = false;
	mesh = GenMeshCylinder(0.5f, 2.f, 8); // Temp
	model = LoadModelFromMesh(mesh);
	rlFPCameraInit(&camera, settings->GetCameraFOVY(), { position.x, CAMERA_Y_OFFSET, position.z });
}


// Getters

Vector3 Player::GetPosition() { return position; }
Vector2 Player::GetPreviousMousePosition() { return previosMousePosition; }
float Player::GetSpeed() { return speed; }
bool Player::GetIsCrouching() { return isCrouching; };
bool Player::GetIsSprinting() { return isSprinting; };
bool Player::GetIsJumping() { return isJumping; }
Mesh Player::GetMesh() { return mesh; }
rlFPCamera Player::GetCamera() { return camera; }

//Setters
void Player::SetPosition(Vector3 _position)
{
	position = _position;
}
void Player::SetRotation(Vector3 _rotation)
{
	rotation = _rotation;
}
void Player::SetPreviousMousePosition(Vector2 _mousePosition)
{
	previosMousePosition = _mousePosition;
}
void Player::SetIsCrouching(bool _state)
{
	isCrouching = _state;
}
void Player::SetIsSprinting(bool _state)
{
	Player::isSprinting = _state;
}
void Player::SetIsJumping(bool _state)
{
	isJumping = _state;
}
void Player::SetMesh(Mesh _mesh)
{
	mesh = _mesh;
}

// Functions
void Player::ToggleIsCrouching()
{
	isCrouching = !isCrouching;
}
void Player::ToggleIsSprinting()
{
	isSprinting = !isSprinting;
}
void Player::ToggleIsJumping()
{
	isJumping = !isJumping;
}

void Player::MovePlayer(Vector2 axis)
{
	Vector2 worldAxis = Vector2Rotate(axis, rotation.x);
	if (!isSprinting)
	{
		// -= because axis values are inverted to desired directions
		position.x -= (WALK_SPEED * worldAxis.x); //* settings->fpsScale(); // having issues atm
		position.z -= (WALK_SPEED * worldAxis.y); //* settings->fpsScale();
	}
	rlFPCameraSetPosition(&camera, { position.x, position.y + CAMERA_Y_OFFSET, position.z });
}

void Player::RotatePlayer(Vector2 rotationAxis)
{
	rotation.x += rotationAxis.x;
	//Stop Y bounce
	if (rotation.y + rotationAxis.y < (PI / 2) && rotation.y + rotationAxis.y >(-PI / 2))
		rotation.y += rotationAxis.y;
	else
		rotationAxis.y = 0.f;

	//Clamp X
	if (rotation.x >= 2 * PI)
		rotation.x -= 2 * PI;
	else if (rotation.x < 0.)
		rotation.x += 2 * PI;

	rlFPCameraRotationUpdate(&camera, rotationAxis);
}

void Player::Draw()
{
	DrawModelEx(model, position, rotation, 0.f, Vector3One(), BLUE);
	//DrawCube(position, 1.f, 2.f, 1.f, GREEN);
}


void Player::SetCamera(rlFPCamera _camera)
{
	camera = _camera;
}