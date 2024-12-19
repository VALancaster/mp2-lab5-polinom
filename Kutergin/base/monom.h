#ifndef MONOM_H
#define MONOM_H

#include<iostream>

class Monom
{
private:
	double coef; // коэффициент
	int x, y, z; // cтепени переменных
public:
	Monom(double coef2, int x2, int y2, int z2); // конструктор инициализатор
	Monom(const Monom& other); // конструктор копирования

	Monom& operator=(const Monom& other);

	double getCoef() const noexcept;
	int getX() const noexcept;
	int getY() const noexcept;
	int getZ() const noexcept;

	void setCoef(double c2);
	void setX(int x2);
	void setY(int y2);
	void setZ(int z2);

	bool operator==(const Monom& other) const;
	bool operator<(const Monom& other) const;
};

#endif
