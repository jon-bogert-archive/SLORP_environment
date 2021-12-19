// Class Header
#include "lib/Player.h"

//Constants
const float WALK_SPEED = 0.5f; // Speed without sprinting
const float CAMERA_Y_OFFSET = 1.f;

// Constructor
//Player::Player(Settings* _settings, Vector3 _position, Vector3 _rotation, Vector3 _scale)
Player::Player(Settings* _settings, Vector3 _position, Vector3 _rotation)
{
	settings = _settings;
	position = _position;
	std::cout << "set x:" << position.x << " y: " << position.y << endl;
	rotation = _rotation;
	//transform.scale = _scale;
	speed = 0.f;
	isCrouching = false;
	isSprinting = false;
	isJumping = false;
	mesh = GenMeshCylinder(0.5f, 2.f, 3); // Temp
	rlFPCameraInit(&camera, settings->GetCameraFOVY(), { position.x, CAMERA_Y_OFFSET, position.z });
}


// Getter
//Transform Player::GetTransform() { return transform; }
Vector3 Player::GetPosition() { return position; }
float Player::GetSpeed() { return speed; }
bool Player::GetIsCrouching() { return isCrouching; };
bool Player::GetIsSprinting() { return isSprinting; };
bool Player::GetIsJumping() { return isJumping; }
Mesh Player::GetMesh() { return mesh; }
rlFPCamera Player::GetCamera() { return camera; }

//Setter
//void Player::SetTransform(Transform _transform)
//{
//	transform = _transform;
//}
void Player::SetPosition(Vector3 _position)
{
	position = _position;
}
void Player::SetRotation(Vector3 _rotation)
{
	rotation = _rotation;
}
//void Player::SetScale(Vector3 _scale)
//{
//	scale = _scale;
//}
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
	if (!isSprinting)
	{
		// -= because axis values are inverted to desired directions
		position.x -= (WALK_SPEED * axis.x);
		position.z -= (WALK_SPEED * axis.y);
		std::cout << "fpsScale:" << settings->fpsScale() << endl;

	}
	rlFPCameraSetPosition(&camera, { position.x, position.y + CAMERA_Y_OFFSET, position.z });
	std::cout << "PosX:" << position.x << " PosZ:" << position.z << endl;
}

void Player::RotatePlayer(Vector2 axis)
{

}


void Player::SetCamera(rlFPCamera _camera)
{
	camera = _camera;
}