//
// Created by Karla Angélica Peña Guerra on 5/8/22.
//
#include <iostream>
#include <fstream>
#include <string>
#include <map>


using namespace std;

#ifndef PATIENT_DATA_CLINIC_H
#define PATIENT_DATA_CLINIC_H

enum menu {NEWPATIENT = 1, NEWVISIT, DISPINFO, QUIT};

class Clinic {
    /*
     * This class stores all patient records in a map (search by file number)
     * stores all visit records in a map (search by visit number).
     */
private:
    string filename;
public:
    // Constructor and destructor
    Clinic(string file_name);
    ~Clinic();

    int assignFileNumber();
    int assignVisitID(int file_no);
    void updatePatientFileNumbers(int fileNum);
    void runMenu();
};


#endif //PATIENT_DATA_CLINIC_H
