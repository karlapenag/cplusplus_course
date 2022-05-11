//
// Created by Karla Angélica Peña Guerra on 2/28/22.
//
#include <iostream>
using namespace std;
struct student{
    int ID_number,birthYear=0,credit_hours=0;
    string firstName="",lastName="";
    char gender= 0;
    float cgpa=0.0;
    string academic_standing;

};
int main() {
    cout << "This program manages student records.";
    string menu = "======================================"
                  "\nWhat would you like to do?"
                  "\na- Enter a student's information"
                  "\nb- Find a student's information"
                  "\nc- Quit"
                  "\n>> ";
    char command = 0;
    //int record_counter=0;
    student student_records[1000] = {};
    int record_counter = 0;
    while (command != 'c') {
        cout << menu;
        cin >> command;
        switch (command) {
            case 'a': {
                //add code for entering a student's data

                cout << "ID number:";
                cin >> student_records[record_counter].ID_number;
                cout << "First name:";
                cin >> student_records[record_counter].firstName;
                cout << "Last name:";
                cin >> student_records[record_counter].lastName;
                cout << "Birth Year:";
                cin >> student_records[record_counter].birthYear;
                cout << "Gender (M/F):";
                cin >> student_records[record_counter].gender;
                cout << "Credit hours:";
                cin >> student_records[record_counter].credit_hours;
                cout << "GPA:";
                cin >> student_records[record_counter].cgpa;
                cout << "Satisfactory academic standing (y/n):";
                cin >> student_records[record_counter].academic_standing;
                record_counter++;
                break;
            }
            case 'b': {
                //add code for printing all student's data

                cout << "Student ID: ";
                int student_ID = 0;
                cin >> student_ID;
                for (int i = 0; i < record_counter; i++) {
                    if (student_records[i].ID_number == student_ID) {
                        cout << "Name: " << student_records[i].firstName << " " << student_records[i].lastName << endl;
                        cout << "Demographics: " << student_records[i].gender << ", " << student_records[i].birthYear
                             << endl;
                        cout << "Academic record: " << student_records[i].credit_hours << " credit hours, "
                             << student_records[i].cgpa << " GPA, ";
                        if (student_records[i].academic_standing == "y") {
                            cout << "satisfactory academic standing";
                        } else {
                            cout << "unsatisfactory academic standing";
                        }
                        cout << endl;
                    }

                }
                break;
            }
            case 'c': {
                cout << "This is c";
                break;
            }
            default:{
                cout << "Invalid command" << endl;
            }
        }
    }
}