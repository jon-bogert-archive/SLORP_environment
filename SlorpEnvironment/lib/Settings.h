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


public:
	Settings();

	//Getters
	Int2 GetWindowResolution();
	int GetTargetFrameRate();
	string GetWindowName();
	float GetCameraFOVY();

	//Setters
	void SetWindowResolution(int _x, int _y);
	void SetTargetFrameRate(int _fps);
	void SetCameraFOVY(float _fovY);

	//Functions
	float fpsScale();	// calculates scale factor between current and refernce frame rate (60fps)
};

