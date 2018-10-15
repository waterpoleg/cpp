#include <vector>
#include <algorithm>

using namespace std;

void Reverse(vector<int>& v) {
	reverse(v.begin(), v.end());
}

//form solution
void Reverse(vector<int>& v) {
	int n = v.size();  // ��� �������� �������� ������ ������� � ���������� n
	for (int i = 0; i < n / 2; ++i) {
		// ������� � �������� i ����������� �������� � �������� n - 1 - i
		// �������� �� ������� � ������� ��������� ���������� tmp
		int tmp = v[i];
		v[i] = v[n - 1 - i];
		v[n - 1 - i] = tmp;
	}
}

int main() {
	vector<int> numbers = { 1, 5, 3, 4, 2 };
	Reverse(numbers);
	return 0;
}