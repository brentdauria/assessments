#include "Chasestate.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "IBehavior.h"
#include "Searchstate.h"



void ChaseState::OnEnter()
{
}

// chase the target
void ChaseState::Update(Agent * Agent, float deltaTime, FiniteStateMachines * sm)
{
	glm::vec2 Vel = m_target->m_position - Agent->m_position;
	Vel = glm::normalize(Vel);
	Vel = Vel * 100.0f;
	glm::vec2 force = Vel - Agent->m_velocity;
	Agent->AddForce(force.x, force.y);

	glm::vec2 dist = m_target->m_position - Agent->m_position;
	float mag = glm::length(dist);
	if (mag > 100.0f)
		sm->changeState(Agent, new Searchstate(m_target, 15.0f, 25.0f, 25.0f));
}

void ChaseState::OnExit()
{
}

ChaseState::ChaseState()
{
	//m_target = nullptr;
}

ChaseState::ChaseState(Agent * target)
{
	// getting the target to chase
	m_target = target;

}


ChaseState::~ChaseState()
{
}
