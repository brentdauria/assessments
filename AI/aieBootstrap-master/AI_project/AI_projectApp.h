#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <glm\glm.hpp>
#include <vector>


class Agent;
class Ants;
class AI_projectApp : public aie::Application {
public:

	AI_projectApp();
	virtual ~AI_projectApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	Ants* m_ant;
	Agent*				m_target;
	Agent*				m_otherAgent;
	Agent*				m_agent;
	aie::Texture*		m_otherTexture;
	aie::Texture*		m_agentTexture;

	std::vector<Agent*> agents;
};