#include "Agent.h"
#include "IBehavior.h"


Agent::Agent()
{

}

Agent::Agent(float a_positionX, float a_positionY)
{
	this->m_position.x = a_positionX;
	this->m_position.y = a_positionY;

	m_velocity = glm::vec2(0, 0);
	m_acceleration = glm::vec2(0, 0);

	m_maxForce = 0.1f;

}


Agent::~Agent()
{

}

void Agent::AddForce(float a_forceX, float a_forceY)
{
	m_acceleration.x += a_forceX;
	m_acceleration.y += a_forceY;
}

void Agent::update(float deltaTime)
{
	AddForce(m_velocity.x * -1.f, m_velocity.y * -1.f);

	m_position += m_velocity * deltaTime;

	m_velocity += m_acceleration * deltaTime;

	m_acceleration = glm::vec2(0, 0);

	for (auto iter = behaviors.begin(); iter != behaviors.end(); ++iter)
		(*iter)->update(deltaTime, this);

}

void Agent::AddBehavior(IBehavior * behavior)
{
	behaviors.push_back(behavior);
}
