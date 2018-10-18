#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void buses_for_stop(map<string, vector<string>>& stops, const string& stop) {
	if (!stops.count(stop)) {
		cout << "No stop" << endl;
	}
	else {
		for (const auto& bus : stops[stop]) {
			cout << bus << " ";
		}
		cout << endl;
	}
}

void stops_for_bus(map<string, vector<string>>& buses, map<string, vector<string>>& stops, const string& bus) {
	if (!buses.count(bus)) {
		cout << "No bus" << endl;
	}
	else {
		for (const auto& stop : buses[bus]) {
			cout << "Stop " << stop << ":";
			if (stops[stop].size() == 1) {
				cout << " no interchange" << endl;
			}
			else {
				for (auto bus_name : stops[stop]) {
					if (bus_name != bus) {
						cout << " " << bus_name;
					}
				}
				cout << endl;
			}
		}
	}
}

int main() {
	int q;
	cin >> q;

	map <string, vector<string>> buses;
	map <string, vector<string>> stops;

	for (int i = 0; i < q; i++) {
		string cmd;
		cin >> cmd;
		if (cmd == "NEW_BUS") {
			string bus;
			int stop_count;
			cin >> bus >> stop_count;

			string stop_name;
			for (int j = 0; j< stop_count; j++) {
				cin >> stop_name;
				buses[bus].push_back(stop_name);
				stops[stop_name].push_back(bus);
			}
		}
		else if (cmd == "BUSES_FOR_STOP") {
			string stop;
			cin >> stop;
			buses_for_stop(stops, stop);
		}
		else if (cmd == "STOPS_FOR_BUS") {
			string bus;
			cin >> bus;
			stops_for_bus(buses, stops, bus);
		}
		else if (cmd == "ALL_BUSES") {
			if (buses.empty()) {
				cout << "No buses" << endl;
			}
			else {
				for (const auto& b : buses) {
					cout << "Bus " << b.first << ":";
					for (const auto& s : b.second) {
						cout << " " << s;
					}
					cout << endl;
				}
			}
		}
	}
	return 0;
}