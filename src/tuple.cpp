#include "tuple.h"


Tuple::Tuple(float x, float y, float z, float w): x_(x), y_(y), z_(z), w_(w)
{}

float Tuple::GetX() const
{ return x_; }

float Tuple::GetY() const
{ return y_; }

float Tuple::GetZ() const
{ return z_; }

float Tuple::GetW() const
{ return w_; }

Tuple::~Tuple()
= default;

bool Tuple::IsPoint() const
{
	// Needs epsilon to compare floating point values.
	return false;
}

bool Tuple::IsVector() const
{
	// Needs epsilon to compare floating point values.
	return false;
}


Tuple Vector(float x, float y, float z)
{
	return Tuple(x, y, z, 0.0f);
}

Tuple Point(float x, float y, float z)
{
	return Tuple{ x, y, z, 1.0f };
}
