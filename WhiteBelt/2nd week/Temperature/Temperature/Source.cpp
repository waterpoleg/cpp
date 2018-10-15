#include <iostream>
#include <vector>
using namespace std;

void VectorPrint(const vector<int>& v) {
	for (auto i : v) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	int t, d, sum = 0;
	vector<int> v, k;

	cin >> t;
		
	for (int i = 0; i < t; i++) {
		cin >> d;
		v.push_back(d);
		sum += d;
	}

	sum = sum / v.size();

	for (int i = 0; i <= v.size() - 1; i++) {
		if (v[i] > sum) {
			k.push_back(i);
		}
	}

	cout << k.size() << endl;
	VectorPrint(k);

	return 0;
}

/* solution from yandex
int main() {
	int n;
	cin >> n;
	vector<int> temperatures(n);
	int sum = 0;
	
	for (int& temperature : temperatures) {
		cin >> temperature;
		sum += temperature;
	}

	int average = sum / n;
	vector<int> result_indices;
	for (int i = 0; i < n; ++i) {
		if (temperatures[i] > average) {
			result_indices.push_back(i);
		}
	}

	cout << result_indices.size() << endl;
	for (int result_index : result_indices) {
		cout << result_index << " ";
	}
	cout << endl;

	return 0;
}
*/