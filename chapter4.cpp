#include <iostream>
using namespace std;

class Date 
{
private:
    int day, month, year;

public:
    Date() : day(0), month(0), year(0) {}
    Date(int d, int m, int y) : day(d), month(m), year(y) {}
    Date(const Date &d) : day(d.day), month(d.month), year(d.year) {}

    void setDay(int d) { day = d; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    bool operator==(const Date &d) const 
    {
        return (day == d.day && month == d.month && year == d.year);
    }

    bool operator<(const Date &d) const 
    {
        if (year < d.year) return true;
        if (year == d.year && month < d.month) return true;
        if (year == d.year && month == d.month && day < d.day) return true;
        return false;
    }

    bool operator>(const Date &d) const 
    {
        return !(*this < d) && !(*this == d);
    }

    friend ostream &operator<<(ostream &out, const Date &d) 
    {
        out << d.year << '/' << d.month << '/' << d.day;
        return out;
    }
};

int main() 
{
    Date date1(31, 5, 1391);
    Date date2(15, 2, 1390);

    if (date1 == date2)
        cout << "Dates are equal" << endl;
    else if (date1 < date2)
        cout << "Date1 is earlier than Date2" << endl;
    else
        cout << "Date1 is later than Date2" << endl;

    return 0;
}