#include "Vector2.h"
#include <math.h>

Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::~Vector2()
{
}

Vector2 Vector2::operator+(Vector2 rhs)
{
	Vector2 result;
	result.x = this->x + rhs.x;
	result.y = this->y + rhs.y;

	return result;
}


Vector2 Vector2::operator-(Vector2 rhs)
{
	Vector2 result;
	result.x = this->x - rhs.x;
	result.y = this->y - rhs.y;

	return result;
}


Vector2 Vector2::operator*(float rhs)
{
	Vector2 result;
	result.x = this->x * rhs;
	result.y = this->y * rhs;

	return result;
}

float Vector2::magnitude()
{
	return sqrtf((x * x) + (y * y));

}

void Vector2::normalise()
{
	float mag = magnitude();
	x /= mag;
	y /= mag;
}

float Vector2::dot(Vector2 rhs)
{
	float result = this->x * rhs.x + this->y * rhs.y;
	return result;
}

float& Vector2::operator[](int index)
{
	if (index == 0)
	{
		return x;
	}
	else
	{
		return y;
	}

}

Vector2::operator float*()
{
	return &x;

}