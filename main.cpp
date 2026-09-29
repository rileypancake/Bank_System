#include <iostream>
#include <vector>
#include <limits>
#include "BankAccount.h"

int main() {
    std::vector<BankAccount> accounts;
    int choice = 0;

    while (choice != 5) {
        std::cout << "\n1. Create Account\n";
        std::cout << "2. Deposit\n";
        std::cout << "3. Withdraw\n";
        std::cout << "4. View Account\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number from 1 to 5.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1) {
            std::string accountNumber;
            std::string accountHolderName;
            double balance;

            std::cout << "Enter account number: ";
            std::cin >> accountNumber;

            bool duplicate = false;

            for (const BankAccount& account : accounts) {
                if (account.getAccountNumber() == accountNumber) {
                    duplicate = true;
                    break;
                }
            }

            if (duplicate) {
                std::cout << "An account with that number already exists.\n";
                continue;
            }

            std::cout << "Enter account holder name: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, accountHolderName);

            if (accountHolderName.empty()) {
                std::cout << "Account holder name cannot be empty.\n";
                continue;
            }

            std::cout << "Enter starting balance: ";

            if (!(std::cin >> balance)) {
                std::cout << "Invalid balance. Please enter a number.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            if (balance < 0) {
                std::cout << "Starting balance cannot be negative.\n";
                continue;
            }

            BankAccount newAccount(accountNumber, accountHolderName, balance);
            accounts.push_back(newAccount);

            std::cout << "Account created successfully!\n";
        }

        else if (choice == 2) {
            std::string accountNumber;
            double amount;

            std::cout << "Enter account number: ";
            std::cin >> accountNumber;

            bool found = false;

            for (BankAccount& account : accounts) {
                if (account.getAccountNumber() == accountNumber) {
                    found = true;

                    std::cout << "Enter deposit amount: ";

                    if (!(std::cin >> amount)) {
                        std::cout << "Invalid amount. Please enter a number.\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        break;
                    }

                    if (amount <= 0) {
                        std::cout << "Deposit amount must be greater than zero.\n";
                        break;
                    }

                    account.deposit(amount);

                    std::cout << "Deposit successful!\n";
                    std::cout << "New balance: $" << account.getBalance() << "\n";
                    break;
                }
            }

            if (!found) {
                std::cout << "Account not found.\n";
            }
        }

        else if (choice == 3) {
            std::string accountNumber;
            double amount;

            std::cout << "Enter account number: ";
            std::cin >> accountNumber;

            bool found = false;

            for (BankAccount& account : accounts) {
                if (account.getAccountNumber() == accountNumber) {
                    found = true;

                    std::cout << "Enter withdrawal amount: ";

                    if (!(std::cin >> amount)) {
                        std::cout << "Invalid amount. Please enter a number.\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        break;
                    }

                    if (account.withdraw(amount)) {
                        std::cout << "Withdrawal successful!\n";
                        std::cout << "New balance: $" << account.getBalance() << "\n";
                    } else {
                        std::cout << "Withdrawal failed. "
                                  << "Amount must be greater than zero and cannot exceed the balance.\n";
                    }

                    break;
                }
            }

            if (!found) {
                std::cout << "Account not found.\n";
            }
        }

        else if (choice == 4) {
            std::string accountNumber;

            std::cout << "Enter account number: ";
            std::cin >> accountNumber;

            bool found = false;

            for (const BankAccount& account : accounts) {
                if (account.getAccountNumber() == accountNumber) {
                    std::cout << "\nAccount Holder: "
                              << account.getAccountHolderName() << "\n";
                    std::cout << "Account Number: "
                              << account.getAccountNumber() << "\n";
                    std::cout << "Balance: $"
                              << account.getBalance() << "\n";

                    found = true;
                    break;
                }
            }

            if (!found) {
                std::cout << "Account not found.\n";
            }
        }

        else if (choice == 5) {
            std::cout << "Thank you for using the Bank Account Management System!\n";
        }

        else {
            std::cout << "Invalid choice. Please enter a number from 1 to 5.\n";
        }
    }

    return 0;
}