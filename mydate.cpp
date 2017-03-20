// CCOM 4029: Lenguajes de Alto Nivel
// Profesor: Eric Gamess
//
// Estudiantes:
// Alex Castiillo Carrasco
// Isamar López Rodríguez
// Rafael L. Marrero Fernández

//    Descripción :This file holds the implementation of the class myDate.
//    This class manages dates which consits of three numbers that represent
//    month, day and year.


#include "mydate.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Lista que contiene los dias de la semana
string DAY[]={"Friday", "Saturday", "Sunday","Monday","Tuesday","Wednesday","Thursday"};

// Lista que contiene los meses en forma string
string MONTH[]={"January","February","March", "April", "May", "June", "July", "August"
, "September", "October", "November", "December"};

int totalMonthDays[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Formula dada en el pdf de la Tarea. Es usada para
// calcular y el año es un leap year.
int MyDate::elapsed() const
{
    int d=day,m=month,y=year;
    if (m==1 || m==2)
    {
        m+=12;
        y--;
    }
    int ElapsedDays=365*y + y/4 - y/100 +y/400 +d
            +(153*m+8)-578135;
    return ElapsedDays;
}


// Constructores default y parameterizado
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

// Getters
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

// Setter
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
    case 3:
    case 5:
    case 8:
    case 10:
        if(day>=0 && day <= 30)
            this->day=day;
        break;
    default:
        if(day>=0 && day <= 31)
            this->day=day;
       break;

        //int totalMonthDays[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    }
}

// Devuelven el dia de la semana y el mes.
// Para buscar el dia hay que calcular (day+month+year+year/4)%7
string MyDate::dayOfWeek() const
{
    return DAY[(day+month+year+year/4)%7];
}

string MyDate::getMonthStr() const
{
    return MONTH[month-1];
}

// Agrega dias a la fecha
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

// Verifica si year es un leap year
bool MyDate::isLeapYear() const
{
    return ((year%4==0 )||(year%400==0));
}

//Devuelve la diferencia de dias entre dos fechas
int MyDate::difference(const MyDate &d) const
{
   int result=(year-d.year)*365;

   for (int i=0; i< month-1;i++)
       result += (i+1)*totalMonthDays[month-2];

   for (int i=0; i< d.month-1;i++)
       result -= (i+1)*totalMonthDays[d.month-2];

   result += (day-d.day);
   return result;

}

// Verifica si dos fechas son iguales
bool MyDate::isEqual(const MyDate &d) const
{
    return this->month==d.month &&
            this->year ==d.year &&
            this->day == d.day;
}

// Verifica si dos fechas no son iguales
bool MyDate::isDifferent(const MyDate &d) const
{
    return this->month!=d.month &&
            this->year !=d.year &&
            this->day != d.day;
}

// Verifica si la fecha esta antes del parametro
bool MyDate::isBefore(const MyDate &d) const
{
    return (this->year < d.year)||
            (this->year<=d.year && this->month < d.month)||
            (this->month<=d.month && this->year <=d.year && this->day < d.day);
}

// Verifica si la fecha esta despues del parametro
bool MyDate::isAfter(const MyDate &d) const
{
    return (this->year > d.year)||
            (this->year>=d.year && this->month > d.month)||
            (this->month>=d.month && this->year >=d.year && this->day > d.day);
}

// Forma sencilla para presentar la fecha: "xx/xx/xxxx"
string MyDate::simpleRepre()
{
    stringstream ss ;

    if(month < 10)                  // 0x/dd/yyyy
        ss << '0' << month << '/' ;
    else                            // xx/dd/yyyy
        ss << month << '/' ;

    if(day < 10)                    // mm/0x/yyyy
        ss << '0' << day << '/' ;
    else                            // mm/xx/yyyy
        ss << day << '/' ;

    if(year < 10)                   // mm/dd/000x
        ss << "000" << year ;
    else if(year < 100)             // mm/dd/00xx
        ss << "00" << year ;
    else if(year < 1000)            // mm/dd/0xxx
        ss << '0' << year ;
    else                            // mm/dd/xxxx
        ss << year ;

    return ss.str() ;
}

// Forma normal para presentar la fecha, ejemplo: "April 22, 1995"
string MyDate::niceRepre()
{
    stringstream ss ;

    ss << MONTH[month - 1] << ' ' << day << ", " << year ;

    return ss.str() ;
}

// Forma alterna para isEqual
bool MyDate::operator==(const MyDate &d) const
{
    return this->month==d.month &&
            this->year ==d.year &&
            this->day == d.day;
}

// Forma alterna para isDifferent
bool MyDate::operator!=(const MyDate &d) const
{
    return this->month!=d.month &&
            this->year !=d.year &&
            this->day != d.day;
}

// Forma alterna para isBefore
bool MyDate::operator<(const MyDate &d) const
{
    return (this->year < d.year)||
            (this->year<=d.year && this->month < d.month)||
            (this->month<=d.month && this->year <=d.year && this->day < d.day);
}

// Forma alterna para isAfter
bool MyDate::operator>(const MyDate &d) const
{
    return (this->year > d.year)||
            (this->year>=d.year && this->month > d.month)||
            (this->month>=d.month && this->year >=d.year && this->day > d.day);
}

// Forma alterna para addDays
void MyDate::operator+(int num)
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

// Opuesto a addDays, resta dias en vez de sumar dias a la fecha
void MyDate::operator-(int num)
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

// Forma alterna para difference
int MyDate::operator-(const MyDate &d) const
{
    int result=(year-d.year)*365;

    for (int i=0; i< month-1;i++)
        result += (i+1)*totalMonthDays[month-2];

    for (int i=0; i< d.month-1;i++)
        result -= (i+1)*totalMonthDays[d.month-2];

    result += (day-d.day);
    return result;
}

// Funcion friend para insertar en la pantalla la fecha
ostream &operator<<( ostream &out, const MyDate &d)
{
    out << MONTH[d.month - 1] << ' ' << d.day << ", " << d.year ;
    return out;
}

// Funcion friend para extraer la fecha de un objeto MyDate
istream &operator>> (istream& in, MyDate &d)
{
    char ch ;

        in >> d.month ;
        in >> ch ;
        in >> d.day ;
        in >> ch ;
        in >> d.year ;

        return in ;
}
