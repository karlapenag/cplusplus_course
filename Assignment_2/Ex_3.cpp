//
// Created by Karla Angélica Peña Guerra on 2/22/22.
//
// CS 207
// 180951
#include <iostream>
#include <string>
using namespace std;

struct Student {
    int ID;
    string firstName;
    string lastName;
    int birthYear;
    string gender;
    int credits;
    float gpa;
    string academicStanding;
};

int main(){
    cout << " EXERCISE 3 " << endl;
    cout << " This program manages student records." << endl;
    string menu = "======================================"
                  "\nWhat would you like to do?"
                  "\na- Enter a student's information"
                  "\nb- Find a student's information"
                  "\nc- Quit"
                  "\n>> ";
    char command = 0;

    Student studentRecord[1000]; // array that will only allow 1000 entries
    int counter = 0; // counter to store student indexes and the total registered students

    while (command != 'c')
    {
        cout << menu;
        cin >> command;
        switch(command)
        {
            case 'a':
                //add code for entering a student's data
                cout<<"ID number: ";
                cin>>studentRecord[counter].ID;
                cout<<"First name: ";
                cin>>studentRecord[counter].firstName;
                cout<<"Last name: ";
                cin>>studentRecord[counter].lastName;
                cout<<"Birth year: ";
                cin>>studentRecord[counter].birthYear;
                cout<<"Gender: ";
                cin>>studentRecord[counter].gender;
                cout<<"Credit hours: ";
                cin>>studentRecord[counter].credits;
                cout<<"GPA: ";
                cin>>studentRecord[counter].gpa;
                cout<<"Satisfactory academic standing (y/n):";
                cin>>studentRecord[counter].academicStanding;
                counter ++; // update index
                break;
            case 'b':
                //add code for printing all student's data
                cout<<"Student ID: ";
                int id_num;
                cin>>id_num;

                for(int i=0;i<1000;i++){
                    if(id_num==studentRecord[i].ID){  // if the prompted ID number matches a student record ID
                        int studentIndex=i;  // the student to which the ID belongs, has its index = i
                        cout<<"Name: "<<studentRecord[studentIndex].firstName<<" "<<studentRecord[studentIndex].lastName<<endl;
                        cout<<"Demographics: "<<studentRecord[studentIndex].gender<<", "<<studentRecord[studentIndex].birthYear<<endl;
                        cout<<"Academic record: "<<studentRecord[studentIndex].credits<<" credit hours, "<<studentRecord[studentIndex].gpa<<" GPA";
                        if (studentRecord[studentIndex].academicStanding == "y"){ // if the academic standing was answered with 'y'
                            cout<<", satisfactory academic standing"<<endl;
                        }
                        else{
                            cout<<endl;
                        }
                        break;
                    }
                    else if(i==counter){ // if the loop has already gone through all the registered students and
                        // didn't find a match, then the ID is not in the record.
                        cout<<"The ID number does not belong to any Student Record."<<endl;
                    }
                }
                break;
            case 'c':
                break;
            default:
                cout << "Invalid command" << endl;
        }
    }
    return 0;
}


