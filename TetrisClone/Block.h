#pragma once
#include <vector>
#include <map>
#include "Position.h"
#include "Colors.h"

class Block
{
public:
	Block();
	void Draw(int offsetX, int offsetY);
	void Move(int rows, int columns);
	int id;
	std::map<int, std::vector<Position>> cells;
	std::vector<Position> GetCellPositions();
	void Rotate();
	void UndoRotation();

private:
	int cellSize;
	int rotationState;
	std::vector<Color> colors;
	int rowOffset;
	int columnOffset;
};

