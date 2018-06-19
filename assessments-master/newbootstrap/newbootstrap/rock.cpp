#include "rock.h"
#include <Texture.h>
#include <Renderer2D.h>
#include <iostream>


rock::rock()
{
	bouncey = false;
	bouncex = false;
}


rock::~rock()
{
}

rock::rock(glm::vec2 pos)
{
	m_texture = new aie::Texture("../bin/textures/rock_large.png");
	m_pos = pos;
}

void rock::Update(float deltaTime)
{
	timer += deltaTime;
	if (timer >= 1.0f)
	{
		rockspeed = rockspeed * 1.1;
		timer = 0.0f;
		if (rockspeed == 300)
		{
			rockspeed = 290;
		}
	}
	if (m_pos.y >= 10 && !bouncey) {

	m_pos.y -= rockspeed * deltaTime;
	}
	else {
		bouncey = true;
	}
	if (m_pos.y <= 700 && bouncey) {
		
		m_pos.y += rockspeed * deltaTime;
	}
	else {
		bouncey = false;
	}

	if (m_pos.x >= 10 && !bouncex) {
		
		m_pos.x -= rockspeed * deltaTime;
	}
	else {
		bouncex = true;
	}
	if (m_pos.x <= 1240 && bouncex) {
		
		m_pos.x += rockspeed * deltaTime;
	}
	else {
		bouncex = false;
	}
	
}

void rock::Draw(aie::Renderer2D * spritebatch)
{
	spritebatch->drawSprite(m_texture, m_pos.x, m_pos.y);
}
