#include "mydate.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string DAY[]={"Friday", "Saturday", "Sunday","Monday","Tuesday","Wednesday","Thursday"};

string MONTH[]={"January","February","March", "April", "May", "June", "July", "August"
, "September", "October", "November", "December"};

int totalMonthDays[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int MyDate::elapsed() const
{
    if (month=1 || month=2)
    {
        month+=12;
        year--;
    }
    int ElapsedDays=365*year + year/4 - year/100 +year/400 +day
            +(153*month+8)-578135;
    return ElapsedDays;
}


MyDate::MyDate(int month, int day, int year)
{
    set(month, day, year);
}

MyDate::MyDate()
{
    month=0;
    day=0;
    year=0;
}

int MyDate::getMonth()
{
    return month;
}

int MyDate::getDay()
{
    return day;
}

int MyDate::getYear()
{
    return year;
}

void MyDate::set(int month, int day, int year)
{
    if(month >=1 && month <= 12)
        this->month=month;

    if (year>1582)
        this->year=year;

    switch(month-1)
    {
    case 1:
        if (isLeapYear() && (day>=0 && day <= 29))
            this->day=day;
        else if (day>=0 && day <= 28)
            this->day=day;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if(day>=0 && day <= 30)
            this->day=day;
        break;
    default:
        if(day>=0 && day <= 31)
            this->day=day;
       break;
    }
}

string MyDate::dayOfWeek() const
{
    return DAY[elapsed()%7];
}

string MyDate::getMonthStr() const
{
    return MONTH[month-1];
}

void MyDate::addDays(int num)
{
    for (int i=0; i <num; i++)
    {
        day++;
        if(isLeapYear())
            totalMonthDays[1]=29;
        else
            totalMonthDays[1]=28;
        if (day > totalMonthDays[month])
        {
            day = 1;
            month++;
        }
        if (month >= 12)
        {
            month = 1;
            year++;
        }
    }
}

bool MyDate::isLeapYear() const
{
    return ((year%4==0 )||(year%400==0));
}

int MyDate::difference(const MyDate &d) const
{
   int result=(year-d.year)*365;

   for (int i=0; i< month-1;i++)
       result += (i+1)*totalMonthDays[month-2];

   for (int i=0; i< d.month-1;i++)
       result -= (i+1)*totalMonthDays[d.month-2];

   result += (day-d.day);

}

bool MyDate::isEqual(const MyDate &d) const
{
    return this->month==d.month &&
            this->year ==d.year &&
            this->day == d.day;
}

bool MyDate::isDifferent(const MyDate &d) const
{
    return this->month!=d.month &&
            this->year !=d.year &&
            this->day != d.day;
}

bool MyDate::isBefore(const MyDate &d) const
{
    return (this->year < d.year)||
            (this->year<=d.year && this->month < d.month)||
            (this->month<=d.month && this->year <=d.year && this->day < d.day);
}

bool MyDate::isAfter(const MyDate &d) const
{
    return (this->year > d.year)||
            (this->year>=d.year && this->month > d.month)||
            (this->month>=d.month && this->year >=d.year && this->day > d.day);
}

string MyDate::simpleRepre()
{
    
    
}

string MyDate::niceRepre()
{
    
}

bool MyDate::operator==(const MyDate &s) const
{
    return this->month==d.month &&
            this->year ==d.year &&
            this->day == d.day;
}

bool MyDate::operator!=(const MyDate &s) const
{
    return this->month!=d.month &&
            this->year !=d.year &&
            this->day != d.day;
}

bool MyDate::operator<(const MyDate &s) const
{
    return (this->year < d.year)||
            (this->year<=d.year && this->month < d.month)||
            (this->month<=d.month && this->year <=d.year && this->day < d.day);
}

bool MyDate::operator>(const MyDate &s) const
{
    return (this->year > d.year)||
            (this->year>=d.year && this->month > d.month)||
            (this->month>=d.month && this->year >=d.year && this->day > d.day);
}

void MyDate::operator+(int num) const
{
    for (int i=0; i <num; i++)
    {
        day++;
        if(isLeapYear())
            totalMonthDays[1]=29;
        else
            totalMonthDays[1]=28;
        if (day > totalMonthDays[month-1])
        {
            day = 1;
            month++;
        }
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }
}

void MyDate::operator-(int num) const
{
    for (int i=0; i <num; i++)
    {
        day--;
        if(isLeapYear())
            totalMonthDays[1]=29;
        else
            totalMonthDays[1]=28;
        if (day == 0 )
        {
            month--;
            if (month ==0)
            {
                month = 12;
                year--;
            }
            day = totalMonthDays[month-1];

        }
    }
}

int operator-(const MyDate &d) const
{
    int result=(year-d.year)*365;

    for (int i=0; i< month-1;i++)
        result += (i+1)*totalMonthDays[month-2];

    for (int i=0; i< d.month-1;i++)
        result -= (i+1)*totalMonthDays[d.month-2];

    result += (day-d.day);
}

friend ostream &operator<<( ostream &out, const MyDate &s)
{

}

friend istream &operator>> (istream&, MyDate &)
{

}
