#ifndef Date_cpp
#define Date_cpp

#include <iostream>
#include "Date.h"

using namespace std;

Date::Date(int d, int m, int y){
    day = d;
    month = m;
    year = y;
}

Date::~Date(){}

int Date::getDay(){ return day;}
int Date::getMonth(){ return month;}
int Date::getYear(){ return year;}   

void Date::setDay(int d){
    day = d;
}
void Date::setMonth(int m){
    month = m;
}
void Date::setYear(int y){
    year = y;
}

void Date::checkDay(){

    bool isLeapYear = false;

    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                isLeapYear = true;
            }
        }
        else{
            isLeapYear = true;
        }
    }
    
    if(day < 0){
        if(month == 1 || month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11){
            day=day+31;
            month--;
            checkMonth();
        }
        else if(month == 5 || month == 7 || month == 10 || month == 12){
            day=day+30;
            month--;
            checkMonth();
        }
        else if(month == 3){
            if(isLeapYear){
                day=day+29;
                month--;
                checkMonth();
            }
            else{
                day=day+28;
                month--;
                checkMonth();
            }
        }
    }
    else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        if(day > 31){
            day=day-31;
            month++;
            checkMonth();
        }
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11){
        if(day > 30){
            day=day-30;
            month++;
            checkMonth();
        }
    }
    else if(month == 2){
        if(isLeapYear){
            if(day > 29){
                day=day-29;
                month++;
                checkMonth();
            }
        }
        else{
            if(day > 28){
                day=day-28;
                month++;
                checkMonth();
            }
        }
    }
    
}

void Date::checkMonth(){
    if(month > 12){
        month = month%12;
        year++;  
    }
    else if(month < 0){
        month = 12+month;
        year--;
    
    }
    checkDay();
}

Date Date::DateAfter(int days){
    Date date(day+days, month, year);
    date.checkDay();

    return date;
}

Date Date::DateBefore(int days){
    Date date(day-days, month, year);
    date.checkDay();

    return date;
}

int Date::numberOfDays()
{
    int daysInMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    bool isLeapYear=true;
    if(month==2){
        if (year % 4 == 0)
        {
            if (year % 100 == 0)
            {
                if (year % 400 == 0)
                {
                    isLeapYear = true;
                }
            }
            else
            {
                isLeapYear = true;
            }
        }

        if(isLeapYear){
            return 29;
        }
        else{
            return 28;
        }
    }
    else{
        return daysInMonth[month-1];
    }
}

string Date::days(){
    bool isLeapYear=true;
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                isLeapYear = true;
            }
        }
        else
        {
            isLeapYear = true;
        }
    }

    int c=(year-year%100)/100, y=year%100, m=month, d=day;

    int sum = 2*(3-(c%4)) + (y%28+((y%28)/4))%7 + d%7;
    int M=(3.4 + (m - 3) % 12 * 2.6);
    M = M % 7;

    if (isLeapYear && (month == 1 || month == 2)){
        M-=1;
    }

    sum = (sum +M) % 7;

    string daysOfWeek[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    

    return daysOfWeek[sum];
}

void Date::printMonthCalendar(){
    int daysInMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    bool isLeapYear=true;
    if(month==2){
        if (year % 4 == 0)
        {
            if (year % 100 == 0)
            {
                if (year % 400 == 0)
                {
                    isLeapYear = true;
                }
            }
            else
            {
                isLeapYear = true;
            }
        }

        if(isLeapYear){
            daysInMonth[1]=29;
        }
        else{
            daysInMonth[1]=28;
        }
    }

    string MONTH[12]= {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    string MON=MONTH[month-1];
    cout << "--------------" << MON << "--------------\n";
    cout << "Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

    int c = (year - year % 100) / 100, y = year % 100, m = month, d = day;

    int sum = 2 * (3 - (c % 4)) + (y % 28 + ((y % 28) / 4)) % 7 + d % 7;
    int M = (3.4 + (m - 3) % 12 * 2.6);
    M = M % 7;

    if (isLeapYear && (month == 1 || month == 2))
    {
        M -= 1;
    }

    sum = (sum + M) % 7;

    int countDay=0;
    
    for(int i=0;i<sum;i++){
        cout << "     ";
        countDay++;
    }

    for(int i=1;i<=daysInMonth[month-1];i++){
        if(i<10){
            cout<<" ";
        }
        cout << i << "   ";
        countDay++;
        if(countDay%7==0){
            cout << endl;
        }
    }
}
#endif