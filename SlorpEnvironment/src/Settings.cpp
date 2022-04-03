#include "pch/pch.h"
#include "lib/Settings.h"

//Default Constants
const int DEFAULT_WINDOW_WIDTH = 1920;
const int DEFAULT_WINDOW_HEIGHT = 1080;
const int DEFAULT_TARGET_FPS = 60;
const int REF_FPS = 60; // reference FPS for physics/animation scaling
const string WINDOW_NAME = "SLORP";
const float CAMERA_FOVY = 60;
const float DEFAULT_MOUSE_SENSITIVITY = 500.f;
const float DEFAULT_STICK_SENSITIVITY = 0.1f;

//Constructor
Settings::Settings()
{
	windowResolution = { DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT };
	targetFrameRate = DEFAULT_TARGET_FPS;
	windowName = WINDOW_NAME;
	cameraFOVY = CAMERA_FOVY;
	mouseSensitivity = DEFAULT_MOUSE_SENSITIVITY;
	stickSensitivity = DEFAULT_STICK_SENSITIVITY;
}

//Getters
Int2 Settings::GetWindowResolution()
{
	return windowResolution;
}
int Settings::GetTargetFrameRate()
{
	return targetFrameRate;
}
string Settings::GetWindowName()
{
	return windowName;
}
float Settings::GetCameraFOVY()
{
	return cameraFOVY;
}
float Settings::GetMouseSensitivity()
{
	return mouseSensitivity;
}
float Settings::GetStickSensitivity()
{
	return stickSensitivity;
}

//Setters
void Settings::SetWindowResolution(int _x, int _y)
{
	windowResolution = { _x, _y };
}
void Settings::SetTargetFrameRate(int _fps)
{
	targetFrameRate = _fps;
}
void Settings::SetCameraFOVY(float _fovY)
{
	cameraFOVY = _fovY;
}
void Settings::SetMouseSensitivity(float _mouseSensitivity)
{
	mouseSensitivity = _mouseSensitivity;
}

//Functions
float Settings::fpsScale()	// calculates scale factor between current and refernce frame rate (60fps)
{
	if (GetFPS == 0)
		return 0.f;
	else
		return REF_FPS / (float)GetFPS();
}