#include "WanderState.h"
#include <glm\ext.hpp>
#include <random>
#include <time.h>
#include "StateMachine.h"
#include "SeekState.h"

WanderState::WanderState()
{
}

WanderState::WanderState(Agent* target, float wanderDistance, float wanderRadius, float jitterAmount)
{
	m_wanderDist = wanderDistance;
	m_wanderRad = wanderRadius;
	m_jitterAmount = jitterAmount;
	// randome target on the edge of the sphere 
	randomVec = Vector2(rand() % (int)m_jitterAmount, rand() % (int)m_jitterAmount);
	m_target = target;
}

void WanderState::update(Agent * agent, StateMachine * sm, float deltaTime)
{
	// set the sphere based on the wander_radius
	glm::vec2 circle = glm::circularRand(m_wanderRad);
	// create a new Target by adding the rand vec and circle
	Vector2 newTarget = Vector2(rand_Vec.m_x + circle.x, randomVec.m_y + circle.y);
	// normalise the new target
	newTarget.normalise();
	Vector2 normalisedTarget = newTarget;
	// project it back on the to the sphere
	Vector2 targetOnSphere = normalisedTarget * m_wanderRad;
	// move in straight line towards the target on the sphere
	targetOnSphere.normalise();
	Vector2 force = targetOnSphere;
	force = force * 50.0f;

	agent->AddForce(force);
	
	Vector2 dist = m_target->GetPosition() - agent->GetPosition();
	float mag = dist.magnitude();
	if (mag < 100.0f)
		sm->ChangeState(agent, new SeekState(m_target));

}

void WanderState::init(Agent * agent)
{
}

void WanderState::exit(Agent * agent)
{
}


WanderState::~WanderState()
{
}
