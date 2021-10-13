// HugeInt.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include <cctype>
using std::isdigit;

#include <cstring>
using std::strlen;

#include "HugeInt.h"

// Конструктор по умолчанию и конструктор
// для преобразования long int в наш объект HugeInt
HugeInt::HugeInt(long value) {
	// заполняем разряды нулями
	for (int i = 0; i <= NUM_DIGITS; i++)
		digits[i] = 0;
	// заполняем массив цифрами из value:
	for (int j = NUM_DIGITS; value != 0 && j >= 0; j--) {
		digits[j] = value % 10;
		value /= 10;
	}
}

// Конструктор, преобразующий строку в HugeInt
HugeInt::HugeInt(const char* string) {
	for (int i = 0; i <= NUM_DIGITS; i++)
		digits[i] = 0;

	int length = strlen(string);

	for (int j = NUM_DIGITS - length, k = 0; j <= NUM_DIGITS; j++, k++)
		if (isdigit(string[k]))
			digits[j] = string[k] - '0';
}

// сложение двух HugeInt
HugeInt HugeInt::operator+(const HugeInt& op2) const {
	HugeInt tmp;
	int carry = 0;
	for (int i = NUM_DIGITS; i >= 0; i--) {
		tmp.digits[i] = digits[i] + op2.digits[i] + carry;

		// нужен ли перенос разряда
		if (tmp.digits[i] > 9) {
			tmp.digits[i] %= 10;
			carry = 1;
		}
		else
			carry = 0;
	}
	return tmp;
}

// сложение HugeInt + int

HugeInt HugeInt::operator+(int op2) const {
	// здесь в будущем можно будет использовать перегруженное сложение и преобразование long в hugeint,
	// а пока пусть будет так
	// выглядит как бред, но иначе я не понимаю первый пункт задания
	HugeInt tmp;
	int carry = 0;
	for (int j = NUM_DIGITS; op2 != 0 && j >= 0; j--) {
		tmp.digits[j] = digits[j] + op2%10 + carry;
		op2 /= 10;
		// кэррифлаг сющий да?
		if (tmp.digits[j] > 9) {
			tmp.digits[j] %= 10;
			carry = 1;
		}
		else
			carry = 0;
	}
	return tmp;
}

// Сложение HugeInt + строка



