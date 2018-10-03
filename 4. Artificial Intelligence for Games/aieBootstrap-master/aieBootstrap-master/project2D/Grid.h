#pragma once
#include "Renderer2D.h"
#include <vector>
#include "Vector2.h"

struct Node;

#define GRID_SIZE 20
#define NODE_SIZE 30


class Grid
{
public:
	Grid();
	~Grid();

	std::vector<Vector2> GetPath(Vector2 v2Start, Vector2 v2End, bool Astar);
	Node* GetNodeByPos(Vector2 v2Pos);
	void SortOpenList();

	void Draw(aie::Renderer2D* pRenderer);

	Node* m_Nodes[GRID_SIZE][GRID_SIZE];

	std::vector<Node*> m_OpenList;
	bool m_ClosedList[GRID_SIZE][GRID_SIZE];
};

