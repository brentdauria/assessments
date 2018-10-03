#include "Vector3.h"
#include <math.h>

Vector3::Vector3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::~Vector3()
{
}

Vector3 Vector3::operator+(Vector3 rhs)
{
	Vector3 result;
	result.x = this->x + rhs.x;
	result.y = this->y + rhs.y;
	result.z = this->z + rhs.z;

	return result;
}


Vector3 Vector3::operator-(Vector3 rhs)
{
	Vector3 result;
	result.x = this->x - rhs.x;
	result.y = this->y - rhs.y;
	result.z = this->z - rhs.z;

	return result;
}


Vector3 Vector3::operator*(float rhs)
{
	Vector3 result;
	result.x = this->x * rhs;
	result.y = this->y * rhs;
	result.z = this->z * rhs;

	return result;
}

float Vector3::magnitude()
{
	return sqrtf((x * x) + (y * y) + (z * z));

}

void Vector3::normalise()
{
	float mag = magnitude();
	x /= mag;
	y /= mag;
	z /= mag;
}

float Vector3::dot(Vector3 rhs)
{
	float result = this->x * rhs.x + this->y * rhs.y + this->z * rhs.z;
	return result;
}

Vector3 Vector3::cross(Vector3 rhs)
{
	Vector3 result;
	result.x = this->y * rhs.z - this->z * rhs.y;
	result.y = this->z * rhs.x - this->x * rhs.z;
	result.z = this->x * rhs.y - this->y * rhs.x;
	return result;
}

float& Vector3::operator[](int index)
{
	if (index == 0)
	{
		return x;
	}
	else if(index == 1)
	{
		return y;
	}
	else
	{
		return z;
	}

}

Vector3::operator float*()
{
	return &x;

}