//
// Created by smaouim on 11/19/2020.
//

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include <ostream>
using namespace std;

class Account {
protected:
    double balance;
    int ID;

public:
    Account(): ID(-1), balance(0.0) {};
    Account(int accID, double accBal) : ID(accID), balance(accBal) {};
    double withdraw(double amount);
    double deposit(double amount);
    void print();
    friend ostream& operator<<(ostream& outstream, const Account& acc);
};


#endif //BANK_ACCOUNT_H
