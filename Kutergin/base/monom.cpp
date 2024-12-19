#include "monom.h"
#include <stdexcept>

Monom::Monom(double coef2 = 0.0, int x2 = 0, int y2 = 0, int z2 = 0) :
	coef(coef2), x(x2), y(y2), z(z2)
{
	if (x2 < 0 || y2 < 0 || z2 < 0 || x2 > 9 || y2 > 9 || z2 > 9)
		throw std::invalid_argument("The degrees of the variables must be non-negative and less than 10");
}

Monom::Monom(const Monom& other) : 
	coef(other.coef), x(other.x), y(other.y), z(other.z) {}

Monom& Monom::operator=(const Monom& other)
{
	if (this != &other)
	{
		coef = other.coef;
		x = other.x;
		y = other.y;
		z = other.z;
	}
	return *this;
}

double Monom::getCoef() const noexcept
{
	return coef;
}

int Monom::getX() const noexcept
{
	return x;
}

int Monom::getY() const noexcept
{
	return y;
}

int Monom::getZ() const noexcept
{
	return z;
}

void Monom::setCoef(double c2)
{
	coef = c2;
}

void Monom::setX(int x2)
{
	x = x2;
}

void Monom::setY(int y2)
{
	y = y2;
}

void Monom::setZ(int z2)
{
	z = z2;
}

bool Monom::operator==(const Monom& other) const
{
	return x == other.x && y == other.y && z == other.z;
}

bool Monom::operator<(const Monom& other) const
{
	if (x != other.x)
		return x < other.x;
	if (y != other.y)
		return y < other.y;
	return z < other.z;
}