#ifndef POLINOM_H
#define POLINOM_H

#include "tsinglylist.h"
#include "monom.h"
#include <string>
#include <sstream>

using namespace std;

class Polinom
{
private:
    TSinglyList<Monom> monoms; // cписок мономов полинома

    
public:
    Polinom() = default; // конструктор по умолчанию
    Polinom(const string& str); // конструктор преобразования типа

    void simplify();
    string toString() const;
    Polinom& operator=(const Polinom& other);
    Polinom operator+(const Polinom& other) const;
    Polinom operator-(const Polinom& other) const;
    Polinom operator*(double scalar) const;
    Polinom derivativeX() const;
};

#endif

