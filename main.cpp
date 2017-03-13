#include <iostream>
#include "mydate.h"

using namespace std;

void ascendentOrder(MyDate array[], int size) ;

int main()
{
    cout << "Hello World!" << endl ;

    MyDate date1(11, 26, 1995) ;

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

    date2.set(4,1,2003) ;

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

    cout << "After sort: " ;

    for(int i = 0 ; i < size ; i++)
    {
        cout << array[i] << " | " ;
    }
}
