#include <iostream>
using namespace std;

bool leapYear(int year, int step = 0)
{
    if (step == 0)
    {
        if (year % 400 == 0)
            return true;

        return leapYear(year, 1);
    }

    if (step == 1)
    {
        if (year % 100 == 0)
            return false;

        return leapYear(year, 2);
    }

    if (step == 2)
    {
        if (year % 4 == 0)
            return true;

        return false;
    }

    return false;
}

int main()
{
    int year;
    cin >> year;

    if (year <= 0)
    {
        cout << "Invalid Year";
        return 0;
    }

    if (leapYear(year))
        cout << year << " is Leap Year";
    else
        cout << "Not Leap Year";

    return 0;
}