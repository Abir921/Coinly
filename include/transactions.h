#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H
#include <string>
#include <vector>
using namespace std;

#pragma once

class transactions
{
private:
    //amount, type, category, date
    struct Transaction{
        double amount;
        string type;
        string category;
        string date;
    };
    double balance;
    vector<Transaction> transactionList;
    string category;

public:
    transactions();
    void setCategory(string Newcategory);
    string getCategory();

    void setBalance(double newBalance);
    double getBalance();
    
    void addTransaction(double amount, string type, string category, string date);
    void displayTransactions();
    ~transactions();
    
};
#endif