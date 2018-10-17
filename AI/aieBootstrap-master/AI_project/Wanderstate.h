#pragma once
#include "State.h"
class Wanderstate : public State
{
public:
	Wanderstate();
	~Wanderstate();

	Wanderstate(Agent* target, float wanderDistance, float wanderRadius, float jitterAmount);
	virtual void update(Agent* agent, FiniteStateMachines * sm, float deltaTime);
	//not sure of the need of the following voids
	virtual void init(Agent* agent);
	virtual void exit(Agent* agent);

private:
	float m_WanderDist;
	float m_wanderRad;
	float m_JitterAmount;
	glm::vec2 randomVec;
	Agent * m_target;
};

