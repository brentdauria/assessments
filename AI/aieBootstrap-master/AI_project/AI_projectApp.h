#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <glm\glm.hpp>


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
	Agent*				m_testAgent;
	aie::Texture*		m_agentTexture;

	Vector<Agent*> agents;
};