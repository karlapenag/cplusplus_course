//
// Created by smaouim on 11/19/2020.
//

#ifndef BANK_BANKAPP_H
#define BANK_BANKAPP_H
#include "Client.h"
#include "Account.h"
#include "SavingsAccount.h"

const int maxClients = 1000;
const int maxAccounts = 1000;
const int maxSavingsAccounts = 1000;
enum menu {CREATE = 1, LIST, WITHDRAW, DEPOSIT, QUIT};

class BankApp{
    Client clientsInfo[maxClients]; // all created with default attributes
    int nbrClients; // actual number of clients
    Account accountsInfo[maxAccounts]; // all created with default attributes
    int nbrAcc; // actual number of basic accounts
    SavingsAccount savingsInfo[maxSavingsAccounts]; // all created with default attributes
    int nbrSavAcc; // actual number of savings accounts
    void printInstructions();
    void createAccount();
    int findClient(int cltID);
    int createClient(int cltID);
    void listAll();
    void withdraw();
    void deposit();
public:
    BankApp() : nbrClients(0), nbrAcc(0), nbrSavAcc(0) {};
    void userInterface();

};


#endif //BANK_BANKAPP_H
