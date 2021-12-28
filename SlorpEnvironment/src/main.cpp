//system headers for Debug
#include <iostream>

//Project Headers
#include "raylib.h"
#include "lib/structs.h"
#include "lib/Settings.h"
#include "lib/physics.h"
#include "lib/Player.h"
#include "lib/Controls.h"

extern "C"
{
#include "lib/rlFPCamera.h"
}

using namespace std;
bool showDebugCam = false;
void InitDebugCam(Camera3D* camera);

int main()
{
	// Initialize Game Settings
	Settings settings;
	Physics physics;
	Controls controls(&settings);
	

	//Setup Game Window
	InitWindow
	(
		settings.GetWindowResolution().x,
		settings.GetWindowResolution().y,
		&settings.GetWindowName()[0] // pass as char array for raylib in (in C)
	);
	SetTargetFPS(settings.GetTargetFrameRate());
	//Init Player/Camera
	Player player(&settings, &physics);
	Camera3D debugCam;
	InitDebugCam(&debugCam);

	while (!WindowShouldClose())
	{
		if (IsKeyPressed(KEY_F3)) { showDebugCam = !showDebugCam; } // Press F3 for 3rd Person Debug Camera
		if (IsKeyPressed(KEY_F11)) { ToggleFullscreen(); } // Press F11 to toggle Fullscreen
		player.MovePlayer(controls.GetMoveAxis());
		player.RotatePlayer(controls.GetRotationAxis(&player));

		BeginDrawing();

		ClearBackground(RAYWHITE);
		if (showDebugCam)
			BeginMode3D(debugCam);
		else
			rlFPCameraBeginMode3D(&player.GetCamera());

		DrawGrid(50, 1.0f);
		DrawCube({ 0.f, 0.5f, 0.f }, 1.f, 1.f, 1.f, RED);
		player.Draw();
		DrawGrid(10, 1.0f);

		rlFPCameraEndMode3D();
		EndDrawing();
	}

	return 0;
}

void InitDebugCam(Camera3D* camera)
{
	camera->position = { 10.0f, 10.0f, 10.0f };
	camera->target = { 0.0f, 0.0f, 0.0f };
	camera->up = { 0.0f, 1.0f, 0.0f };
	camera->fovy = 90.0f;
	camera->projection = CAMERA_PERSPECTIVE;
}