#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
	map<vector<string>, int> routes;
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++) {
		int stops_number;
		cin >> stops_number;
		vector<string> stops(stops_number);
		for (string& s : stops) { 
				cin >> s; 
		}
		if (!routes.count(stops)) {
			int old_size = routes.size();
			routes[stops] = old_size + 1;
			cout << "New bus " << routes[stops] << endl;
		}
		else {
			cout << "Already exists for " << routes[stops] << endl;
		}
	}
	return 0;
}

/*
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
	int q;
	cin >> q;

	map<vector<string>, int> buses;

	for (int i = 0; i < q; ++i) {
		int n;
		cin >> n;
		vector<string> stops(n);
		for (string& stop : stops) {
			cin >> stop;
		}

		// проверяем, не существует ли уже маршрут с таким набором остановок
		if (buses.count(stops) == 0) {

			// если не существует, нужно сохранить новый маршрут;
			// его номер на единицу больше текущего количества маршрутов
			const int new_number = buses.size() + 1;
			buses[stops] = new_number;
			cout << "New bus " << new_number << endl;

		}
		else {
			cout << "Already exists for " << buses[stops] << endl;
		}
	}

	return 0;
}
*/