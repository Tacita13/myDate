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

    // Constructores default y parameterizado
    MyDate(int month, int day, int year);
    MyDate();

    // Getters
    int getMonth();
    int getDay();
    int getYear();

    // Setter
    void set(int month, int day, int year);
    
    // Devuelven el dia de la semana y el mes
    string dayOfWeek() const;
    string getMonthStr() const;
    
    // Agrega dias a la fecha
    void addDays(int num);
    
    // Verifica si year es un leap year
    bool isLeapYear() const;
    
    //Devuelve la diferencia de dias entre dos fechas
    int difference(const MyDate &d) const;

    // Verifica si dos fechas son iguales
    bool isEqual(const MyDate &d) const;
    
    // Verifica si dos fechas no son iguales
    bool isDifferent(const MyDate &d) const;
    
    // Verifica si la fecha esta antes del parametro
    bool isBefore(const MyDate &d) const;
    
    // Verifica si la fecha esta despues del parametro
    bool isAfter(const MyDate &d) const;
    
    // Forma sencilla para presentar la fecha: "xx/xx/xxxx"
    string simpleRepre();
    
    // Forma normal para presentar la fecha, ejemplo: "April 22, 1995"
    string niceRepre();

    // Forma alterna para isEqual
    bool operator==(const MyDate &d) const ;

    // Forma alterna para isDifferent
    bool operator!=(const MyDate &d) const ;

    // Forma alterna para isBefore
    bool operator<(const MyDate &d) const ;

    // Forma alterna para isAfter
    bool operator>(const MyDate &d) const ;

    // Forma alterna para addDays
    void operator+(int num) ;

    // Opuesto a addDays, resta dias en vez de sumar dias a la fecha
    void operator-(int num) ;

    // Forma alterna para difference
    int operator-(const MyDate &d) const ;

    // Funcion friend para insertar en la pantalla la fecha
    friend ostream &operator<<( ostream &out, const MyDate &D) ;

    // Funcion friend para extraer la fecha de un objeto MyDate
    friend istream &operator>> (istream&in , MyDate &d) ;

};

#endif // MYDATE_H
