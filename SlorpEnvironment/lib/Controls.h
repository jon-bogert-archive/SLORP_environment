#pragma once

//Project Headers
#include "raylib.h"
#include "raymath.h"
#include "lib/Settings.h"
#include <math.h>
#include <iostream>

class Controls
{
private:
	Settings* settings;

	// Comtroller stick deadzones
	float deadzoneMinLeft; //TODO - Getter/Setter Fn's
	float deadzoneMaxLeft; //TODO - Getter/Setter Fn's
	float deadzoneMinRight; //TODO - Getter/Setter Fn's
	float deadzoneMaxRight; //TODO - Getter/Setter Fn's

	Vector2 moveAxis; // resulting Vector2//TODO - Getter/Setter Fn's

	//Move Axis Controller Inputs
	int moveAxisController;// Controller Input // TODO - Getter/Setter Fn's

	//Move Keys (Keyboard Only - Get stick axis for Controller)
	int moveUpKeyboard; //TODO - Getter/Setter Fn's
	int moveDownKeyboard; //TODO - Getter/Setter Fn's
	int moveLeftKeyboard; //TODO - Getter/Setter Fn's
	int moveRightKeyboard; //TODO - Getter/Setter Fn's

public:
	//Constructor
	Controls(Settings* settings);

	//Getters
	Vector2 GetMoveAxis();	// Returns move axis from controller or keyboard w/ throw

private:
	//Internal
	float DeadZoneLeft(float input);
	void MoveButtonToAxis();
};