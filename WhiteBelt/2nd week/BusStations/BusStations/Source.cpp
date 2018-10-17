#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main() {
	int q;
	cin >> q;

	map<string, vector<string>> routes;
	map<string, vector<string>> buses;

	for (int i = 1; i < q; i++) {
		string cmd;
		cin >> cmd;

		if (cmd == "NEW_BUS") {
			string bus;
			int stops_number;
			cin >> bus >> stops_number;
			for (int s = 1; s <= stops_number; s++) {
				string stop_n = "";
				cin >> stop_n;
				routes[bus].push_back(stop_n);
				buses[stop_n].push_back(bus);
			}

		}
		else if (cmd == "BUSES_FOR_STOP") {

		}
		else if (cmd == "STOPS_FOR_BUS") {
			string bus;
			cin >> bus;

			if (!routes.count(bus)) {
				cout << "No bus" << endl;
			}
			else {

			}
		}
		else if (cmd == "ALL_BUSES") {
			if (routes.size() == 0) {
				cout << "No buses" << endl;
			}
			else {
				for (const auto& r : routes) {
					cout << "Bus " << r.first << ":";
					for (const auto& rs : r.second) {
						cout << " " << rs;;
					}
					cout << endl;
				}
			}
		}
	}

	return 0;
}