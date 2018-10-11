#pragma once
#include "Agent.h"
class FiniteStateMachines;
class State
{
public:
	State();
	virtual void Update(Agent* Agent, float deltaTime, FiniteStateMachines* sm) = 0;
	~State();
};

