#pragma once

class StateMachine;

class baseState
{
public:
	baseState();
	virtual ~baseState();

	virtual void OnEnter();
	virtual void OnUpdate(StateMachine* pStateMachine);
	virtual void OnExit();
};