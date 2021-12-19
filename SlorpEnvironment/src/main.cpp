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
		//std::cout << "X:" << controls.GetMoveAxis().x << " Y:" << controls.GetMoveAxis().y << endl;
		player.MovePlayer(controls.GetMoveAxis());
		//std::cout << "Player Position X:" << player.GetTransform().position.x << " Z:" << player.GetTransform().position.z << endl;
		BeginDrawing();

		ClearBackground(RAYWHITE);
		rlFPCameraBeginMode3D(&player.GetCamera());

		DrawGrid(10, 1.0f);

		rlFPCameraEndMode3D();
		EndDrawing();
	}

	return 0;
}