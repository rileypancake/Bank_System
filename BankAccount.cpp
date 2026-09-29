//
// Created by raind on 9/28/2026.
//

#include "BankAccount.h"

BankAccount::BankAccount() {
    accountNumber = "";
    accountHolderName = "";
    balance = 0.0;
}

BankAccount::BankAccount(std::string accountNumber,
                         std::string accountHolderName,
                         double balance) {
    this->accountNumber = accountNumber;
    this->accountHolderName = accountHolderName;
    this->balance = balance;
}

std::string BankAccount::getAccountNumber() const
{
    return accountNumber;
}
std::string BankAccount::getAccountHolderName() const
{
    return accountHolderName;
}
double BankAccount::getBalance() const
{
    return balance;
}

void BankAccount::deposit(double amount)
{
    if (amount > 0)
    {
        balance += amount;
    }

}
bool BankAccount::withdraw(double amount)
{
    if (amount <= 0 || amount > balance)
    {
        return false;
    }

    balance -= amount;
    return true;
}
