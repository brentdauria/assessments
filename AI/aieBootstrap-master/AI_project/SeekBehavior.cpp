#include "SeekBehavior.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>



SeekBehavior::SeekBehavior()
{
	m_target = nullptr;
}

SeekBehavior::SeekBehavior(Agent * target)
{
	m_target = target;
}


SeekBehavior::~SeekBehavior()
{
}

void SeekBehavior::update(float a_deltaTime, Agent * agent)
{
	glm::vec2 Vel = m_target->m_position - agent->m_position;
	Vel = glm::normalize(Vel);
	Vel = Vel * 100.0f;
	glm::vec2 force = Vel - agent->m_velocity;
	agent->AddForce(force.x, force.y);


}
