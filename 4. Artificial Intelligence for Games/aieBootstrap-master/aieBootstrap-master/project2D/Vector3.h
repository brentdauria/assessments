#pragma once
struct Vector3
{
	Vector3();
	Vector3(float x, float y, float z);
	~Vector3();

	Vector3 operator+(Vector3 rhs);
	Vector3 operator-(Vector3 rhs);
	Vector3 operator*(float rhs);

	float magnitude();
	void normalise();
	float dot(Vector3 rhs);
	Vector3 cross(Vector3 rhs);
	float& operator[](int index);
	explicit operator float*();

	float x;
	float y;
	float z;

};

static Vector3 operator* (float lhs, Vector3 rhs)
{
	Vector3 result;
	result.x = rhs.x * lhs;
	result.y = rhs.y * lhs;
	result.z = rhs.z * lhs;
	return result;

}



