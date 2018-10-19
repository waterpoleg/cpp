set<string> BuildMapValuesSet(const map<int, string>& m) {
	set<string> result;
	for (const auto& s : m) { 
		result.insert(s.second); 
	}
	return result;
}