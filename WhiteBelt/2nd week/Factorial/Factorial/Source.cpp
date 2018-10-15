#include <iostream>

using namespace std;

int Factorial(int n) {
	int res = 1;
	if (n < 0) {
		return 1;
	}
	else {
		for (int i = 1; i <= n; i++) {
			res *= i;
		}
	}
	return res;
}

//Идеальное и лаконичное решение:
int Factorial2(int x) {
	if (x <= 1) {
		return 1;
	}
	else {
		return x * Factorial2(x - 1);  // вычисляем факториал от x-1 и умножаем на x
	}
}

int main() {
	int n;
	cin >> n;
	cout << Factorial(n) << endl;
	return 0;
}

