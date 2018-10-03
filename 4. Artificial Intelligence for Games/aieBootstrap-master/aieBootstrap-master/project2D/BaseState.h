#pragma once

class StateMachine;
class Agent;

class BaseState
{
public:
	BaseState();
	virtual ~BaseState();

	virtual void OnEnter();
	virtual void OnUpdate(StateMachine* pStateMachine, Agent* agent, float fDeltaTime);
	virtual void OnExit();
};

