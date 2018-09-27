#include "Ants.h"
#include <Texture.h>
#include <Renderer2D.h>
#include "AI_projectApp.h"




void Ants::Update(float deltaTime, aie::Input * input)
{
}

void Ants::Draw(aie::Renderer2D * spritebatch)
{
	spritebatch->drawSprite(m_texture, m_pos.x, m_pos.y, 100, 100);

}

Ants::Ants(glm::vec2 pos)
{
	m_pos = pos;
	m_texture = new aie::Texture("../bin/textures/Ant.png");

	
}
	

Ants::Ants()
{
}


Ants::~Ants()
{
}
