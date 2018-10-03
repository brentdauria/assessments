#include "Grid.h"
#include "Node.h"
#include <stdlib.h>


#define GRID_SPACING 2.0f
#define OFFSET_X 350.0f
#define OFFSET_Y 75.0f

Grid::Grid()
{
	for (int x = 0; x < GRID_SIZE; ++x)
	{
		for (int y = 0; y < GRID_SIZE; ++y)
		{
			m_Nodes[x][y] = new Node();
			m_Nodes[x][y]-> m_v2Pos.x = OFFSET_X + NODE_SIZE * x;
			m_Nodes[x][y]-> m_v2Pos.y = OFFSET_Y + NODE_SIZE * y;
			m_Nodes[x][y]->m_nIndexX = x;
			m_Nodes[x][y]->m_nIndexY = y;
		}
	}

	for (int x = 0; x < GRID_SIZE; ++x)
	{
		for (int y = 0; y < GRID_SIZE; ++y)
		{
			m_Nodes[x][y]->m_Neighbours[0] = nullptr;
			m_Nodes[x][y]->m_Neighbours[1] = nullptr;
			m_Nodes[x][y]->m_Neighbours[2] = nullptr;
			m_Nodes[x][y]->m_Neighbours[3] = nullptr;
			m_Nodes[x][y]->m_Neighbours[4] = nullptr;
			m_Nodes[x][y]->m_Neighbours[5] = nullptr;
			m_Nodes[x][y]->m_Neighbours[6] = nullptr;
			m_Nodes[x][y]->m_Neighbours[7] = nullptr;

			m_Nodes[x][y]->m_Costs[0] = 10;
			m_Nodes[x][y]->m_Costs[1] = 10;
			m_Nodes[x][y]->m_Costs[2] = 10;
			m_Nodes[x][y]->m_Costs[3] = 10;

			m_Nodes[x][y]->m_Costs[4] = 14;
			m_Nodes[x][y]->m_Costs[5] = 14;
			m_Nodes[x][y]->m_Costs[6] = 14;
			m_Nodes[x][y]->m_Costs[7] = 14;

			if (y < GRID_SIZE - 1)
				m_Nodes[x][y]->m_Neighbours[0] = m_Nodes[x][y + 1];

			if (x < GRID_SIZE - 1)
				m_Nodes[x][y]->m_Neighbours[1] = m_Nodes[x + 1][y];

			if (y < 0)
				m_Nodes[x][y]->m_Neighbours[2] = m_Nodes[x][y - 1];

			if (x < 0)
				m_Nodes[x][y]->m_Neighbours[3] = m_Nodes[x - 1][y];

			//Diagonals
			if (y < GRID_SIZE - 1 && x < GRID_SIZE - 1)
				m_Nodes[x][y]->m_Neighbours[4] = m_Nodes[x + 1][y + 1];

			if (y < 0 && x < GRID_SIZE - 1)
				m_Nodes[x][y]->m_Neighbours[4] = m_Nodes[x + 1][y - 1];

			if (y < 0 && x < 0)
				m_Nodes[x][y]->m_Neighbours[4] = m_Nodes[x - 1][y - 1];

			if (y < GRID_SIZE - 1 && x < 0)
				m_Nodes[x][y]->m_Neighbours[4] = m_Nodes[x - 1][y + 1];
		}
	}

	for (int i = 0; i < 80; ++i)
	{
		int x = rand() % GRID_SIZE;
		int y = rand() % GRID_SIZE;
		m_Nodes[x][y]->m_bBlocked = true;
	}

}

Grid::~Grid()
{

	for (int x = 0; x < GRID_SIZE; ++x)
	{
		for (int y = 0; y < GRID_SIZE; ++y)
		{
			delete m_Nodes[x][y];
		}
	}
}

void Grid::Draw(aie::Renderer2D* pRenderer)
{
	for (int x = 0; x < GRID_SIZE; ++x)
	{
		for (int y = 0; y < GRID_SIZE; ++y)
		{
			if (m_Nodes[x][y]->m_bBlocked)
				continue;

			Vector2 v2Pos = m_Nodes[x][y]->m_v2Pos;
			float fSize = NODE_SIZE - GRID_SPACING;
			pRenderer->drawBox(v2Pos.x, v2Pos.y, fSize, fSize);

			for (int i = 0; i < NEIGHBOUR_COUNT; ++i)
			{
				if (m_Nodes[x][y]->m_Neighbours[i])
				{
					if (m_Nodes[x][y]->m_Neighbours[i]->m_bBlocked)
						continue;

					Vector2 v2NeighbourPos = m_Nodes[x][y]->m_Neighbours[i]->m_v2Pos; 
					pRenderer->drawLine(v2Pos.x, v2Pos.y, v2NeighbourPos.x, v2NeighbourPos.y, 3);
				}
			}
		}
	}
}

void Grid::SortOpenList()
{
	for (int i = 0; i < m_OpenList.size(); ++i)
	{
		for (int j = 0; j < m_OpenList.size() - 1; ++j)
		{
			if (m_OpenList[j]->m_nFScore > m_OpenList[j + 1]->m_nFScore)
			{
				Node* swap = m_OpenList[j];
				m_OpenList[j] = m_OpenList[j + 1];
				m_OpenList[j + 1] = swap;
			}
		}
	}

}

std::vector<Vector2> Grid::GetPath(Vector2 v2Start, Vector2 v2End, bool Astar)
{
	std::vector<Vector2> path;
	Node* pStart = GetNodeByPos(v2Start);
	Node* pEnd = GetNodeByPos(v2End);

	// Safety Check
	if (!pStart || !pEnd)
		return path;

	if (pStart->m_bBlocked || pEnd->m_bBlocked)
		return path;

	//clear open list
	m_OpenList.clear();
	memset(m_ClosedList, 0, sizeof(bool) * GRID_SIZE * GRID_SIZE);

	//set start node's G score to zerp and prev to null
	pStart->m_nGScore = 0;
	pStart->m_pPrev = nullptr;
	m_OpenList.push_back(pStart);

	while(m_OpenList.size() > 0)
	{
		//sort open list
		SortOpenList();

		//Remove lowest node from open list and add to closed list
		Node* pCurrent = m_OpenList[0];
		m_OpenList.erase(m_OpenList.begin());
		m_ClosedList[pCurrent->m_nIndexX][pCurrent->m_nIndexY] = true;

		//Complete path here
		if (pCurrent == pEnd)
		{
			//Add current to path
			path.push_back(pCurrent->m_v2Pos);
			//
			while (pCurrent->m_pPrev)
			{
				pCurrent = pCurrent->m_pPrev;
				path.push_back(pCurrent->m_v2Pos);
			}
			return path;
		}

		//Loop through all neighbours and add them to open list
		for (int i = 0; i < NEIGHBOUR_COUNT; ++i)
		{
			Node* pNeighbour = pCurrent->m_Neighbours[i];
			//Skip null neighbours
			if (!pNeighbour)
				continue;

			//skip blocked neighbours
			if (pNeighbour->m_bBlocked)
				continue;

			//skip neighbours that are already in closed list
			if (m_ClosedList[pNeighbour->m_nIndexX][pNeighbour->m_nIndexY])
				continue;

			//if neighbour is already in open list
			if (std::find(m_OpenList.begin(), m_OpenList.end(), pNeighbour) != m_OpenList.end())
			{
				//check if this is a better path (comparing G scores)
				int newGScore = pCurrent->m_nGScore + pCurrent->m_Costs[i];
				if (newGScore < pNeighbour->m_nGScore)
				{
					//Update to use the better path
					pNeighbour->m_nGScore = newGScore;
					pNeighbour->m_nFScore = pNeighbour->m_nGScore + pNeighbour->m_nHScore;
					pNeighbour->m_pPrev = pCurrent;
				}

			}
			else
			{
				//calculate G and F scores (and H for A*)
				pNeighbour->m_nGScore = pCurrent->m_nGScore + pCurrent->m_Costs[i];

				if (Astar)//A*
				{
					int diffX = abs(pEnd->m_nIndexX - pNeighbour->m_nIndexX);
					int diffY = abs(pEnd->m_nIndexY - pNeighbour->m_nIndexY);
					pNeighbour->m_nHScore = (diffX + diffY) * 10;
				}
				else
					pNeighbour->m_nHScore = 0; //Dijkstras

				pNeighbour->m_nFScore = pNeighbour->m_nGScore + pNeighbour->m_nHScore;

				//set prev node pointer to the current node
				pNeighbour->m_pPrev = pCurrent;

				//Add node to open list
				m_OpenList.push_back(pNeighbour);
			}
		}
	}

	return path;
}

Node* Grid::GetNodeByPos(Vector2 v2Pos)
{
	int x = (int)((v2Pos.x - OFFSET_X) / NODE_SIZE);
	int y = (int)((v2Pos.y - OFFSET_Y) / NODE_SIZE);

	if (x < 0)
		return nullptr;
	if (y < 0)
		return nullptr;
	if (x >= OFFSET_X)
		return nullptr;
	if (x >= OFFSET_Y)
		return nullptr;

	return m_Nodes[x][y];
}