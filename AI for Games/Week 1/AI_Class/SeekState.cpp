#include "SeekState.h"



SeekState::SeekState()
{
	m_target = nullptr;
}

SeekState::SeekState(Agent * target)
{
	m_target = target;
}

void SeekState::update(Agent * agent, float deltaTime)
{
	Vector2 desiredVel = m_target->position - agent->position;
	desiredVel.normalise();
	desiredVel = desiredVel * 100.0f;
	Vector2 force = desiredVel - agent->velocity;
	agent->AddForce(force);
}


SeekState::~SeekState()
{
	delete m_target;
}
