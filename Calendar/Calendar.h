//
// Created by Chen Gutman id:205616147 and Yarin Mizrahi id:205663917 on 14/11/2019.
//

#pragma once
#include "MyDate.h"


class Calendar
{
private:
    MyDate* cal[30];

public:
	Calendar();

	int setDate(const MyDate& newDate, int num);
	bool isFree(int num);
	int firstFree();
	int insert(const MyDate& newDate);
	int oldest();
	int datesNum(const MyDate& newDate);
	void deleteAll();
	int deleteDate(int num);
	char* print();
	void sortDates();

	~Calendar() {};
};

