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
	cout << "������� ����\n";
	cout << "���\n";  cin >> year;
	cout << "�����\n";  cin >> month;
	cout << "����\n";  cin >> day;

	DateTime dt;
	bool isDateCorrect = dt.checkDate(year, month, day);
		if (!isDateCorrect) {
		cout << "���� �� �����!" << endl;
		exit(1);
		}

	Date firstDate(day, month, year);
	firstDate.getDayResult();
	firstDate.getWeekend();
	return 0;
}