#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int q;
	cin >> q;
	vector<int> days = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; 
	vector<vector<string>> task_for_day;
	int month = 0;
	task_for_day.resize(days[month], {});
	for (int i = 1; q >= i; i++) {
		string cmd;
		int day;
		string task;
		cin >> cmd;
		if (cmd == "ADD") { 
			cin >> day >> task; 
			task_for_day[day - 1].push_back(task); 
		}
		else if (cmd == "NEXT") { 
			month++;
			if (month > 11) { 
				month = 0;
			}
			vector<vector<string>> v = task_for_day;
			int x = task_for_day.size(); 
			int y = days[month]; 
			task_for_day.resize(y);
			int z = y - 1;
			if (x > y) {
				for (y; x > y; y++) {
					task_for_day[z].insert(end(task_for_day[z]), begin(v[y]), end(v[y]));
				}
			}
			v.clear();
		}
		else if (cmd == "DUMP") {
			cin >> day;
			cout << task_for_day[day - 1].size();
			for (auto i : task_for_day[day - 1]) {
				cout << " " << i;
			}
			cout << endl;
		}
	}
	return 0;
}


#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ���������� (��������� �� ���� ���������) ���������
// ����� ������� �������� ����������_�������
const vector<int> MONTH_LENGTHS =
{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int MONTH_COUNT = MONTH_LENGTHS.size();

int main() {
	int q;
	cin >> q;

	// ����� �������� ������ (�� 0 �� 11)
	int month = 0;

	// ������� ������ ������ ����� �����, ������ ���������� ���� � ������ ������;
	// ��� ���������� ������� �� ��������� �����, ������ ��� ��� ���������� ���
	vector<vector<string>> days_concerns(MONTH_LENGTHS[month]);

	for (int i = 0; i < q; ++i) {
		string operation_code;
		cin >> operation_code;

		if (operation_code == "ADD") {

			int day;
			string concern;
			cin >> day >> concern;
			--day;  // �������� ������� ���������� � ����
			days_concerns[day].push_back(concern);

		}
		else if (operation_code == "NEXT") {

			// ����� ��������� � ���������� ������ �������� ����� �����������
			// ��������� ��� ���������� �����������, ������ ��� ������ � �� ���������
			const int old_month_length = MONTH_LENGTHS[month];

			// ����� ������ ������ ����������� �� 1, �� ����� ������� ��� ������:
			// ��������, (5 + 1) % 12 = 6, �� (11 + 1) % 12 = 0
			month = (month + 1) % MONTH_COUNT;

			const int new_month_length = MONTH_LENGTHS[month];

			// ���� ����� ����� ������ �����������, ���������� ������� resize;
			// ����� ����� resize ���� ����������� ���� � �������� ��������� ����
			if (new_month_length < old_month_length) {

				// ����� ����������� ��������� ����� ���� � ��������� ���� ������ ������
				// ����� �� ������ ��������� ��� days_concerns[new_month_length - 1],
				// �������� ������ � ����� �������� ��������� ��� ����� �������
				vector<string>& last_day_concerns = days_concerns[new_month_length - 1];

				// ���������� ��� ������� ��� � ����� ������
				for (int day = new_month_length; day < old_month_length; ++day) {
					// �������� ������ days_concerns[day]
					// � ����� ������� last_day_concerns
					last_day_concerns.insert(
						end(last_day_concerns),
						begin(days_concerns[day]), end(days_concerns[day]));
				}
			}
			days_concerns.resize(new_month_length);

		}
		else if (operation_code == "DUMP") {

			int day;
			cin >> day;
			--day;

			// ������� ������ ��� � ���������� ���� � ������ �������
			cout << days_concerns[day].size() << " ";
			for (const string& concern : days_concerns[day]) {
				cout << concern << " ";
			}
			cout << endl;

		}
	}

	return 0;
}