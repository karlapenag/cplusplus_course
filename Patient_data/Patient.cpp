//
// Created by Karla Angélica Peña Guerra on 5/8/22.
//
#include <iostream>
#include <fstream>
using namespace std;
#include "Clinic.h"
#include "Patient.h"
#include "Visit.h"

vector<Visit> visitsVector;

Patient::Patient(int fileNumber, string firstName, string lastName, char gender, int age) {
    this->file_number = fileNumber;
    this->first_name = firstName;
    this->last_name = lastName;
    this->gender = gender;
    this->age = age;

    ofstream outfile("../patients_files/" + to_string(fileNumber) + ".txt");
    outfile << this->file_number << endl;
    outfile << this->first_name << endl;
    outfile << this->last_name << endl;
    outfile << this->gender << endl;
    outfile << this->age << endl;
}

int Patient::getFileNumber() const {
    return file_number;
}

const string &Patient::getFirstName() const {
    return first_name;
}

const string &Patient::getLastName() const {
    return last_name;
}

char Patient::getGender() const {
    return gender;
}

int Patient::getAge() const {
    return age;
}

const vector<Visit> &Patient::getVisits() const {
    return visits;
}

Patient::Patient(int fileNumber) {


}

Patient::~Patient()= default;

std::ostream& operator<<(std::ostream& os, Patient patient)
{
    os << patient.getFileNumber() << endl;
    os << patient.getFirstName() << endl;
    os << patient.getLastName() << endl;
    os << patient.getGender() << endl;
    os << patient.getAge() << endl;

    return os;
}

void Patient::addVisit(Visit visit) {
    Patient::visits.push_back(visit);

    ofstream outfile("../patients_files/" + to_string(file_number) + ".txt", std::ios::app);
    outfile << visit.getVisitIdNumber() << " ";
    outfile << visit.getDate() << " ";
    outfile << visit.getDocsFirst() << " ";
    outfile << visit.getDocsLast();
}


