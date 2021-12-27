#pragma once

//Project Headers
#include "raylib.h"
#include "lib/structs.h"
#include <string>

using namespace std;

class Settings
{
private:
	Int2 windowResolution;
	int targetFrameRate;
	string windowName;
	float cameraFOVY;
	float mouseSensitivity;


public:
	Settings();

	//Getters
	Int2 GetWindowResolution();
	int GetTargetFrameRate();
	string GetWindowName();
	float GetCameraFOVY();
	float GetMouseSensitivity();

	//Setters
	void SetWindowResolution(int _x, int _y);
	void SetTargetFrameRate(int _fps);
	void SetCameraFOVY(float _fovY);
	void SetMouseSensitivity(float _mouseSensitivity);

	//Functions
	float fpsScale();	// calculates scale factor between current and refernce frame rate (60fps)
};

