#pragma once

#ifndef HUGEINT_H
#define HUGEINT_H
#include <iostream>

#define NUM_DIGITS 47
using std::ostream;

class HugeInt
{
	friend ostream& operator<< (ostream&, const HugeInt&);
public:
	HugeInt(long = 0); //конструктор преобразования/конструктор по умолчанию
	HugeInt(const char*); // конструктор преобразования

	//сложение HugeInt + HugeInt
	HugeInt operator+(const HugeInt&) const;

	//сложение HugeInt + int
	HugeInt operator+(int) const;
	//сложение HugeInt + строка
	HugeInt operator+(const char*) const;

private:
	short digits[30];
};

#endif // !HUGEINT_H

