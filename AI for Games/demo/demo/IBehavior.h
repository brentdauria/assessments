#pragma once
#include "Agent.h"
class IBehavior
{
public:
	IBehavior() {}
	virtual ~IBehavior() = 0 {}
	virtual void update(float a_deltaTime, Agent* agent) = 0;
};