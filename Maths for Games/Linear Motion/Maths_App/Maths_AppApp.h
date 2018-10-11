#pragma once

#include "Application.h"
#include "Renderer2D.h"
class Player;
class Maths_AppApp : public aie::Application {
public:

	Maths_AppApp();
	virtual ~Maths_AppApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	Player*				m_player;
};