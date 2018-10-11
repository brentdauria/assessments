#pragma once
#include <Vector2.h>
#include <Matrix3.h>
namespace aie {
	class Texture;
	class Renderer2D;
	class Input;
}

class Player
{
public:
	Player();
	void update(float deltaTime, aie::Input* input);
	void draw(aie::Renderer2D* renderer);
	void MoveForward(float a_amount);
	void TurnLeft(float a_rot);
	void TurnRight(float a_rot);
	void AddForce(Vector2 force);
	~Player();

private:
	aie::Texture*	m_texture;
	Vector2			m_position;
	Vector2			m_acceleration;
	Vector2			m_velocity;
	float			m_speed;
	float			m_rotation;
	float			m_rotationSpeed;
	Matrix3			m_local;
	Matrix3			m_world;

};

