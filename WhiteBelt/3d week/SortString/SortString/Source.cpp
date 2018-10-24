#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

std::string ToLower(string s) {
	for (auto& c : s) {
		c = tolower(c);
	}
	return s;
}

int main() {
	int n;
	cin >> n;
	vector<std::string> v(n);
	for (auto& el : v) {
		std::cin >> el;
	}
	
	sort(begin(v), end(v), [](std::string x, std::string y) {return ToLower(x) < ToLower(y); });
	
	for (const auto& el : v) {
		cout << el << ' ';
	}
	
	return 0;
}

/*

// �������� ������������� ����� ������� ���� ������ � ����������� �������, ������������ ��� ������ ��� ����� ��������.

// ��� ����� �������, ��������, � ������� ������� lexicographical_compare, ������������ ��� ��������� ��������� 
// (� ����� ������ � ��� ������ ��������) � ������� ������� �����������. � ����������� ��� ������� lexicographical_compare 
// �� ���������� ������� tolower, ������������ ������, ���������� � ������� ��������.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// ��������� ������ �����
	int n;
	cin >> n;
	vector<string> v(n);
	for (string& s : v) {
		cin >> s;
	}

	// ���������
	sort(begin(v), end(v),
		// ���������� ��� ���������� � ������-�������, ������������ ������ ��� ����� ��������
		[](const string& l, const string& r) {
		// ���������� �����������������...
		return lexicographical_compare(
			// ... ��� ������� ������ l ...
			begin(l), end(l),
			// ... �� ����� ��������� ������ r ...
			begin(r), end(r),
			// ..., ��������� � �������� ����������� ��������� ��������� �������� ��� ����� ��������
			[](char cl, char cr) { return tolower(cl) < tolower(cr); }
		);
	}
	);

	// ������� ��������������� ������
	for (const string& s : v) {
		cout << s << ' ';
	}

	return 0;
}

*/