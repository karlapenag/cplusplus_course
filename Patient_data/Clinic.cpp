//
// Created by Karla Angélica Peña Guerra on 5/8/22.
//
#include <iostream>
#include <fstream>
using namespace std;
#include "Clinic.h"
#include "Visit.h"
#include "Patient.h"

multimap<int, Patient> patientRecords;
multimap<int, Visit> patientVisits;

Clinic::Clinic(string file_name){
    this->filename = file_name;
}

Clinic::~Clinic()= default;

int command = 0;
string firstName;
string lastName;
char gender;
int age;
string docFirst;
string docLast;
string date;
int fileNumber;
int fileNum = 0;

int Clinic::assignFileNumber() {
    ifstream infile;
    infile.open(Clinic::filename); // opens the file

    if(!infile) { // file couldn't be opened
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }

    if (infile.peek() == std::ifstream::traits_type::eof()){ // if empty
        fileNum = 1;
        return fileNum;
    }

    int maxNum = 0;
    infile >> maxNum;

    while ( !infile.eof() ) { // keep reading until end-of-file
        infile >> fileNum;
        if (fileNum > maxNum){
            maxNum = fileNum;
        }
    }
    infile.close();
    fileNum = maxNum + 1;
    updatePatientFileNumbers(fileNum);

    return fileNum;
}

int Clinic::assignVisitID(int file_no) {
    int maxNum = 0;
    multimap<int, Visit>::iterator it;
    for (it = patientVisits.equal_range(file_no).first; it!=patientVisits.equal_range(file_no).second; ++it){
        int visit_number = (*it).second.getVisitIdNumber();
        if (visit_number > maxNum){
            maxNum = visit_number;
        }
    }
    int visit_number = maxNum + 1;
    return visit_number;
}

void Clinic::updatePatientFileNumbers(int fileNum) {
    ofstream outfile;
    outfile.open(Clinic::filename, std::ios::app);
    outfile << fileNum;
    this->filename = to_string(fileNum);
    outfile.close();
}

void Clinic::runMenu() {
    cout << "Welcome to patient management" << endl;
    cout << endl;

    while(command != QUIT)
    {
        cout << "================================================" << endl;
        cout << "Please choose a command: " << endl;
        cout << NEWPATIENT << ". Add new patient" << endl;
        cout << NEWVISIT << ". Add new visit" << endl;
        cout << DISPINFO << ". Display patient information" << endl;
        cout << QUIT << ". Quit" << endl;
        cout <<"===============>";
        cin >> command;
        while(command < NEWPATIENT || command > QUIT) {
            cout << "Invalid command" << endl;
            cin >> command;
        }

        switch(command)
        {
            case NEWPATIENT:{
                cout << "First name (no spaces):";
                cin >> firstName;
                cout << "Last name (no spaces):";
                cin >> lastName;
                cout << "Gender (M or F):";
                cin >> gender;
                cout << "Age:";
                cin >> age;
                int file_number = assignFileNumber();
                Patient patient = Patient(file_number, firstName, lastName, gender, age);
                patientRecords.insert({file_number, patient});
                break;
            }
            case NEWVISIT:{
                cout << " Patient file number: ";
                cin >> fileNumber;
                cout << " Date (dd/mm/yyyy): ";
                cin >> date;
                cout << " Doctor's first name: ";
                cin >> docFirst;
                cout << " Doctor's last name: ";
                cin >> docLast;
                int visitID = assignVisitID(fileNumber);
                Visit visit = Visit(fileNumber,visitID,date,docFirst,docLast);
                patientVisits.insert({fileNumber,visit});
                // addvisit function in patient class

                break;
            }
            case DISPINFO:{
                int inputFN;
                cout << " Patient file number: " << endl;
                cin >> inputFN;
                cout << "---------------------";
                cout << patientRecords.find(inputFN)->second;
                cout << patientVisits.find(inputFN)->second;

                break;
            }
            case QUIT:{
                cout << " Thank you for using patient management. Bye!" << endl;
                break;
            }
        }
    }
}