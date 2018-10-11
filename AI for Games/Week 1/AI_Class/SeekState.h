#pragma once
#include "IBehavior.h"
class SeekState : public IBehavior
{
public:
	SeekState();
	SeekState(Agent* target);
	virtual void update(Agent* agent, float deltaTime);
	~SeekState();

private:
	Agent* m_target;
};

