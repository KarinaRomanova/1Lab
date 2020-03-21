#include <iostream> 
#include "Date.h"
#include "DT.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int day;
	int month;
	int year;
	cout << "Введите дату\n";
	cout << "Год\n";  cin >> year;
	cout << "Месяц\n";  cin >> month;
	cout << "День\n";  cin >> day;

	DateTime dt;
	bool isDateCorrect = dt.checkDate(year, month, day);
		if (!isDateCorrect) {
		cout << "Дата не верна!" << endl;
		exit(1);
		}

	Date firstDate(day, month, year);
	firstDate.getDayResult();
	firstDate.getWeekend();
	return 0;
}