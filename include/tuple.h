// ReSharper disable CppClangTidyCppcoreguidelinesSpecialMemberFunctions
#pragma once

class Tuple
{
public:
	Tuple(float x, float y, float z, float w);
	~Tuple();

	// Getter methods
	float GetX() const;
	float GetY() const;
	float GetZ() const;
	float GetW() const;

	bool IsPoint() const;
	bool IsVector() const;


	

private:
	float x_, y_, z_, w_;
};

Tuple Vector(float x, float y, float z);
Tuple Point(float x, float y, float z);