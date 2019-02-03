using namespace std;

class Rational {
public:
	Rational() {
		numerator = 0;
		denominator = 1;
	}

	Rational(int new_numerator, int new_denominator) {
		numerator = new_numerator;
		denominator = new_denominator;
		GetRational(numerator, denominator);
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

	void GetRational(int& numerator, int& denominator) {
		int gcd = GCD(abs(numerator), abs(denominator));
		numerator /= gcd;
		denominator /= gcd;

		if (denominator < 0) {
			denominator = -denominator;
			numerator = -numerator;
		}
	}

	int GCD(int a, int b) {
		return b ? GCD(b, a % b) : a;
	}
};

