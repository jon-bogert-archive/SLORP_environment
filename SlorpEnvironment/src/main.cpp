//system headers for Debug
#include <iostream>

//Project Headers
#include "raylib.h"
#include "lib/structs.h"
#include "lib/Settings.h"
#include "lib/Player.h"
#include "lib/Controls.h"

extern "C"
{
#include "lib/rlFPCamera.h"
}

using namespace std;

//Global Variables

int main()
{
	// Initialize Game Settings
	Settings settings;
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
	Player player(&settings);

	while (!WindowShouldClose())
	{
		if (IsKeyPressed(KEY_F11)) { ToggleFullscreen(); }
		player.MovePlayer(controls.GetMoveAxis());
		player.RotatePlayer(controls.GetRotationAxis(&player));

		BeginDrawing();

		ClearBackground(RAYWHITE);
		rlFPCameraBeginMode3D(&player.GetCamera());

		DrawGrid(50, 1.0f);
		DrawCube({ 0.f, 0.5f, 0.f }, 1.f, 1.f, 1.f, RED);

		rlFPCameraEndMode3D();
		EndDrawing();
	}

	return 0;
}