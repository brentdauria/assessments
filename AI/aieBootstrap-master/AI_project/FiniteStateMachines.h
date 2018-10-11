#pragma once
#include "State.h"
class FiniteStateMachines
{
public:
	FiniteStateMachines();
	void SetCurrentState(State* currentState);
	~FiniteStateMachines();
	void Update(float deltaTime, Agent* agent);

private:
	State * currentState;
	State * prevState;

};

