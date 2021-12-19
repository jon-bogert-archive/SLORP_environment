#include "lib/Settings.h"

//Default Constants
const int DEFAULT_WINDOW_WIDTH = 1920;
const int DEFAULT_WINDOW_HEIGHT = 1080;
const int DEFAULT_TARGET_FPS = 60;
const int REF_FPS = 60; // reference FPS for physics/animation scaling
const string WINDOW_NAME = "SLORP";
const float CAMERA_FOVY = 60;

//Constructor
Settings::Settings()
{
	windowResolution = { DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT };
	targetFrameRate = DEFAULT_TARGET_FPS;
	windowName = WINDOW_NAME;
	cameraFOVY = CAMERA_FOVY;

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

//Functions
float Settings::fpsScale()	// calculates scale factor between current and refernce frame rate (60fps)
{
	if (GetFPS == 0)
		return 0.f;
	else
		return REF_FPS / (float)GetFPS();
}