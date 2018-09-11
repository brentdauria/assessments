
class Vector2
{
public:

	union
	{
		struct
		{
			float m_x;
			float m_y;
		};
	};

	Vector2();
	Vector2(float x, float y);
	Vector2(const Vector2& other);

	Vector2 operator + (Vector2 other);
	Vector2 operator - (Vector2 other);
	Vector2 operator * (float scalar) const;
	Vector2 operator / (float scalar);
	friend Vector2 operator * (float scalar, const Vector2& other);


	float magnitude();
	void normalise();

	~Vector2();
};
