#include <string>
#include <map>
#include <vector>

using namespace std;

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		first_names[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		last_names[year] = last_name;
	}
	string GetFullName(int year) {
		// �������� ��� � ������� �� ��������� �� ��� year
		const string first_name = FindNameByYear(first_names, year);
		const string last_name = FindNameByYear(last_names, year);

		// ���� � ���, � ������� ����������
		if (first_name.empty() && last_name.empty()) {
			return "Incognito";

			// ���� ���������� ������ ���
		}
		else if (first_name.empty()) {
			return last_name + " with unknown first name";

			// ���� ���������� ������ �������
		}
		else if (last_name.empty()) {
			return first_name + " with unknown last name";

			// ���� �������� � ���, � �������
		}
		else {
			return first_name + " " + last_name;
		}
	}
	string GetFullNameWithHistory(int year) {
		auto f_names = GetNames(first_names, year);
		auto l_names = GetNames(last_names, year);

		if (!f_names.size() && !l_names.size())
		{
			return "Incognito";
		}
		else if (!f_names.size() && l_names.size())
		{
			return GetName(l_names) + " with unknown first name";
		}
		else if (f_names.size() && !l_names.size())
		{
			return GetName(f_names) + " with unknown last name";
		}
		else if (f_names.size() && l_names.size())
		{
			return GetName(f_names) + " " + GetName(l_names);
		}
	}

private:
	map<int, string> first_names;
	map<int, string> last_names;

	// ���� ��� ����������, ���������� ������ ������
	string FindNameByYear(const map<int, string>& names, int year) {
		string name;  // ���������� ��� ����������

					  // ���������� ��� ������� �� ����������� ����� �������, �� ���� � ��������������� �������
		for (const auto& item : names) {
			// ���� ��������� ��� �� ������ �������, ��������� ���
			if (item.first <= year) {
				name = item.second;
			}
			else {
				// ����� ���� ������������, ��� ��� ��� ������ � ��� ����������� ��������� � ��������
				break;
			}
		}

		return name;
	}

	vector<string> GetNames(const map<int, string>& m, int year)
	{
		vector<string> names;

		string prev;
		for (auto iter = m.rbegin(); iter != m.rend(); ++iter) {
			if (iter->first > year) {
				continue;
			}

			if (iter->second != prev) {
				prev = iter->second;
				names.push_back(prev);
			}
		}

		return names;
	}

	string GetName(const vector<string>& names)
	{
		string result = names[0];
		string prev = names[0];

		string s;
		for (int i = 1; i < names.size(); ++i)
		{
			if (prev != names[i])
			{
				if (!s.empty())
				{
					s += ", ";
				}
				prev = names[i];
				s += names[i];
			}
		}

		if (!s.empty())
		{
			result = result + " (" + s + ")";
		}

		return result;
	}
};