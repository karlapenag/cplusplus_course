//
// Created by Karla Angélica Peña Guerra on 3/25/22.
//
#include <iostream>
#include <iomanip>
using namespace std;

/*int main() {

    int size;
    cout << "values";
    cin >> size;
    int *ptr = new int[size];
    cout << "more values" << endl;
    for (int i = 0; i < size; i++) {
        cin >> ptr[i];
    }
    cout << "array is: " << endl;
    for (int i = 0; i < size; i++) {
        cout << ptr[i] << endl;
    }
}*/
class Student{
public:
    string studentName;
    int studentAge;
    int studentMarks;
    int admissionYear;

    Student(string name, int age, int marks, int year)
    {
        studentName = name;
        studentAge = age;
        studentMarks = marks;
        admissionYear = year;
    }
};
 int main()
 {
     Student studentArray[4] = {Student("Alex", 20, 80, 2018), Student("Bob", 21, 82, 2018), Student("Chandler", 23, 85, 2017), Student("Rose", 18, 89, 2019)};
        cout
        << right
        << setw(10)
        << "Name"
        << right
        << setw(5)
        << "Age"
        << right
        << setw(8)
        << "Marks"
        << left
        << setw(5)
        << "Year"
        << endl;
        for (int i = 0; i < 4; i++)
        {
            cout
            << left
            << setw(10)
            << studentArray[i].studentName
            << left
            << setw(5)
            << studentArray[i].studentAge
            << left
            << setw(8)
            << studentArray[i].studentMarks
            << left
            << setw(5)
            << studentArray[i].admissionYear
            << endl;
        }
        return 0;
 }

