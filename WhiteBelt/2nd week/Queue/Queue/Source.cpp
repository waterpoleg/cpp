#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int q, op, wc = 0;
	string cmd;
	vector<int> people, wp;

	cin >> q;
		
	for (int i = 1; i <= q; i++) {
		cin >> cmd;
		if (cmd == "WORRY") {
			cin >> op;
			if (people[op] == 0) {
				people[op] = 1;
				wc++;
			}
		}
		else if (cmd == "QUIET") {
			cin >> op;
			people[op] = 0;
			wc--;
		}
		else if (cmd == "COME") {
			cin >> op;
			if (op < 0) {
				int len = people.size();
				for (int y = 1; y <= abs(op); y++) {
					if (people[len - y] == 1) {
						wc--;
					}
					people.pop_back();
				}
			}
			else {
				for (int x = 1; x <= op; x++) {
					people.push_back(0);
				}
			}
		}
		else if (cmd == "WORRY_COUNT") {
			wp.push_back(wc);
		}
	}
	for (int i = 0; i < wp.size(); i++) {
		cout << wp[i] << endl;
	}
	return 0;
}
/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int q;
	cin >> q;
	vector<bool> is_nervous;

	for (int i = 0; i < q; ++i) {
		string operation_code;
		cin >> operation_code;

		if (operation_code == "WORRY_COUNT") {

			// подсчитываем количество элементов в векторе is_nervous, равных true
			cout << count(begin(is_nervous), end(is_nervous), true) << endl;

		}
		else {
			if (operation_code == "WORRY" || operation_code == "QUIET") {

				int person_index;
				cin >> person_index;

				// выражение в скобках имеет тип bool и равно true для запроса WORRY,
				// поэтому is_nervous[person_index] станет равным false или true
				// в зависимости от operation_code
				is_nervous[person_index] = (operation_code == "WORRY");

			}
			else if (operation_code == "COME") {

				int person_count;
				cin >> person_count;

				// метод resize может как уменьшать размер вектора, так и увеличивать,
				// поэтому специально рассматривать случаи с положительным
				// и отрицательным person_count не нужно
				is_nervous.resize(is_nervous.size() + person_count, false);

			}
		}
	}

	return 0;
}*/