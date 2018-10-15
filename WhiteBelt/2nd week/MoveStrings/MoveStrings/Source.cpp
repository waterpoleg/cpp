#include <iostream>
#include <string>
#include <vector>

using namespace std;

void MoveStrings(vector<string>& src, vector<string>& dest) {
	dest.insert(dest.end(), src.begin(), src.end());
	src.clear();
}

// from solution in the course 
void MoveStrings2(vector<string>& source, vector<string>& destination) {
	for (auto w : source) {
		destination.push_back(w);
	}
	source.clear();
}

int main() {
	vector<string> src = {"a", "b", "c"};
	vector<string> dest = {"z"};
	MoveStrings(src, dest);
 	return 0;
}