#pragma once
#include "State.h"
class WanderState : public State
{
public:
	WanderState();
	WanderState(Agent* target, float wanderDistance, float wanderRadius, float jitterAmount);
	virtual void update(Agent* agent, StateMachine* sm, float deltaTime);
	virtual void init(Agent* agent);
	virtual void exit(Agent* agent);
	~WanderState();
private:
	float m_wanderDist;
	float m_wanderRad;
	float m_jitterAmount;
	Vector2 randomVec;
	Agent * m_target;
};

