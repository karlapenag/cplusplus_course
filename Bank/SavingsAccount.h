//
// Created by smaouim on 11/19/2020.
//

#ifndef BANK_SAVINGSACCOUNT_H
#define BANK_SAVINGSACCOUNT_H
#include "Account.h"
#include <iostream>
using namespace std;

class SavingsAccount : public Account {
    double minBalance;

public:
    SavingsAccount() : minBalance(1000), Account() {};
    SavingsAccount(int accID, double accBalance, double accMinBalance);
    double withdraw(double amount);
    double deposit(double amount);

};


#endif //BANK_SAVINGSACCOUNT_H
