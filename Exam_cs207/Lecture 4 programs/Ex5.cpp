#include <iostream>
using namespace std;

enum weekday{
    SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, ALL_DAYS};

int main()
{
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
