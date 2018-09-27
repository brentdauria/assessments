#pragma once
#include<Input.h>
#include <glm\vec2.hpp>
#include <vector>
#include <Texture.h>

namespace aie {
	class Texture;
	class Renderer2D;
	class Input;
	class Font;
}


class Ants
{
public:
	Ants();
	~Ants();
	void Update(float deltaTime, aie::Input * input);
	void Draw(aie::Renderer2D* spritebatch);
	Ants(glm::vec2 pos);
	glm::vec2 m_pos;

	float antspeed = 500.0f;
	aie::Texture* m_texture;

};

