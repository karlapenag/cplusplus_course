//
// Created by Karla Angélica Peña Guerra on 5/8/22.
//
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>
using namespace std;

#ifndef PATIENT_DATA_VISIT_H
#define PATIENT_DATA_VISIT_H


class Visit {
private:
    int file_number;
    int visit_id_number;
    string date;
    string docs_first;
    string docs_last;
    friend class Patient;

    /*
     * This class will store Visits data for a Patient (visit ID number, patient file number, date, doctor's first & last name)
     * date as a string in the format dd/mm/yyyy
     */

public:
    // Constructor and destructor
    Visit(int fileNumber, int visitID, string date, string docsFirst, string docsLast);
    ~Visit();
    // functions
    friend ostream& operator<<(ostream& os, Visit visit); // overload operator <<

    int getVisitIdNumber() const;
    const string &getDate() const;
    const string &getDocsFirst() const;
    const string &getDocsLast() const;

};


#endif //PATIENT_DATA_VISIT_H
