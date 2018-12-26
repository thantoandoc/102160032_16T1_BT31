#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
using namespace std;
class Date
{
private:
	int day, month, year;
public:
	Date(int = 0, int = 0, int = 0);
	Date(const Date &);
	int getYear();
	int getMonth();
	int getDay();
	~Date();
	friend istream & operator >> (istream &, Date &);
	friend ostream & operator << (ostream &, Date &);
};

