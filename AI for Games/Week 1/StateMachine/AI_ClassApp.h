#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <vector>
class Agent;
class StateMachine;
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
	StateMachine*		m_fsm;
	std::vector<Agent*> m_agents;

};