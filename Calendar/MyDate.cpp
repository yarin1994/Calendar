//
// Created by Chen Gutman id:205616147 and Yarin Mizrahi id:205663917 on 14/11/2019.
//

#include "MyDate.h"
using namespace std;

MyDate::MyDate(){
    _year=0,_month=0 ,_day=0 ;
}

MyDate::MyDate(int day, int month, int year){
    set(day,month,year);
}
void MyDate::init() {
    set(20,11,2019);
}

int MyDate::set(int day, int month, int year) {
    if(setYear(year)==0 && setMonth(month)==0 && setDay(day)==0)return 0;
    _year=0,_month=0 ,_day=0 ;
    return -1;
}

int MyDate::setDay(int day) {

    if(day>0 && day<=30){
        if(_month==2)
        {
            if(day<=28){
                _day=day;
                return 0;
            }
            return -1;

        }
        _day = day;
        return 0;

    }
    return -1;
}
int MyDate::setMonth(int month) {
    if (month<=12 && month>0) {
        _month = month;
        return 0;
    }
    return -1;

}
int MyDate::setYear(int year) {
    if (year>=1900 && year <=2100){
        _year=year;
        return 0;
    }
    return -1;
}
int MyDate:: getDay(){
    return _day;
}
int MyDate::getMonth(){
    return _month;
}
int MyDate:: getYear(){
    return _year;
}
bool MyDate:: isEquale(const MyDate& newDate){
    if (_year== newDate._year && _month == newDate._month && _day==newDate._day) return true;
    return false;
}

bool MyDate::isBefore(const MyDate& newDate){
    if (_year== newDate._year && _month == newDate._month && _day==newDate._day) return false;
    if (_year<=newDate._year) {
        if(_year<newDate._year)return true;
        else{
            if(_month<=newDate._month){
                if(_month<newDate._month)return true;
                else{
                    if(_day<newDate._day)return true;
                    return false;
                }

            }
        }
    }
    return false;
}
int MyDate::delay(int num) {
    if (num>365 || _day<1 || _day>30 || (_day>28 && _month==2)) return -1;
    if (num > 0 && num<=365)
    {
        while (num>0)
        {
                --num;
                ++_day;

                if (_day > 30)
                {
                    ++_month;
                    _day = 1;
                }

                if (_month == 2 && _day > 28)
                {
                    ++_month;
                    _day = 1;
                }

                if (_month > 12)
                {
                    ++_year;
                    _month = 1;
                }
            }

            return 0;
        }

}


int MyDate::bringForward(int num){
    if (num>365) return -1;
    if (num == 365)
    {
        _year--;
        return 0;
    }

    while(num > 0)
    {
        num--;
        _day--;
        if(_day == 0)
        {
            --_month;
            if(_month == 2)_day = 28;
            else _day = 30;
        }
        if(_month == 0)
        {
            _year--;
            _month = 12;
        }
    }
    return 0;
}

char* MyDate::print() {
    char* str;
    str=new char;
    string s_day= to_string(_day);
    string s_month = to_string(_month);
    string s_year = to_string(_year);
    int index=0;
    for(int i =0;i< s_day.size();i++){
        str[i] = s_day[i];
        index++;
    }
    str[index] = '/';
    index++;
    for(int i =0;i< s_month.size();i++){
        str[index] = s_month[i];
        index++;
    }
    str[index] = '/';
    index++;
    for(int i =0;i< s_year.size();i++){
        str[index] = s_year[i];
        index++;
    }
    return str;
}