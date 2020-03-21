#include <iostream>
using namespace std;

int DayResult(int date_day, int date_month, int date_year)
{
	int dayResult;
	int a;
	int yearcalc;
	int monthcalc;
	a = (14 - date_month) / 12;
	yearcalc = date_month - a;
	monthcalc = date_month + (12 * a) - 2;
	dayResult = (date_day + (31 * monthcalc) / 12 + yearcalc + yearcalc / 4 - yearcalc / 100 + yearcalc / 400) % 7;
	return dayResult;
}
void DayWeek(int dayResult)
{
	string dayString;
	switch (dayResult) {
	case 0:
		dayString = "Sunday";
		cout << dayString << endl;
		break;
	case 1:
		dayString = "Monday";
		cout << dayString << endl;
		break;
	case 2:
		dayString = "Tuesday";
		cout << dayString << endl;
		break;
	case 3:
		dayString = "Wednesday";
		cout << dayString << endl;
		break;
	case 4:
		dayString = "Thursday";
		cout << dayString << endl;
		break;
	case 5:
		dayString = "Friday";
		cout << dayString << endl;
		break;
	case 6:
		dayString = "Saturday";
		cout << dayString << endl;
		break;

	default:
		cout << "Error";
		break;
	
	}
}
void Weekend(int dayResult, int day, int month) {
	if (dayResult == 6 || dayResult == 7)
	{
		cout << "Выходной\n";
	}
	if (day == 31 && month == 12)
	{
		cout << "Выходной\n";
	}
	if (day == 8 && month == 3)
	{
		cout << "Выходной\n";
	}
	if (day == 23 && month == 2) {
		cout << "Выходной\n";
	}
	if (day == 9 && month == 5) {
		cout << "Выходной\n";
	}
	if (day == 1 && month == 5) {
		cout << "Выходной\n";
	}
}

bool checkRange(int value, int min, int max) {
	if (value < min)
		return false;
	if (value > max)
		return false;
	return true;
}

bool checkDate(int year, int mon, int day, bool isAddingDate = false) {
	switch (mon)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return checkRange(day, 1, 31);
	case 2:
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
			return checkRange(day, 1, 29);
		else
			return checkRange(day, 1, 28);
		// апрель, июнь, сентябрь и ноябрь
	case 4:
	case 6:
	case 9:
	case 11:
		return checkRange(day, 1, 30);

	default:
		if (isAddingDate && mon == 0)
			return true;
		//std::cout << "Month is incorrect" << std::endl;
		return false;
	}
}

bool checkDateTime(int year, int mon, int day, int hour, int min, int sec) {
	if (checkDate(year, mon, day) && (checkRange(hour, 0, 23)) && checkRange(min, 0, 59) && (checkRange(sec, 0, 59)))
	{
		return true;
	}
	else {
		return false;
	}
}






bool checkDateTime(int year, int mon, int day) {
	
	if (checkDate(year, mon, day, false))
	{
		return true;
	}
	else {
		return false;
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	int day;
	int month;
	int year;
	cout << "Введите дату\n";
	cout << "Год\n";  cin >> year;
	cout << "Месяц\n";  cin >> month;
	cout << "День\n";  cin >> day;

	if (checkDateTime(year, month, day, 0, 0, 0)) {
		cout << "Дата верна" << endl;
	}
	else {
		cout << "Дата не верна" << endl;
		return 0;
	}

	int dayResult = DayResult(day, month, year);
	DayWeek(dayResult);
	Weekend(dayResult, day, month);


	return 0;
}
