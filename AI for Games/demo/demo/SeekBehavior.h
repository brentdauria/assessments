#pragma once
#include "IBehavior.h"
class SeekBehavior : public IBehavior
{
public:
	SeekBehavior();
	SeekBehavior(Agent* target);
	~SeekBehavior();
	void update(float a_deltaTime, Agent* agent)override;

private:
	Agent * m_target;
};

