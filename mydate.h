#ifndef MYDATE_H
#define MYDATE_H
#include <string>
using namespace std;

class MyDate
{
private:
    int month, day, year;
    int elapsed() const;
public:
    MyDate(int month, int day, int year);
    MyDate();
    int getMonth();
    int getDay();
    int getYear();
    void set(int month, int day, int year);
    
    string dayOfWeek() const;
    
    string getMonthStr() const;
    
    void addDays(int num);
    
    bool isLeapYear() const;
    
    int difference(const MyDate &d) const;
    
    bool isEqual(const MyDate &d) const;
    
    bool isDifferent(const MyDate &d) const;
    
    bool isBefore(const MyDate &d) const;
    
    bool isAfter(const MyDate &d) const;
    
    string simpleRepre();
    
    string niceRepre();

    bool operator==(const MyDate &s) const ;
    bool operator!=(const MyDate &s) const ;
    bool operator<(const MyDate &s) const ;
    bool operator>(const MyDate &s) const ;
    void operator+(int num) ;
    void operator-(int num) ;

    int operator-(const MyDate &d) const ;

    friend ostream &operator<<( ostream &out, const MyDate &s) ;
    friend istream &operator>> (istream&, MyDate &) ;

};

#endif // MYDATE_H
