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

private:
	float x_, y_, z_, w_;
};

Tuple Vector(float x, float y, float z);
Tuple Point(float x, float y, float z);

Tuple operator +(Tuple lhs, Tuple rhs);
Tuple operator -(Tuple lhs, Tuple rhs);
Tuple operator -(Tuple t);
Tuple operator *(float lhs, Tuple rhs);
Tuple operator /(float lhs, Tuple rhs);

