#include "tuple.h"
#include "math_functions.h"


Tuple::Tuple(float x, float y, float z, float w)
        : x_(x), y_(y), z_(z), w_(w) {
}

bool Tuple::IsPoint() const
{ 
	return FloatEquality(w_, 1.0f);
}

bool Tuple::IsVector() const
{
    return FloatEquality(w_, 0.0f);
}

Tuple Point(float x, float y, float z) 
{ 
	return Tuple{x, y, z, 1.0f}; 
}

Tuple Vector(float x, float y, float z)
{
	return Tuple(x, y, z, 0.0f);
}

Tuple operator+(Tuple lhs, Tuple rhs) {
    return Tuple(lhs.GetX() + rhs.GetX(), lhs.GetY() + rhs.GetY(), lhs.GetZ() + rhs.GetZ(), lhs.GetW() + rhs.GetW());
}

Tuple operator-(Tuple lhs, Tuple rhs) {
    return Tuple(lhs.GetX() - rhs.GetX(), lhs.GetY() - rhs.GetY(), lhs.GetZ() - rhs.GetZ(), lhs.GetW() - rhs.GetW());
}

Tuple operator-(Tuple t) {
    return Tuple(-t.GetX(), -t.GetY(), -t.GetZ(), -t.GetW());
}

Tuple operator*(float lhs, Tuple rhs) {
    return Tuple(lhs * rhs.GetX(), lhs * rhs.GetY(), lhs * rhs.GetZ(), lhs * rhs.GetW());
}

Tuple operator/(float lhs, Tuple rhs) {
    return Tuple(lhs / rhs.GetX(), lhs / rhs.GetY(), lhs / rhs.GetZ(), lhs / rhs.GetW());
}








