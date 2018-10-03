#pragma once
#include "BaseState.h"
class ChaseState : public BaseState
{
public:
	ChaseState();
	~ChaseState();

	virtual void OnEnter();
	virtual void OnUpdate(StateMachine* pStateMachine, Agent* agent, float fDeltaTime);
	virtual void OnExit();
};

