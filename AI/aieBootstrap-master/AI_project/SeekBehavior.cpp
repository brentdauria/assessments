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
	// velocity btw target and the ai agent
	glm::vec2 Vel = m_target->m_position - agent->m_position;
	// normalize the velocity
	Vel = glm::normalize(Vel);
	// apply speed
	Vel = Vel * 100.0f;
	// subtract the velocity with agent's current velocity
	glm::vec2 force = Vel - agent->m_velocity;
	// add the force to the ai agent
	agent->AddForce(force.x, force.y);


}
