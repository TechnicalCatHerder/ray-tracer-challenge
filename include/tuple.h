// ReSharper disable CppClangTidyCppcoreguidelinesSpecialMemberFunctions
#pragma once

class Tuple
{
public:
    Tuple(float x, float y, float z, float w);
	~Tuple() = default;

	// Getter methods
	float GetX() const { return x_; }
	float GetY() const { return y_; }
	float GetZ() const { return z_; }
	float GetW() const { return w_; }

	bool IsPoint() const;
	bool IsVector() const;

	// It's unclear why the book has me measuring W as part of Magnitude but it's there so I'm putting it here.
	// Magnitude is only measured for a Vector and W will always be 0.
	float Magnitude();
	Tuple Normalize();
	float DotProduct(Tuple t);
	Tuple CrossProduct(Tuple t);

private:
	float x_, y_, z_, w_;
};

Tuple Vector(float x, float y, float z);
Tuple Point(float x, float y, float z);

Tuple operator +(Tuple lhs, Tuple rhs);
Tuple operator -(Tuple lhs, Tuple rhs);
Tuple operator -(Tuple t);
Tuple operator *(float lhs, Tuple rhs);
Tuple operator /(Tuple lhs, float rhs);
bool operator ==(Tuple lhs, Tuple rhs);

