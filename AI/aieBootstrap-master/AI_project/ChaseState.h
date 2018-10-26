#pragma once
#include "IBehavior.h"
#include "FiniteStateMachines.h"
class ChaseState : public State
{
public:

	virtual void OnEnter();
	virtual void Update(Agent* Agent, float deltaTime, FiniteStateMachines* sm);
	virtual void OnExit();
	ChaseState();
	ChaseState(Agent* target);
	~ChaseState();
	
	
private:
	 Agent* m_target; 
	 float playerRadius;
};

