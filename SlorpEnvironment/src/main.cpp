//system headers for Debug
#include <iostream>

//Project Headers
#include "raylib.h"
#include "lib/structs.h"


//system namespace for Debug;
using namespace std;

int main()
{
	InitWindow(1920, 1080, "Window");

	SetTargetFPS(60);

	while (!WindowShouldClose())
	{

		BeginDrawing();

		ClearBackground(RAYWHITE);

		EndDrawing();

	}

	return 0;
}