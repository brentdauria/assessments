#pragma once
#include "Agent.h"

class FiniteStateMachines;
//class Agent;
class State
{
public:
	State();
	virtual void OnEnter();
	virtual void Update(Agent* Agent, float deltaTime, FiniteStateMachines* sm) = 0;
	virtual void OnExit();
	~State();
	
	


};

