#include "Wanderstate.h"
#include <glm\ext.hpp>
#include <random>
#include <time.h>
#include "FiniteStateMachines.h"
#include "SeekBehavior.h"



Wanderstate::Wanderstate()
{
}


Wanderstate::~Wanderstate()
{
}

Wanderstate::Wanderstate(Agent * target, float wanderDistance, float wanderRadius, float jitterAmount)
{

	m_WanderDist = wanderDistance;
	m_wanderRad = wanderRadius;
	m_JitterAmount = jitterAmount;
	randomVec = glm::vec2(rand() % (int)m_JitterAmount, rand() % (int)m_JitterAmount);
	m_target = target;
}

void Wanderstate::update(Agent * agent, FiniteStateMachines * sm, float deltaTime)
{
	
	glm::vec2 circle = glm::circularRand(m_wanderRad);
	glm::vec2 newTarget = glm::vec2();


}

void Wanderstate::init(Agent * agent)
{
}

void Wanderstate::exit(Agent * agent)
{
}
