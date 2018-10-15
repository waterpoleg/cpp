#include <iostream>
#include <string>
#include <vector>

using namespace std;

//используем функция из предыдущего задания
bool IsPalindrom(string s) {
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - i - 1]) {
			return false;
		}
	}
	return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
	vector<string> res;
	for (auto s : words) {
		if (IsPalindrom(s) && s.size() >= minLength) {
			res.push_back(s);
		}
	}
	return res;
}

int main() {
	int minLength;
	string s;
	vector<string> v;

	//длина
	cin >> minLength;

	//строки, конец ввода = ctrl+Z
	while (getline(cin, s)) {
		v.push_back(s);
	}
	
	for (auto p : PalindromFilter(v, minLength)) {
		cout << p << " ";
	}
	cout << endl;
	return 0;
}