// Problem 19 -- Counting Sundays
#include <iostream>
using namespace std;

int main()
{
    unsigned int date = 1;
    unsigned int month = 1;
    unsigned int year = 1900;
    unsigned int day = 1;
    unsigned int sundayCount = 0;
    while (!(day == 1 && year == 2001))
    {
        date++;
        day++;
        if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            if (date > 30)
            {
                date = 1;
                month++;
            }
        }
        else if (month != 2)
        {
            if (date > 31)
            {
                date = 1;
                month++;
            }
        }
        else if (date > 28)
        {
            if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            {
                if (date > 29)
                {
                    date = 1;
                    month++;
                }
            }
            else
            {
                date = 1;
                month++;
            }
        }
        if (day > 7)
            day = 1;
        if (month == 13)
        {
            month = 1;
            year++;
        }
        if (year >= 1901 && year <= 2000)
            if (date == 1 && day == 7)
                sundayCount++;
    }
    cout << sundayCount << "\n";
    return 0;
}