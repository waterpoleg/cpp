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
		// поместим вызов функции AskTimeServer в try-catch блок
		try {
			last_fetched_time = AskTimeServer();
		}
		catch (const system_error&) {  // ловим только system_error
		}
		// возвращаем значение пол€ Ч либо обновлЄнное, либо нет
		return last_fetched_time;
	}

private:
	string last_fetched_time = "00:00:00";
};
