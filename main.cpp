// CCOM 4029: Lenguajes de Alto Nivel
// Profesor: Eric Gamess
//
// Estudiantes:
// Alex Castiillo Carrasco
// Isamar López Rodríguez
// Rafael L. Marrero Fernández

//    Descripción :This file holds the main that finally displays
//    the values of the class myDate and an additional function 
//    ascendentOrder that orders a given array of dates in ascending
//    order.

#include <iostream>
#include "mydate.h"

using namespace std;

//orders a given array of dates in ascending order
void ascendentOrder(MyDate array[], int size) ;

//the main function holds a series of examples that test the class myDate
//with its data members and function members
int main()
{
    MyDate date1(10, 31, 1995) ;

    cout << "\nMonth: " << date1.getMonthStr() << endl ;
    cout << "Day: " << date1.getDay() << endl ;
    cout << "Year: " << date1.getYear() << endl ;

    cout << "\nDate of 1: " << date1.simpleRepre() ;
    cout << "\nDate of 1: " << date1.niceRepre() << endl ;

    if( date1.isLeapYear() )
        cout << "\ndate1 is a Leap Year.\n" ;
    else
        cout << "\ndate1 is not a Leap Year.\n" ;

    MyDate date2 ;

    cout << "\nDate of 2 before setFunction: " << date2.simpleRepre() << " " << date2.niceRepre() << endl ;

    date2.set(4,1,2002) ;

    cout << "\nDate of 2 after setFunction: " << date2.simpleRepre() << " " << date2.niceRepre() << endl ;

    if( date2.isLeapYear() )
        cout << "\ndate2 is a Leap Year..\n" ;
    else
        cout << "\ndate2 is not a Leap Year.\n" ;

    cout << "\nAre date1 and date2 equal? " ;

    if( date1 == date2 )
        cout << "Yes\n" ;
    else
        cout << "No\n" ;

    cout << "\nAre date1 and date2 different? " ;

    if( date1 != date2 )
        cout << "Yes\n" ;
    else
        cout << "No\n" ;

    cout << "\nIs date1 before date2? " ;

    if( date1 < date2 )
        cout << "Yes\n" ;
    else
        cout << "No\n" ;

    cout << "\nIs date1 after date2? " ;

    if( date1 > date2 )
        cout << "Yes\n" ;
    else
        cout << "No\n" ;

    MyDate date3 ;

    cout << "\nEnter a date in the form mm/dd/yyyy: " ;
    cin >> date3 ;
    cout << endl << date3 << endl ;

    MyDate list[] = {date3, date1, date2} ;

    ascendentOrder(list, 3) ;

    return 0 ;
}
//this function orders a given array of dates with its size in ascending order
void ascendentOrder(MyDate array[], int size)
{
    int n, location ;
    MyDate temp ;

    for (n = 1 ; n < size ; n++)
        if (array[n] < array[n - 1])
        {
            temp = array[n] ;
            location = n ;
            do
            {
                array[location] = array[location - 1] ;
                location-- ;
            } while (location > 0 && array[location - 1] > temp) ;
            array[location] = temp ;
        }
}
