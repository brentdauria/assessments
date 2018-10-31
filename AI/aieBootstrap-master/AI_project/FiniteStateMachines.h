#pragma once
#include "State.h"
#include <vector>
class FiniteStateMachines
{
public:
	FiniteStateMachines();
	void SetCurrentState(State* currentState);
	~FiniteStateMachines();
	void Update(float deltaTime, Agent* agent);
	void PrevState(State* Prevstate);
	void changeState(Agent* Agent, State* newState);

private:
	State * currentState;
	State * prevState;

	std::vector<State*> states;
};

