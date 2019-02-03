#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>
#include <sstream>

using namespace std;

// Реализуйте функции и методы классов и при необходимости добавьте свои

class Date {
public:
	Date() {
		_year = 0;
		_month = 0;
		_day = 0;
	}
	Date(int year, int month, int day) {
		if (month > 12 || month < 1) {
			throw invalid_argument("Month value is invalid: " + to_string(month));
		}
		if (day > 31 || day < 1) {
			throw invalid_argument("Day value is invalid: " + to_string(day));
		}
		_year = year;
		_month = month;
		_day = day;
	}
	int GetYear() const {
		return _year;
	}
	int GetMonth() const {
		return _month;
	}
	int GetDay() const {
		return _day;
	}

private:
	int _year, _month, _day;
};

bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() == rhs.GetDay()) {
		if (lhs.GetMonth() == rhs.GetMonth()) {
			return lhs.GetDay() < rhs.GetDay();
		}
		return lhs.GetMonth() < rhs.GetMonth();
	}
	return lhs.GetYear() < rhs.GetYear();
}

std::ostream& operator<<(ostream& stream, const Date& date) {
	stream << setfill('0') 
		<< setw(4) << date.GetYear() << "-"
		<< setw(2) << date.GetMonth() << "-"
		<< setw(2) << date.GetDay();
	return stream;
}

class Database {
public:
	void AddEvent(const Date& date, const string& event) {
		if (!event.empty()) {
			events[date].insert(event);
		}
	}
	
	bool DeleteEvent(const Date& date, const string& event) {
		if (events.count(date) > 0 && events.at(date).count(event) > 0) {
			events.at(date).erase(event);
			if (events.at(date).size() == 0) {
				events.erase(date);
			}
			return true;
		}
		return false;
	}
	
	int  DeleteDate(const Date& date) {
		if (events.count(date) > 0) {
			int n = events.at(date).size();
			events.erase(date);
			return n;
		}
		return 0;
	}

	set<string> Find(const Date& date) const {
		if (events.count(date) > 0) {
			return events.at(date);
		}
		return {};
	}
  
	void Print() const {
		for (auto const& event : events) {
			for (auto const& e : event.second) {
				cout << event.first << " " << e << endl;
			}
		}
	}

private:
	map<Date, set<string>> events;
};

Date getDate(const string& date) {
	int year, month, day;
	stringstream in(date);
	in >> year;
	if (in.peek() != '-') {
		throw std::logic_error("Wrong date format: " + date);
	}
	in.ignore(1);
	in >> month;
	if (in.peek() != '-') {
		throw std::logic_error("Wrong date format: " + date);
	}
	in.ignore(1);
	in.peek();
	if (in.eof()) {
		throw std::logic_error("Wrong date format: " + date);
	}
	in >> day;
	if (!in.eof()) {
		throw std::logic_error("Wrong date format: " + date);
	}
	return Date(year, month, day);
}

int main() {
  Database db;
  try {
	  string command;
	  while (getline(cin, command)) {
		  // Считайте команды с потока ввода и обработайте каждую
		  stringstream stream(command);
		  string cmd;

		  stream >> cmd;

		  if (cmd == "Add") {
			  string date, event;
			  stream >> date >> event;
			  Date d = getDate(date);
			  db.AddEvent(d, event);
		  }
		  else if (cmd == "Del") {
			  string date;
			  stream >> date;
			  Date d = getDate(date);
			  if (stream.eof()) {
				  cout << "Deleted " << db.DeleteDate(d) << " events" << endl;
			  }
			  else {
				  string event;
				  stream >> event;
				  if (db.DeleteEvent(d, event)) {
					  cout << "Deleted successfully" << endl;
				  }
				  else {
					  cout << "Event not found" << endl;
				  }
			  }
		  }
		  else if (cmd == "Find") {
			  string date;
			  stream >> date;
			  Date d = getDate(date);
			  for (const auto& item : db.Find(d)) {
				  cout << item << endl;
			  }
		  }
		  else if (cmd == "Print") {
			  db.Print();
		  }
		  else if (cmd.empty()) {
			  continue;
		  }
		  else {
			  throw logic_error("Unknown command: " + cmd);
		  }
	  }
  }
  catch (exception& e) {
	  cout << e.what() << endl;
  }

  return 0;
}

