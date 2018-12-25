#pragma once
#include <iostream>
using namespace std;
class Date
{
private:
	int day, month, year;
public:
	Date(int = 0, int = 0, int = 0);
	Date(const Date &);
	~Date();
	friend istream & operator >> (istream &, Date &);
};

