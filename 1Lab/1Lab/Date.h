#pragma once
#include<string>
#include<iostream>

using namespace std;

class Date {
private:

	int day;
	int month;
	int year;
	int dayResult;

public:
    
	Date(int date_day, int date_month, int date_year); 
	void getDayResult();										  
	void getWeekend();										  
};
