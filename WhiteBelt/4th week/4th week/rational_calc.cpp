#include <iostream>

using namespace std;

// ���� �� �������� ���������� ����������� ������ �������� (���) � �����������:
// ������ ����� ������� ����� �������� ���� ��, �� � ������� �����������
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
	Rational() {  // ����� �� ��������� � 0/1
		numerator = 0;
		denominator = 1;
	}
	Rational(int new_numerator, int new_denominator) {
		if (new_denominator == 0) throw  invalid_argument("denominator is zero");
		const int gcd = GreatestCommonDivisor(new_numerator, new_denominator);
		// �������� �����, �������� ��������� � ����������� �� �� ���
		numerator = new_numerator / gcd;
		denominator = new_denominator / gcd;
		// ����������� ������ ���� �������������
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

// ��������� ����� ���������, ���������� �������� ��������� � �����������
bool operator == (const Rational& lhs, const Rational& rhs) {
	return lhs.Numerator() == rhs.Numerator() &&
		lhs.Denominator() == rhs.Denominator();
}

// ���������� ������� ������� �������� ������, ���������� �� ���������� ��������� � ������ �����������
Rational operator + (const Rational& lhs, const Rational& rhs) {
	return {
		lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
		lhs.Denominator() * rhs.Denominator()
	};
}

// ��������� ��������� ���������� ��������
// ������������ ���� ����� ���� ��������, ��������� ��� ������ Rational �������� �������� ������: ����� �������� lhs � rhs ����� ���� �� ���������           ��� lhs + (-rhs)
Rational operator - (const Rational& lhs, const Rational& rhs) {
	return {
		lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
		lhs.Denominator() * rhs.Denominator()
	};
}

Rational operator * (const Rational& lhs, const Rational& rhs) {
	return {
		lhs.Numerator() * rhs.Numerator(),
		lhs.Denominator() * rhs.Denominator()
	};
}

// ������� ����������� ��������� �� �������� (�������������) �����
Rational operator / (const Rational& lhs, const Rational& rhs) {
	if (rhs.Numerator() == 0) {
		throw domain_error("division by zero");
	}
	return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

istream& operator >> (istream& is, Rational& r) {
	int n, d;
	char c;
	is >> n >> c >> d;
	if (is && c == '/') {
		r = Rational(n, d);
	}
	return is;
}

ostream& operator << (ostream& os, const Rational& r) {
	return os << r.Numerator() << '/' << r.Denominator();
}

// ����� �������� lhs � rhs, ������� �� �������� � ����, ��� ����������� ��������� � ���� ���������
bool operator < (const Rational& lhs, const Rational& rhs) {
	return (lhs - rhs).Numerator() < 0;
}

int main() 
{
	Rational d_1, d_2;
	char o;
	
	try 
	{
		cin >> d_1 >> o >> d_2;
	} 
	catch (invalid_argument&) 
	{
		cout << "Invalid argument" << endl;
		return 0;
	}

	switch (o)
	{
	case '+':
		cout << d_1 + d_2 << endl;
		break;
	case '-':
		cout << d_1 - d_2 << endl;
		break;
	case '*':
		cout << d_1 * d_2 << endl;
		break;
	case '/':
		try
		{
			cout << d_1 / d_2;
		} 
		catch (domain_error&)
		{
			cout << "Division by zero" << endl;
		}
		break;
	}

	return 0;
}