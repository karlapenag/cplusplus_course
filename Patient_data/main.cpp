#include <iostream>
#include<fstream>
#include "Clinic.h"
#include "Visit.h"
#include "Patient.h"
using namespace std;


int main() {
    Clinic clinic("../patient_files/patients.txt"); //
    clinic.runMenu();

    return 0;
}
