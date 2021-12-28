//Class header
#include "lib/Controls.h"

//Default Values
const float DEADZONE_MIN = 0.3f;
const float DEADZONE_MAX = 1.0f;
const float AXIS_THROW = 0.25f; //simulated control stick travel time

Controls::Controls(Settings* _settings)
{
	settings = _settings;

	deadzoneMinLeft = DEADZONE_MIN; 
	deadzoneMaxLeft = DEADZONE_MAX; 
	deadzoneMinRight = DEADZONE_MIN; 
	deadzoneMaxRight = DEADZONE_MAX; 

	moveAxis = Vector2Zero(); // resulting Vector2
	rotationAxis = Vector2Zero();

	//Move Axis Controller Inputs
	moveAxisController = 0;

	//Move Keys (Keyboard Only - Get stick axis for Controller)
	moveUpKeyboard = KEY_W;
	moveDownKeyboard = KEY_S;
	moveLeftKeyboard = KEY_A;
	moveRightKeyboard = KEY_D;

	jumpKeyboard = KEY_SPACE;
	jumpController = GAMEPAD_BUTTON_RIGHT_FACE_DOWN; // A Button
}

Vector2 Controls::GetMoveAxis()
{
	Vector2 tempAxis;
	if (IsGamepadAvailable(0))
	{
		tempAxis.x = DeadZoneLeft(GetGamepadAxisMovement(0, 0));
		tempAxis.y = DeadZoneLeft(GetGamepadAxisMovement(0, 1));
		if ((tempAxis.x == 0.f) && (tempAxis.y == 0.f)) // if control stick is centered -> check keys
			MoveButtonToAxis();
		else
			moveAxis = tempAxis;
	}
	else
		MoveButtonToAxis();
	
	return moveAxis;
}

Vector2 Controls::GetRotationAxis(Player* player) // COPYRIGHT: Adapted from rlCamera by Jeffery Myers
{
	//TODO - Implement Controller R_Stick input

//Mouse
	Vector2 mousePositionDelta = { 0.0f, 0.0f };
	Vector2 mousePosition = GetMousePosition();

	//Calculate Difference
	mousePositionDelta.x = mousePosition.x - player->GetPreviousMousePosition().x;
	mousePositionDelta.y = mousePosition.y - player->GetPreviousMousePosition().y;

	//Store previous position for next frame
	player->SetPreviousMousePosition(mousePosition);

	//Get Axis Value from mouse delta
	rotationAxis.x = mousePositionDelta.x / settings->GetMouseSensitivity();
	rotationAxis.y = mousePositionDelta.y / settings->GetMouseSensitivity();

	return rotationAxis;
}

bool Controls::GetJump()
{
	if (IsKeyDown(jumpKeyboard) || IsGamepadButtonDown(0, jumpController))
		return true;
	else
		return false;
}

float Controls::DeadZoneLeft(float input)
{
	if (fabs(input) < deadzoneMinLeft)
	{
		return 0.f;
	}
	else if (fabs(input) > deadzoneMaxLeft)
	{
		if (input >= 0.f) { return 1.f; }
		else { return -1.f; }
	}
	else
	{
		if (input >= 0.f)
		{
			return (input - deadzoneMinLeft) * (1 / (deadzoneMaxLeft - deadzoneMinLeft));
		}
		else
		{
			return (input + deadzoneMinLeft) * (1 / (deadzoneMaxLeft - deadzoneMinLeft));
		}
	}
}

void Controls::MoveButtonToAxis()
{
	Vector2 targetValue = { 0.f, 0.f };
	float axisThrowScaled = AXIS_THROW * settings->fpsScale(); // Throw Scaled to current FPS
	if (IsKeyDown(moveRightKeyboard))
	{
		targetValue.x = 1.f;
	}
	if (IsKeyDown(moveLeftKeyboard))
	{
		targetValue.x = -1.f;
	}
	if (IsKeyDown(moveDownKeyboard))
	{
		targetValue.y = 1.f;
	}
	if (IsKeyDown(moveUpKeyboard))
	{
		targetValue.y = -1.f;
	}

	if ((targetValue.x != 0.f) && (targetValue.y != 0.f))
	{
		targetValue.x = sqrtf(0.5f) * targetValue.x;
		targetValue.y = sqrtf(0.5f) * targetValue.y;
	}

	if ((moveAxis.x < targetValue.x) && (moveAxis.x + axisThrowScaled < targetValue.x))
	{
		moveAxis.x += axisThrowScaled;
	}
	else if ((moveAxis.x > targetValue.x) && (moveAxis.x - axisThrowScaled > targetValue.x))
	{
		moveAxis.x -= axisThrowScaled;
	}
	else if (((moveAxis.x < targetValue.x) && (moveAxis.x + axisThrowScaled >= targetValue.x))
		|| ((moveAxis.x > targetValue.x) && (moveAxis.x - axisThrowScaled <= targetValue.x)))
	{
		moveAxis.x = targetValue.x;
	}

	if ((moveAxis.y < targetValue.y) && (moveAxis.y + axisThrowScaled < targetValue.y))
	{
		moveAxis.y += axisThrowScaled;
	}
	else if ((moveAxis.y > targetValue.y) && (moveAxis.y - axisThrowScaled > targetValue.y))
	{
		moveAxis.y -= axisThrowScaled;
	}
	else if (((moveAxis.y < targetValue.y) && (moveAxis.y + axisThrowScaled >= targetValue.y))
		|| ((moveAxis.y > targetValue.y) && (moveAxis.y - axisThrowScaled <= targetValue.y)))
	{
		moveAxis.y = targetValue.y;
	}
}