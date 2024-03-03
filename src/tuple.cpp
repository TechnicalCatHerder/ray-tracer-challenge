#include "tuple.h"
#include "math_functions.h"
#include <cmath>


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

float Tuple::Magnitude()
{
    return sqrtf (this->x_ * this->x_ + this->y_ * this->y_ + this->z_ * this->z_ + this->w_ * this->w_);
}

Tuple Tuple::Normalize()
{
    float VectorMagnitude = this->Magnitude();
    return Tuple(this->x_  / VectorMagnitude, this->y_ / VectorMagnitude, this->z_  / VectorMagnitude, this->w_ / VectorMagnitude);
}

float Tuple::DotProduct(Tuple t)
{
    return (this->x_ * t.GetX() + this->y_ * t.GetY() + this->z_ * t.GetZ() + this->w_ * t.GetW());
}

Tuple Tuple::CrossProduct(Tuple t)
{
    return Vector(this->y_ * t.GetZ() - this->z_ * t.GetY(),
                    this->z_ * t.GetX() - this->x_ * t.GetZ(),
                    this->x_ * t.GetY() - this->y_ * t.GetX());
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

Tuple operator/(Tuple lhs, float rhs) {
    return Tuple(lhs.GetX() / rhs, lhs.GetY() / rhs, lhs.GetZ() / rhs, lhs.GetW() / rhs);
}

bool operator==(Tuple lhs, Tuple rhs) {
    return FloatEquality(lhs.GetX(), rhs.GetX()) && FloatEquality(lhs.GetY(), rhs.GetY()) && FloatEquality(lhs.GetZ(), rhs.GetZ()) && FloatEquality(lhs.GetW(), rhs.GetW());
}








