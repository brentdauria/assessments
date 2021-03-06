#include "Agent.h"
#include <Renderer2D.h>
#include <Texture.h>
#include "IBehavior.h"

Agent::Agent()
{
	texture = nullptr;
	position = Vector2(0, 0);
	acceleration = Vector2(0, 0);
	velocity = Vector2(0, 0);
}

Agent::Agent(aie::Texture * texture, Vector2 position)
{
	this->texture = texture;
	this->position = position;
	acceleration = Vector2(0, 0);
	velocity = Vector2(0, 0);
}

void Agent::update(float deltaTime)
{
	AddForce(velocity * -0.15f);
	velocity = velocity + acceleration * deltaTime;
	position = position + velocity * deltaTime;
	acceleration = Vector2(0, 0);
	for (auto behavior : m_behaviors)
	{
		behavior->update(this, deltaTime);
	}
}

void Agent::draw(aie::Renderer2D * renderer)
{
	renderer->drawSprite(texture, position.m_x, position.m_y);
}

void Agent::AddForce(Vector2 force)
{
	acceleration = acceleration + force;
}

void Agent::AddBehavior(IBehavior * behavior)
{
	m_behaviors.push_back(behavior);
}


Agent::~Agent()
{
	delete texture;
}
