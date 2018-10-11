#pragma once

#include "Application.h"
#include "Renderer2D.h"
class Agent;
class AI_ClassApp : public aie::Application {
public:

	AI_ClassApp();
	virtual ~AI_ClassApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	Agent*				m_player;
	Agent*				m_AI;
	//std::vector<Agent*> m_agents;

};