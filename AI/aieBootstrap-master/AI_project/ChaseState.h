#pragma once
#include "IBehavior.h"
#include "FiniteStateMachines.h"
class ChaseState
{
public:

	virtual void OnEnter();
	virtual void Update(Agent* Agent, float deltaTime, FiniteStateMachines* sm);
	virtual void OnExit();
	ChaseState();
	~ChaseState();

private:
	 Agent * m_target;

};

