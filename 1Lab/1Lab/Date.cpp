#include "Date.h"

	Date::Date(int date_day, int date_month, int date_year) 
		:day(date_day), month(date_month),year(date_year)
	{
		int a;
		int yearcalc;
		int monthcalc;
		a = (14 - month) / 12;
		yearcalc = year - a;
		monthcalc = month + (12 * a) - 2;
		dayResult = (day + (31 * monthcalc) / 12 + yearcalc + yearcalc / 4 - yearcalc / 100 + yearcalc / 400) % 7;
	}
		
	void Date::getDayResult()										
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
	
	void Date::getWeekend()										  
	{
		if (dayResult == 6 || dayResult == 7)
		{
			cout << "Weekend\n";
		}
		if (day == 31 && month == 12)
		{
			cout << "Weekend\n";
		}
		if (day == 8 && month == 3)
		{
			cout << "Weekend\n";
		}
		if (day == 23 && month == 2) {
			cout << "Weekend\n";
		}
		if (day == 9 && month == 5) {
			cout << "Weekend\n";
		}
		if (day == 1 && month == 5) {
			cout << "Weekend\n";
		}
	}
