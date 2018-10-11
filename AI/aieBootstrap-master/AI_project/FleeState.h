#pragma once
#include "State.h"
class FleeState : public State
{
public:
	FleeState();
	virtual void Update(Agent* Agent, float deltaTime, FiniteStateMachines* sm);
	~FleeState();
};

