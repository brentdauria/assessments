#pragma once
#include "BaseState.h"
class FleeState : public BaseState
{
public:
	FleeState();
	~FleeState();

	virtual void OnEnter();
	virtual void OnUpdate(StateMachine* pStateMachine, Agent* agent, float fDeltaTime);
	virtual void OnExit();
};

