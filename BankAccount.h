//
// Created by raind on 9/28/2026.
//

#ifndef OBJECT_CLASSES_LAB_BANKACCOUNT_H
#define OBJECT_CLASSES_LAB_BANKACCOUNT_H
#include <string>


class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;

public:
    BankAccount();
    BankAccount(std::string accountNumber, std::string accountHolderName, double balance);

    std::string getAccountNumber() const;
    std::string getAccountHolderName() const;
    double getBalance() const;

    void deposit(double amount);
    bool withdraw(double amount);
};



#endif //OBJECT_CLASSES_LAB_BANKACCOUNT_H
