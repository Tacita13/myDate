#ifndef MYDATE_H
#define MYDATE_H
#include <string>

class MyDate
{
private:
    // The attributes of a date object
    int month, day, year;

    // Returns the number of elapsed days since October 15th, 1582
    int elapsed() ;

public:
    // Constructor. A validation of the data must be made
    MyDate(int month, int day, int year);

    // Default Constructor. Initializes the date to "00/00/0000".
    MyDate();

    // Getter function for the month
    int getMonth() const;

    // Getter function for the day
    int getDay() const;

    // Getter function for the year
    int getYear() const;

    // Setter function. A validation of the data must be made
    void set(int month, int day, int year);

    // Returns the day of the week ("Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", or "Sunday")
    string dayOfWeek() const;

    // Returns the month of the year ("January", "February", "March", ...)
    string getMonthStr() const;

    // Modifies this date, by adding num days to it. If num is positive, then the new date is chronologically after the original date. If num is negative, then the new date is chronologically before the original date
    void addDays(int num);

    // Returns true if the year is a leap year, otherwise false
    bool isLeapYear() const;

    // Returns the number of days between this date and d. The result is a positive integer if this date is chronologically after d. The result is a negative integer if this date is chronologically before d
    int difference(const MyDate &d) const;

    // Returns true if this date is equal to d, otherwise false
    bool isEqual(const MyDate &d) const;

    // Returns true if this date is different from d, otherwise false
    bool isDifferent(const MyDate &d) const;

    // Returns true if this date is chronologically before d, otherwise false
    bool isBefore(const MyDate &d) const;

    // Returns true if this date is chronologically after d, otherwise false
    bool isAfter(const MyDate &d) const;

    // Returns a string that represents this date formatted as MM/DD/YYYY, e.g. "02/24/2016". Note that the month and the day must be represented over two digits.
    string simpleRepre();

    // Returns a string that represents this date with a nice format, e.g.,    // "February 24, 2016"
    string niceRepre();

     // Returns true if this date is equal to d, otherwise false
    bool operator==(const MyDate &s) const ; 
    
    // Returns true if this date is different from d, otherwise false
    bool operator!=(const MyDate &s) const ;
    
    // Returns true if this date is chronologically before d, otherwise false
    bool operator<(const MyDate &s) const ;
    
    // Returns true if this date is chronologically after d, otherwise false
    bool operator>(const MyDate &s) const ;

    // Returns a string that represents this date with a nice format, e.g.,    // "February 24, 2016"
    friend ostream &operator<<( ostream &out, const MyDate &s) ;
    
    // Let the use of "cin >> mm/dd/yyyy" to enter a date.
    friend istream &operator>> (istream&, MyDate &) ;
    
};

#endif // MYDATE_H
