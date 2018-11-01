#pragma once
#include "State.h"
class Searchstate : public State
{
public:
	Searchstate();
	~Searchstate();

	Searchstate(Agent* target, float wanderDistance, float wanderRadius, float jitterAmount);
	virtual void Update(Agent* Agent, float deltaTime, FiniteStateMachines* sm);
	//not sure of the need of the following voids
	virtual void OnEnter(Agent* agent);
	virtual void OnExit(Agent* agent);

private:
	float m_WanderDist;
	float m_wanderRad;
	float m_JitterAmount;
	glm::vec2 randomVec;
	//Agent *m_target = new Agent();
	Agent *m_target;
};

