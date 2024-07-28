#include "main.h"

int main(int argc, char* argv[]){
	InitWindow(1280, 720, "JMV");
	SetTargetFPS(60);

	while(!WindowShouldClose()){
		BeginDrawing();
			ClearBackground(BLACK);
		EndDrawing();
	}

	return 0;
}
