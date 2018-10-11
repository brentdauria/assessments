#include "FiniteStateMachines.h"



FiniteStateMachines::FiniteStateMachines()
{
}

void FiniteStateMachines::SetCurrentState(State * currentState)
{
	this->currentState = currentState;
}


FiniteStateMachines::~FiniteStateMachines()
{
}

void FiniteStateMachines::Update(float deltaTime, Agent * agent)
{
	currentState->Update(agent, deltaTime, this);
}
