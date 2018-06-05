#pragma once

#include "Application.h"
#include "Renderer2D.h"


class player;
class rock;
class newbootstrapApp : public aie::Application {
public:

	newbootstrapApp();
	virtual ~newbootstrapApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:
	float m_timer;
	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	player* m_player;
	//rock* m_rock;

};