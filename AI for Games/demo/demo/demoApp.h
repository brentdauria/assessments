#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <vector>

class Agent;

class demoApp : public aie::Application {
public:

	demoApp();
	virtual ~demoApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	aie::Texture*		m_agentTexture;
	Agent*				m_testAgent;

	std::vector<Agent*> agents;
};