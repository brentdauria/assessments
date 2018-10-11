#include "Player.h"
#include <Texture.h>
#include <Renderer2D.h>
#include <Input.h>
#include <Vector3.h>
#include <GenLib.h>
#include <math.h>
Player::Player()
{
	m_texture = new aie::Texture("../bin/textures/ship.png");
	m_position = Vector2(100, 200);
	m_speed = 50.0f;
	m_rotation = 0.0f;
	m_velocity = Vector2(0, 0);
	m_acceleration = Vector2(0, 0);
	m_local = m_local.createTranslation(m_position.m_x, m_position.m_y, 1);
	m_rotationSpeed = 10.0f;
}

void Player::update(float deltaTime, aie::Input* input)
{
	Vector2 rotation(cosf(m_rotation), sinf(m_rotation));

	Vector2 force = m_local.axis[1];
	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		MoveForward(m_speed * deltaTime);
		AddForce(force);
	}
	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		TurnLeft(m_rotationSpeed * deltaTime);
	}
	if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		
	}
	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		TurnRight(m_rotationSpeed * deltaTime);
	}
	AddForce(m_velocity * -0.50f);
	m_velocity = m_velocity + m_acceleration * deltaTime;
	m_position = m_position + m_velocity * deltaTime;
	m_acceleration = Vector2(0, 0);

	Matrix3 mTrans = Matrix3::createTranslation(m_position.m_x, m_position.m_y, 1);
	Matrix3 mRot = Matrix3::createRotation(m_rotation);
	Matrix3 mScale = Matrix3::createScale(1, 1);
	m_local = mTrans * mRot * mScale;
	m_world = m_local;

}

void Player::draw(aie::Renderer2D * renderer)
{
	renderer->drawSpriteTransformed3x3(m_texture, (float*)m_world);
}

void Player::MoveForward(float a_amount)
{
	Vector3 forward = Vector3(0, a_amount, 1);
	Vector3 pos = m_local * forward;
	m_position = Vector2(pos.m_x, pos.m_y);
}

void Player::TurnLeft(float a_rot)
{
	m_rotation += a_rot;
}

void Player::TurnRight(float a_rot)
{
	m_rotation -= a_rot;
}

void Player::AddForce(Vector2 force)
{
	m_acceleration = m_acceleration + force;
}


Player::~Player()
{
}
