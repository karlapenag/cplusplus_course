//
// Created by smaouim on 11/19/2020.
//

#include "Client.h"

ostream &operator<<(ostream &out, const Client &clt) {
    out << "---------------------------------------------" << endl;
    out << "Client ID: " << clt.ID << endl;
    out << "Name: " << clt.firstName << " " << clt.lastName << endl;
    out << "Phone number: " << clt.phoneNbr << endl;
    if(clt.account)
    {
        out << "Basic account info: --------" << endl;
        out << *clt.account;
    }
    else
    {
        out << "--------No record of a basic account. " << endl;
    }
    if(clt.savingsAccount)
    {
        out << "Savings account info: ---------" << endl;
        out << *clt.savingsAccount ;
    }
    else
    {
        out << "------No record of a savings account. " << endl;
    }
    return out;
}
