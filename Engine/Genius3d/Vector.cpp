

#include "Vector.h"

NAMESPACEBEGIN(Genius)

Vector::Vector()
{
	x = y = z = 0.0f;
}

Vector::Vector(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector::Vector(const Vector& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}

Vector::~Vector()
{

}

void Vector::Normalize()
{
	float fFactor = 1.0f / Length();
	x *= fFactor;
	y *= fFactor;
	z *= fFactor;
}

float Vector::Length()
{
	return sqrtf(x * x + y * y + z * z);
}

float Vector::Dot(const Vector& vec) const
{
	return x * vec.x + y * vec.y + z * vec.z;
}

Vector Vector::Cross(const Vector& rkVector) const
{
	return Vector(
		y * rkVector.z - z * rkVector.y,
		z * rkVector.x - x * rkVector.z,
		x * rkVector.y - y * rkVector.x);
}

Vector& Vector::operator -()
{
	x = -x;
	y = -y;
	z = -z;
	return *this;
}

Vector Vector::operator + (const Vector &v) const
{
	Vector r(x + v.x, y + v.y, z + v.z);
	return r;
}

Vector Vector::operator - (const Vector &v) const
{
	Vector r(x - v.x, y - v.y, z - v.z);
	return r;
}

Vector& Vector::operator = (const Vector &v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

Vector& Vector::operator += (const Vector &v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

Vector& Vector::operator -= (const Vector &v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

Vector Vector::operator * (float d) const
{
	Vector r(x * d, y * d, z * d);
	return r;
}

Vector Vector::operator / (float m) const
{
	return Vector(x / m, y / m, z / m);
}


NAMESPACEEND