#pragma once

#include <glm/vec2.hpp>
#include <vector>


class IBehavior;
class FiniteStateMachines;
class Agent
{
public:
	Agent();
	Agent(float a_positionX, float a_positionY);
	~Agent();

	void AddForce(float a_forceX, float a_forceY);

	void update(float deltaTime);

	void AddBehavior(IBehavior* behavior);
	void SetMachine(FiniteStateMachines* Fmachines);
	
	glm::vec2 m_position;
	glm::vec2 m_velocity;
	glm::vec2 m_acceleration;

	float m_maxForce;
	
	FiniteStateMachines* FMachine;
	std::vector<IBehavior*> behaviors;
};

