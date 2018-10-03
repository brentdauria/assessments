#pragma once
#include "baseState.h"
class PatrolState : public baseState
{
public:
	PatrolState();
	~PatrolState();

	virtual void OnEnter();
	virtual void OnUpdate(StateMachine* pStateMachine);
	virtual void OnExit();
};

