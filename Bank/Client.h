//
// Created by smaouim on 11/19/2020.
//

#ifndef BANK_CLIENT_H
#define BANK_CLIENT_H

#include <string>
#include "Account.h"
#include "SavingsAccount.h"
using namespace std;

class Client {
    int ID;
    string firstName;
    string lastName;
    string phoneNbr;
    Account* account;
    SavingsAccount* savingsAccount;
public:
    Client(int cltID = -1, string first = "", string last = "", string phone = "",
           Account* acc=nullptr, SavingsAccount* savAcc=nullptr) :
           ID(cltID), firstName(first), lastName(last), phoneNbr(phone),
           account(acc), savingsAccount(savAcc) {};

    int getID() {return ID;};
    Account* getAccount(){return account;};
    SavingsAccount* getSavingsAccount(){return savingsAccount;};
    void setAccount(Account* acc) {account = acc;};
    void setSavingsAccount(SavingsAccount* savAcc) {savingsAccount = savAcc;};
    friend ostream& operator<<(ostream& out, const Client& clt);
};


#endif //BANK_CLIENT_H
