//
// Created by Chen Gutman id:205616147 and Yarin Mizrahi id:205663917 on 14/11/2019.
//

#pragma once
#include <iostream>
#include "string.h"

using namespace std;

class MyDate
{
private:
	int _day,_month,_year;

public:
	MyDate();
	MyDate(int day, int month, int year);

	void init();
	int set(int day, int month, int year);
	int setDay(int day);
	int setMonth(int month);
	int setYear(int year);
	int getDay();
	int getMonth();
	int getYear();
	bool isEquale(const MyDate& newDate);
	bool isBefore(const MyDate& newDate);
	int delay(int num);
	int bringForward(int num);
	char* print();


	~MyDate() {};
};

