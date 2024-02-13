#pragma once

class tuple
{
public:
	tuple(float x, float y, float z, float w)
		: x_(x), y_(y), z_(z), w_(w) {};
	~tuple() = default;

	// Getter methods
	float getX() const { return x_; }
	float getY() const { return y_; }
	float getZ() const { return z_; }
	float getW() const { return w_; }

	bool IsPoint() const;
	bool IsVector() const;

private:
	float x_, y_, z_, w_;
};

