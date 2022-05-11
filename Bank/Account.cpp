//
// Created by smaouim on 11/19/2020.
//

#include "Account.h"
#include <iostream>
using namespace std;

double Account::withdraw(double amount)
{
    if(amount <= balance)
    {
        balance -= amount;
        cout << "Withdrawal successful" << endl;
        cout << "New balance: " << balance << endl;
    }
    else
    {
        cout << "Not enough credit" << endl;
        cout << "Current balance: " << balance;
    }
    return balance;
}
double Account::deposit(double amount)
{
    balance += amount;
    cout << "Deposit successful" << endl;
    cout << "New balance: " << balance << endl;
    return balance;
}
void Account::print()
{
    cout << "Account nbr: " << ID << endl;
    cout << "Current balance: " << balance << endl;
}

std::ostream& operator<<(std::ostream& out, const Account& acc)
{
    out << "Account nbr: " << acc.ID << endl;
    out << "Current balance: " << acc.balance << endl;
}