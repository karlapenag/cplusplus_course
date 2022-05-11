//
// Created by smaouim on 11/19/2020.
//

#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(int accID, double accBalance, double accMinBalance)
{
    ID = accID;
    minBalance = accMinBalance;
    if(accBalance >= accMinBalance)
    {
        balance = accBalance;
    }
    else
    {
        cout << "Balance should be larger than " << accMinBalance << endl;
        balance = 0;
        cout << "Balance initialaised to 0." << endl;
    }
}

double SavingsAccount::withdraw(double amount) {
    if(balance - amount >= minBalance)
    {
        balance -= amount;
        cout << "Withdrawal successful" << endl;
        cout << "New balance: " << balance << endl;
    }
    else
    {
        cout << "Not enough credit." << endl;
        cout << "Current balance: " << balance << endl;
    }
    return balance;
}

double SavingsAccount::deposit(double amount) {
    if(amount >= 100)
    {
        balance += amount;
        cout << "Deposit successful" << endl;
        cout << "New balance: " << balance << endl;
    }
    else
    {
        cout << "Minimum deposit is 100" << endl;
        cout << "Current balance: " << balance << endl;
    }
    return balance;
}

