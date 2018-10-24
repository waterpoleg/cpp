#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);

	for (auto& i : v)
	{
		cin >> i;
	}

	sort(begin(v), end(v), [](int i, int j) {return abs(i) < abs(j); });

	for (const auto& s : v)
	{
		cout << s << " ";
	}
	return 0;
}


/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

	// ��������� ������
	int n;
	cin >> n;
	vector<int> v(n);
	for (int& x : v) {
		cin >> x;
	}

	// ���������
	sort(begin(v), end(v),
		// �������, ������������ abs(l) � abs(r) � ������ ����� l � r
		[](int l, int r) {
		return abs(l) < abs(r);
	}
	);

	// ������� �������������� ������
	for (int x : v) {
		cout << x << " ";
	}

	return 0;
}
*/