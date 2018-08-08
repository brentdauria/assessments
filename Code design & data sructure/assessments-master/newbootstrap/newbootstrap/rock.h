#pragma once
#include <glm\vec2.hpp>
#include <vector>

namespace aie {
	class Texture;
	class Renderer2D;
	class Input;
	class Font;
}

class rock
{
public:
	rock();
	~rock();
	rock(glm::vec2 pos);
	void Update(float deltaTime);
	void Draw(aie::Renderer2D* spritebatch);
	float timer = 0.0f;
	glm::vec2	m_pos;
private:
	aie::Texture* m_texture;
	bool bouncex;
	bool bouncey;
	float rockspeed = 210.0f;
};

