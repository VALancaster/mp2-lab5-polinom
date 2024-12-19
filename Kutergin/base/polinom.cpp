#include "polinom.h"

void Polinom::simplify()
{
	if (monoms.IsEmpty())
		return;

	for (size_t i = 0; i < monoms.size(); ++i)
	{
		Monom& current = monoms[i];
		for (size_t j = i + 1; j < monoms.size(); )
		{
			Monom& next = monoms[j];
			// Проверяем, одинаковые ли степени переменных у мономов
			if (current.getX() == next.getX() &&
				current.getY() == next.getY() &&
				current.getZ() == next.getZ())
			{
				// Складываем коэффициенты одинаковых мономов
				current.setCoef(current.getCoef() + next.getCoef());
				// Удаляем текущий моном, а не следующий, потому что следующий будет сдвигаться
				monoms.EraseAfter(j - 1);
			}
			else {
				++j;
			}
		}
	}

	// Убираем все мономы с нулевыми коэффициентами
	for (size_t i = 0; i < monoms.size(); ++i)
	{
		if (monoms[i].getCoef() == 0)
		{
			monoms.EraseAfter(i - 1);
			--i; // после удаления элемента надо уменьшить индекс, чтобы не пропустить следующий
		}
	}
}


Polinom::Polinom(const string& str)
{
	stringstream ss(str);
	char sign = '+'; // по умолчанию знак плюс
	double coef = 0.0;
	int x = 0, y = 0, z = 0;

	size_t pos = 0;
	while (pos < str.size())
	{
		if (str[pos] == '+' || str[pos] == '-') // чтение знака
		{
			sign = str[pos];
			pos++;
		}

		// сброс значений для нового монома
		x = y = z = 0;
		coef = 0.0; 
		// чтение коэффициента с учетом дробной части 
		size_t coef_start = pos;
		while ((isdigit(str[pos]) || str[pos] == '.') && pos < str.size()) // чтение коэффициента
		{
			// coef = coef * 10 + (str[pos] - '0');
			pos++;
		}
		coef = std::stod(str.substr(coef_start, pos - coef_start));
		if (sign == '-')
			coef = -coef;

		// чтение степеней x, y, z
		if (str[pos] == 'x')
		{
			++pos; // пропускаем 'x'
			x = str[pos] - '0';
			pos++;
		}
		if (str[pos] == 'y')
		{
			++pos; // пропускаем 'y'
			y = str[pos] - '0';
			pos++;
		}
		if (str[pos] == 'z')
		{
			++pos; // пропускаем 'z'
			z = str[pos] - '0';
			pos++;
		}

		Monom m(coef, x, y, z);
		monoms.PushFront(m);
		x = y = z = 0;
	}
	simplify();
}

string Polinom::toString() const
{
	ostringstream os;
	for (size_t i = 0; i < monoms.size(); ++i)
	{
		const Monom& m = monoms[i];
		os << (m.getCoef() >= 0 ? " + " : " - ")
			<< abs(m.getCoef())
			<< "x^" << m.getX()
			<< "y^" << m.getY()
			<< "z^" << m.getZ();
	}
	string result = os.str();
	return result.empty() ? "0" : result;
}

Polinom& Polinom::operator=(const Polinom& other)
{
	if (this != &other)
	{
		monoms.Clear();  // очищаем текущий список
		for (size_t i = 0; i < other.monoms.size(); ++i)
		{
			monoms.PushFront(other.monoms[i]); // копируем все мономы из другого полинома
		}
	}
	return *this;
}

Polinom Polinom::operator+(const Polinom& other) const
{
	Polinom result;
	for (size_t i = 0; i < monoms.size(); ++i)
		result.monoms.PushFront(monoms[i]);
	for (size_t i = 0; i < other.monoms.size(); ++i)
		result.monoms.PushFront(other.monoms[i]);
	result.simplify();
	return result;
}

Polinom Polinom::operator-(const Polinom& other) const
{
	Polinom result = *this; // в новом полиноме находится текущий полином
	for (size_t i = 0; i < other.monoms.size(); ++i) // постепенно вычитаем второй полином
	{
		Monom current = other.monoms[i];
		current.setCoef(-current.getCoef()); // инвертируем знак 
		result.monoms.PushFront(current); 
	}
	result.simplify();
	return result;
}

Polinom Polinom::operator*(double scalar) const
{
	Polinom result;
	for (size_t i = 0; i < monoms.size(); ++i)
	{
		Monom current = monoms[i];
		current.setCoef(current.getCoef() * scalar);
		result.monoms.PushFront(current);
	}
	result.simplify(); 
	return result;
}

Polinom Polinom::derivativeX() const
{
	Polinom result;
	for (size_t i = 0; i < monoms.size(); ++i)
	{
		Monom current = monoms[i];
		if (current.getX() > 0) // поскольку x,y,z принадлежат отрезку [0,...,9]
		{
			current.setCoef(current.getCoef() * current.getX());
			current.setX(current.getX() - 1);
			result.monoms.PushFront(current);
		} 
		else if (current.getX() == 0 && current.getCoef() != 0)
		{
			Monom zeromonom(0.0, 0, current.getY(), current.getZ());
			result.monoms.PushFront(zeromonom);
		}
	}
	result.simplify();
	return result;
}
