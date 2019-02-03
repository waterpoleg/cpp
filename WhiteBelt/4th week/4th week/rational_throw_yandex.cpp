#include <iostream>
#include <exception>

using namespace std;

int GreatestCommonDivisor(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return GreatestCommonDivisor(b, a % b);
	}
}

class Rational {
public:
	Rational() {
		numerator = 0;
		denominator = 1;
	}
	Rational(int new_numerator, int new_denominator) {
		if (new_denominator == 0) {
			// ������� ���������� � ������ �������� �����������
			throw invalid_argument("");
		}
		const int gcd = GreatestCommonDivisor(new_numerator, new_denominator);
		numerator = new_numerator / gcd;
		denominator = new_denominator / gcd;
		if (denominator < 0) {
			denominator = -denominator;
			numerator = -numerator;
		}
	}

	int Numerator() const {
		return numerator;
	}

	int Denominator() const {
		return denominator;
	}

private:
	int numerator;
	int denominator;
};

Rational operator * (const Rational& lhs, const Rational& rhs) {
	return {
		lhs.Numerator() * rhs.Numerator(),
		lhs.Denominator() * rhs.Denominator()
	};
}

Rational operator / (const Rational& lhs, const Rational& rhs) {
	// ��������� �������� �� 0 (��� ����������� �������� �� 0 ��� ���������)
	if (rhs.Numerator() == 0) {
		throw domain_error("");
	}
	return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}