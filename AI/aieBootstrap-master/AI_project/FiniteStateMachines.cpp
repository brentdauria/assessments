#include "FiniteStateMachines.h"
#include "State.h"
#include "Agent.h"




FiniteStateMachines::FiniteStateMachines()
{
	currentState = nullptr;
	prevState = nullptr;
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

void FiniteStateMachines::PrevState(State * Prevstate)
{
}

void FiniteStateMachines::changeState(Agent * Agent, State * newState)
{
	if (currentState)
		currentState->OnExit();
	if (newState == NULL)
	{
		currentState = nullptr;
		return;
	}
	currentState = newState;
	prevState = currentState;
	if (currentState)
		currentState->OnEnter();
	
}


