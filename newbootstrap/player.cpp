#include "player.h"
#include <Texture.h>
#include <Renderer2D.h>
#include <iostream>
#include "rock.h"

class rock;
player::player()
{
	
}

player::player(glm::vec2 pos)
{
	m_texture = new aie::Texture("../bin/textures/ship.png");
	m_pos = pos;
	m_rock = new rock(glm::vec2(1000, 600));
	isGameOver();
}


player::~player()
{
	delete m_rock; 
}

void player::Update(float deltaTime, aie::Input * input)
{
	if ((input->isKeyDown(aie::INPUT_KEY_LEFT) || input->isKeyDown(aie::INPUT_KEY_A)) && m_pos.x >= 50)
	{
		//sets player speed in the left direction
		m_pos.x -= playerspeed * deltaTime;
	}

	if ((input->isKeyDown(aie::INPUT_KEY_RIGHT) || input->isKeyDown(aie::INPUT_KEY_D)) && m_pos.x <= 1230)
	{
		//sets player speed in the right direction
		m_pos.x += playerspeed * deltaTime;
	}

	if ((input->isKeyDown(aie::INPUT_KEY_UP) || input->isKeyDown(aie::INPUT_KEY_W)) && m_pos.y <= 650)
	{
		//sets player speed in the up direction
		m_pos.y += playerspeed * deltaTime;
	}

	if ((input->isKeyDown(aie::INPUT_KEY_DOWN) || input->isKeyDown(aie::INPUT_KEY_S)) && m_pos.y >= 50)
	{
		//sets player speed in the down direction
		m_pos.y -= playerspeed * deltaTime;
	}

	if (bool(input->wasKeyPressed(aie::INPUT_KEY_SPACE)))
	{
		playerspeed = playerspeed * 2;
	}
	else if (bool(input->wasKeyReleased(aie::INPUT_KEY_SPACE)))
	{ 
		playerspeed = playerspeed / 2;
	}

	m_rock->Update(deltaTime);


	isGameOver();
	
}

void player::Draw(aie::Renderer2D * spritebatch)
{
	spritebatch->drawSprite(m_texture, m_pos.x, m_pos.y);
	m_rock->Draw(spritebatch);
}

bool player::isGameOver()
{
	distanceX = m_pos.x - m_rock->m_pos.x;
	distanceY = m_pos.y - m_rock->m_pos.y;
	if ((distanceX < 35 && distanceX > -35) && (distanceY < 43 && distanceY > -43))
	{
		return true;
	}
	return false;
}
