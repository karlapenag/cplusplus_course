//
// Created by smaouim on 11/19/2020.
//
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCDFAInspection"

#include "BankApp.h"
#include <cctype>

void BankApp::userInterface() {
    cout << "Welcome to KAUST Banking" << endl;
    int menuChoice = 0;

    while(menuChoice != QUIT)
    {
        printInstructions();
        cin >> menuChoice;
        while(menuChoice < CREATE || menuChoice > QUIT) {
            cout << "Invalid choice" << endl;
            printInstructions();
            cin >> menuChoice;
        }
        switch(menuChoice)
        {
            case CREATE:
                createAccount();
                break;
            case LIST:
                listAll();
                break;
            case WITHDRAW:
                withdraw();
                break;
            case DEPOSIT:
                deposit();
                break;
            case QUIT:
                cout << "Good bye" << endl;
                break;
        }
    }

}

void BankApp::printInstructions() {
    cout << "********************************************" << endl;
    cout << CREATE << ". Create a New Account" << endl;
    cout << LIST << ". List Clients and Accounts" << endl;
    cout << WITHDRAW << ". Withdraw Money" << endl;
    cout << DEPOSIT << ". Deposit Money" << endl;
    cout << QUIT << ". Quit the application" << endl;
    cout << endl << "------- Please enter choice: ";
}

void BankApp::createAccount() {
    int cltID;
    cout << "Client ID: ";
    cin >> cltID;
    int cltIdx = findClient(cltID);
    if (cltIdx == -1)
    {
        cout << "Client not found." << endl;
        cout << "Creating client record: " << endl;
        cltIdx = createClient(cltID);
    }
    char answer;
    cout << "Savings account? (y/n): ";
    cin >> answer;
    if(answer == 'y' && clientsInfo[cltIdx].getSavingsAccount())
    {
        cout << "Client already has a savings account" << endl;
        return;
    }

    if(answer == 'n' && clientsInfo[cltIdx].getAccount())
    {
        cout << "Client already has a basic account" << endl;
        return;
    }

    if (answer == 'y')
    {
        cout << "Minimum Balance: ";
        int minBal;
        cin >> minBal;
        cout << "Initial balance: ";
        int bal;
        cin >> bal;
        int accID = clientsInfo[cltIdx].getID() * 10 + 1;
        savingsInfo[nbrSavAcc] = SavingsAccount(accID, bal, minBal);
        clientsInfo[cltIdx].setSavingsAccount(&savingsInfo[nbrSavAcc++]);
    }
    else
    {
        cout << "Initial balance: ";
        int bal;
        cin >> bal;
        int accID = clientsInfo[cltIdx].getID() * 10;
        accountsInfo[nbrAcc] = Account(accID, bal);
        clientsInfo[cltIdx].setAccount(&accountsInfo[nbrAcc++]);
    }
}

int BankApp::findClient(int cltID) {
    for(int i = 0; i < nbrClients; i++)
    {
        if(clientsInfo[i].getID() == cltID)
            return i;
    }
    return -1;
}

int BankApp::createClient(int cltID) {
    cout << "First name: ";
    string first;
    cin >> first;
    cout << "Last name: ";
    string last;
    cin >> last;
    cout << "Phone number: ";
    string phone;
    cin >> phone;
    clientsInfo[nbrClients++] = Client(cltID, first, last, phone);
    return nbrClients-1; // index in array of new client
}

void BankApp::listAll() {
    for(int i = 0; i < nbrClients; i++)
    {
        cout << clientsInfo[i] << endl;
    }
}

void BankApp::withdraw() {
    cout << "Client ID: ";
    int cltID;
    cin >> cltID;
    int cltIdx = findClient(cltID);
    if(cltIdx == -1)
    {
        cout << "---- No records of this client ----- " << endl;
        return;
    }
    cout << "Savings account? (y/n) ";
    char answer;
    cin >> answer;
    if(answer == 'y' && clientsInfo[cltIdx].getSavingsAccount())
    {
        SavingsAccount* acc = clientsInfo[cltIdx].getSavingsAccount();
        cout << "Amount: ";
        double amount;
        cin >> amount;
        acc->withdraw(amount);
        return;
    }
    if(answer == 'n' && clientsInfo[cltIdx].getAccount())
    {
        Account* acc = clientsInfo[cltIdx].getAccount();
        cout << "Amount: ";
        double amount;
        cin >> amount;
        acc->withdraw(amount);
        return;
    }
    cout << "------ No account on record ----- " << endl;
}

void BankApp::deposit() {
    cout << "Client ID: ";
    int cltID;
    cin >> cltID;
    int cltIdx = findClient(cltID);
    if(cltIdx == -1)
    {
        cout << "---- No records of this client ----- " << endl;
        return;
    }
    cout << "Savings account? (y/n) ";
    char answer;
    cin >> answer;
    if(answer == 'y' && clientsInfo[cltIdx].getSavingsAccount())
    {
        SavingsAccount* acc = clientsInfo[cltIdx].getSavingsAccount();
        cout << "Amount: ";
        double amount;
        cin >> amount;
        acc->deposit(amount);
        return;
    }
    if(answer == 'n' && clientsInfo[cltIdx].getAccount())
    {
        Account* acc = clientsInfo[cltIdx].getAccount();
        cout << "Amount: ";
        double amount;
        cin >> amount;
        acc->deposit(amount);
        return;
    }
    cout << "------ No account on record ----- " << endl;

}
