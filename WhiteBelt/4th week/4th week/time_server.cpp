#include <iostream>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer() 
{
	return "03:06:10";
}

class TimeServer 
{
	public:
		string GetCurrentTime() 
		{
			try 
			{
				LastFetchedTime = AskTimeServer();
				return LastFetchedTime;
			}
			catch (system_error) 
			{
				return LastFetchedTime;
			}
		}
	private:
		string LastFetchedTime = "00:00:00";
};

// yandex solution below

#include <exception>
#include <string>

using namespace std;

class TimeServer {
public:
	string GetCurrentTime() {
		// �������� ����� ������� AskTimeServer � try-catch ����
		try {
			last_fetched_time = AskTimeServer();
		}
		catch (const system_error&) {  // ����� ������ system_error
		}
		// ���������� �������� ���� � ���� ����������, ���� ���
		return last_fetched_time;
	}

private:
	string last_fetched_time = "00:00:00";
};
