#include <iostream>
#include "mydate.h"

using namespace std;

//Sorts in ascending order an array of dates
void ascendentOrder(MyDate array[], int size);

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

    if( date1.isEqual(date2) )
        cout << "Yes\n" ;
    else
        cout << "No\n" ;

    cout << "\nAre date1 and date2 different? " ;

    if( date1.isDifferent(date2) )
        cout << "Yes\n" ;
    else
        cout << "No\n" ;

    cout << "\nIs date1 before date2? " ;

    if( date1.isBefore(date2) )
        cout << "Yes\n" ;
    else
        cout << "No\n" ;

    cout << "\nIs date1 after date2? " ;

    if( date1.isAfter(date2) )
        cout << "Yes\n" ;
    else
        cout << "No\n" ;

    return 0 ;
}

//Sorts in ascending order an array of dates
void MyDate::ascendentOrder(MyDate array[], int size)
{
  int temp;
  for(i=1;i<n;++i)
  {
      for(j=0;j<(n-i);++j)
          if(array[j]>array[j+1])
          {
              temp=array[j];
              array[j]=array[j+1];
              array[j+1]=temp;
          }
  }
  }
