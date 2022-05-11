//
// Created by Karla Angélica Peña Guerra on 2/22/22.
//
#include <iostream>
using namespace std;
enum weekday{
    SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, ALL_DAYS};
int main()
{
    struct fraction{
        int numerator;
        int denominator;
        };

    fraction f1 {0,1} , f2 {0, 1};
    cout << "Please enter the numerator and denominator of the first fraction, separated by a space: ";
    cin >> f1.numerator >> f1.denominator;
    cout << "Please enter the numerator and denominator of the second fraction, separated by a space: ";
    cin >> f2.numerator >> f2.denominator;

    fraction f3 {f1.numerator * f2.numerator, f1.denominator * f2.denominator};
    //f3.numerator = f1.numerator * f2.numerator;
    //f3.denominator = f1.denominator * f2.denominator;
    cout << "The product of these two fractions is: " << f3.numerator << "/" << f3.denominator ;
    cout << " = " << (double) f3.numerator / f3.denominator << endl;

    string openingHours[ALL_DAYS][2];
    for(weekday day = SUNDAY; day <ALL_DAYS; day=weekday(day+1))
    {
        string dayString;
        switch(day)
        {
            case SUNDAY: dayString = "Sunday"; break;
            case MONDAY: dayString = "Monday"; break;
            case TUESDAY: dayString = "Tuesday"; break;
            case WEDNESDAY: dayString = "Wednesday"; break;
            case THURSDAY: dayString = "Thursday"; break;
            case FRIDAY: dayString = "Friday"; break;
            case SATURDAY: dayString = "Saturday"; break;
            default: dayString = "";
        }
        cout << "Please enter the opening and closing time for " << dayString;
        cout  << " in the format hh:mm hh:mm" << endl;
        cin >> openingHours[day][0] >> openingHours[day][1];
    }
    cout << "Table of opening hours: " << endl;
    for(weekday day = SUNDAY; day <ALL_DAYS; day=weekday(day+1))
    {
        string dayString;
        switch(day)
        {
            case SUNDAY: dayString = "Sunday"; break;
            case MONDAY: dayString = "Monday"; break;
            case TUESDAY: dayString = "Tuesday"; break;
            case WEDNESDAY: dayString = "Wednesday"; break;
            case THURSDAY: dayString = "Thursday"; break;
            case FRIDAY: dayString = "Friday"; break;
            case SATURDAY: dayString = "Saturday"; break;
            default: dayString = "";
        }
        cout << dayString << ": " << openingHours[day][0] << " to " << openingHours[day][1] << endl;
    }
    return 0;
}
