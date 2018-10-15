#include <iostream>
#include <vector>

using namespace std;

vector<int> Reversed(const vector<int>& v) {
	vector<int> res;
	for (int i = v.size() - 1; i >= 0; i--) {
		res.push_back(v[i]);
	}
	return res;
}

//from solution
vector<int> Reversed(const vector<int>& input) {
	auto seq = input;
	for (int i = 0; i < seq.size() / 2; ++i) {
		auto tmp = seq[i];
		seq[i] = seq[seq.size() - 1 - i];
		seq[seq.size() - 1 - i] = tmp;
	}
	return seq;
}

int main() {
	vector<int> numbers = { 1, 5, 3, 4, 2 };
	numbers = Reversed(numbers);
	for (auto i : numbers) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}