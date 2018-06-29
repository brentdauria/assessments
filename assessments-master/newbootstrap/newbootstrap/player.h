#pragma once
#include<Input.h>
#include <glm\vec2.hpp>
#include <vector>
#include "rock.h"

namespace aie {
	class Texture;
	class Renderer2D;
	class Input;
	class Font;
}

class rock;

class player
{
public:
	player();
	player(glm::vec2 pos);
	~player();
	void Update(float deltaTime, aie::Input* input);
	void Draw(aie::Renderer2D* spritebatch);
	bool isGameOver();

private:
	glm::vec2	m_pos;
	glm::vec2	m_tarPos;
	aie::Texture* m_texture;
	float playerspeed = 320.0f;
	rock* m_rock;
	float distanceX = 0.0f;
	float distanceY = 0.0f;
};

