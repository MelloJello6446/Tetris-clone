#pragma once
#include"Grid.h"
#include"blocks.cpp"



class Game
{

public:
	~Game();
	Game();
	Grid grid;
	Block GetRandomBlock();
	std::vector<Block> GetAllBlocks();
	void Draw();
	void HandleInput();
	void MoveBlockLeft();
	void MoveBlockRight();
	void MoveBlockDown();
	void SaveBlock();
	bool GameOver;
	int  score;
	Music music;
	double gameSpeed;
	bool isSaved;
	void UseSavedBlock();
	void DrawSavedBlock();


private:
	std::vector<Block> Blocks;
	Block currentBlock;
	Block nextBlock;
	bool IsBlockOutside();
	void RotateBlock();
	void LockBlock();
	bool BlockFits();
	void Reset();
	void UpdateScore(int LinesCleared, int moveDownPoints);
	Sound rotateSound;
	Sound clearSound;
	Block SavedBlock;
	
	


};