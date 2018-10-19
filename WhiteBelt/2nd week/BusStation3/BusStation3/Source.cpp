#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main() 
{
	int q;
	cin >> q;
	
	map<set<string>, int> routes;
	
	for (int i = 1; i <= q; i++)
	{
		int n;
		cin >> n;

		set<string> stops;

		for (int j = 1; j <= n; j++)
		{
			string stop;
			cin >> stop;
			stops.insert(stop);
		}
		if (routes.count(stops))
		{
			cout << "Already exists for " << routes[stops] << endl;
		}
		else
		{
			int old_sise = routes.size();
			routes[stops] = old_sise + 1;
			cout << "New bus " << routes[stops] << endl;
		}
	}
	return 0;
}

/*

#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main() {
	int q;
	cin >> q;

	map<set<string>, int> buses;

	for (int i = 0; i < q; ++i) {
		int n;
		cin >> n;
		set<string> stops;
		for (int j = 0; j < n; ++j) {
			string stop;
			cin >> stop;
			stops.insert(stop);
		}
		if (buses.count(stops) == 0) {
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