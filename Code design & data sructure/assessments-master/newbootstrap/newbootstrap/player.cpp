#include "player.h"
#include <Texture.h>
#include <Renderer2D.h>
#include <iostream>
#include "rock.h"

class rock;
player::player()
{
	
}
//importing  textures and assigning startup positions
player::player(glm::vec2 pos) :
	m_pos(glm::vec2(0,0))
{
	m_texture = new aie::Texture("../bin/textures/ship.png");
	m_tarPos = pos;
	m_rock = new rock(glm::vec2(1000, 600));
	isGameOver();
}


player::~player()
{
	delete m_rock; 
}

void player::Update(float deltaTime, aie::Input * input)
{
	if ((input->isKeyDown(aie::INPUT_KEY_LEFT) || input->isKeyDown(aie::INPUT_KEY_A)) && m_tarPos.x >= 50)
	{
		//sets player speed in the left direction
		m_tarPos.x -= playerspeed * deltaTime;
	}

	if ((input->isKeyDown(aie::INPUT_KEY_RIGHT) || input->isKeyDown(aie::INPUT_KEY_D)) && m_tarPos.x <= 1230)
	{
		//sets player speed in the right direction
		m_tarPos.x += playerspeed * deltaTime;
	}

	if ((input->isKeyDown(aie::INPUT_KEY_UP) || input->isKeyDown(aie::INPUT_KEY_W)) && m_tarPos.y <= 650)
	{
		//sets player speed in the up direction
		m_tarPos.y += playerspeed * deltaTime;
	}

	if ((input->isKeyDown(aie::INPUT_KEY_DOWN) || input->isKeyDown(aie::INPUT_KEY_S)) && m_tarPos.y >= 50)
	{
		//sets player speed in the down direction
		m_tarPos.y -= playerspeed * deltaTime;
	}

	if (bool(input->wasKeyPressed(aie::INPUT_KEY_SPACE)))
	{// adds like a boost like feature changing the players speed
		playerspeed =  playerspeed * 4;
	}
	else if (bool(input->wasKeyReleased(aie::INPUT_KEY_SPACE)))
	{ 
		// resets the players speed when the key is released
		playerspeed = playerspeed / 4;
	}


	//adding a lerp gives the user a velocity like feel to flying the ship
	static float lerpAmount = 0.3f;
	m_pos -= (m_pos - m_tarPos) * lerpAmount * deltaTime;


	m_rock->Update(deltaTime);


	isGameOver();
	
}

void player::Draw(aie::Renderer2D * spritebatch)
{
	spritebatch->drawSprite(m_texture, m_pos.x, m_pos.y);
	m_rock->Draw(spritebatch);
}
//is game over checks if the postition of the player and rock are the same if so than the have colided
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
