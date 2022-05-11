//
// Created by Karla Angélica Peña Guerra on 5/8/22.
//
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>
#include "Visit.h"
#include "Clinic.h"

using namespace std;

#ifndef PATIENT_DATA_PATIENT_H
#define PATIENT_DATA_PATIENT_H

class Patient {
    /*
     * This class will save the Patient's information (file number, first & last name, gender and age) in a vector
     * Add visits to vector separately (one by one)
     * Create output file (file_number.txt) with above information
     * Give access to the information in the file
     */
private:
    int file_number;
    string first_name;
    string last_name;
    char gender;
    int age;
    vector<Visit> visits;
public:
    // Constructor and destructor
    Patient(int fileNumber, string firstName, string lastName, char gender, int age);
    Patient(int fileNumber);
    ~Patient();

    // Functions
    friend ostream& operator<<(ostream& os, Patient patient); // overload operator <<

    void addVisit(Visit visit);

    int getFileNumber() const;
    const string &getFirstName() const;
    const string &getLastName() const;
    char getGender() const;
    int getAge() const;
    const vector<Visit> &getVisits() const;


};




#endif //PATIENT_DATA_PATIENT_H
