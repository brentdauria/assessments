#pragma once
#include "Agent.h"


class StateMachine;
class SeekBehaviour;
class Grid;

class Duck : public Agent
{
public:
	Duck(aie::Texture* pTexture, Vector2 v2Pos, float fRotRadians, Grid* pGrid);
	~Duck();

	void Update(float fDeltaTime);
	void Draw(aie::Renderer2D* pRenderer);
private:
	SeekBehaviour* m_pSeekBehaviour;
	Grid* m_pGrid;
	std::vector<Vector2> m_Path;
	StateMachine* m_pStateMachine;
	bool isFollowing;
	int nextWaypoint;
};

