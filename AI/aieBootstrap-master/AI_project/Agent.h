#pragma once

#include <glm/vec2.hpp>
#include <vector>
#include "Vector2.h"

class IBehavior;
class Agent
{
public:
	Agent();
	Agent(float a_positionX, float a_positionY);
	~Agent();

	void AddForce(float a_forceX, float a_forceY);

	void update(float deltaTime);

	void AddBehavior(IBehavior* behavior);

	glm::vec2 m_position;
	glm::vec2 m_velocity;
	glm::vec2 m_acceleration;

	float m_maxForce;

	
};

