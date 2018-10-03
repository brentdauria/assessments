#pragma once
#include "baseState.h"
class AttackState : public baseState
{
public:
	AttackState();
	~AttackState();

	virtual void OnEnter();
	virtual void OnUpdate(StateMachine* pStateMachine);
	virtual void OnExit();
};

