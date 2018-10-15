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

//��������� � ���������� �������:
int Factorial2(int x) {
	if (x <= 1) {
		return 1;
	}
	else {
		return x * Factorial2(x - 1);  // ��������� ��������� �� x-1 � �������� �� x
	}
}

int main() {
	int n;
	cin >> n;
	cout << Factorial(n) << endl;
	return 0;
}

