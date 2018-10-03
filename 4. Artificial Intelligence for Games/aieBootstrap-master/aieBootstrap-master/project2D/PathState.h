#pragma once
#include "BaseState.h"
class PathState : public BaseState
{
public:
	PathState();
	~PathState();

	virtual void OnEnter();
	virtual void OnUpdate(StateMachine* pStateMachine, Agent* agent, float fDeltaTime);
	virtual void OnExit();
};

