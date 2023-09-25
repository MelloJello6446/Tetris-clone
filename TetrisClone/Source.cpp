#include "raylib.h"
#include"Game.h"
#include "Colors.h"
#include <iostream>
#include "Grid.h"


double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval)
	{
		lastUpdateTime = currentTime;
		return true;

	}
	return false;
}

int main()
{


	InitWindow(500, 620, "Raylib tetris");
	SetTargetFPS(0);

	Font font = LoadFontEx("font/pricedown bl.ttf", 64, 0, 0);

	Game game = Game();

	while(WindowShouldClose() == false)
	{
		UpdateMusicStream(game.music);
		game.HandleInput();
		if (EventTriggered(game.gameSpeed))
		{
			game.MoveBlockDown();
			
			
		}
		BeginDrawing();
		ClearBackground(darkBlue);
		DrawTextEx(font, "Score", { 365, 15 }, 38, 2, WHITE);
		DrawTextEx(font, "Next", { 370, 175 }, 38, 2, WHITE);
		if (game.GameOver)
		{
			DrawTextEx(font, "GAME OVER", { 320, 450 }, 38, 2, WHITE);
		}
		DrawRectangleRounded({ 320, 55, 170, 60 }, 0.3, 6, lightBlue);
		
		
        
		char scoreText[10];
		sprintf_s(scoreText, "%d", game.score);
		Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
		
		
		  
		DrawTextEx(font, scoreText, { 320 + (170 - textSize.x)/2, 65}, 38, 2, WHITE);
		DrawRectangleRounded({ 320, 215, 170, 180 }, 0.3, 6, lightBlue);

		DrawTextEx(font, "Saved", { 365, 400 }, 38, 2, WHITE);
		DrawRectangleRounded({ 320, 440, 170, 180 }, 0.3, 6, lightBlue);
		game.Draw();
		game.DrawSavedBlock();
		EndDrawing();
	}

	CloseWindow();
}