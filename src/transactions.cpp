#include "transactions.h"
#include <iostream>
#include <iomanip>
using namespace std;

transactions::transactions()
{
    balance = 0.0;
}
transactions::~transactions()
{
   
}

void transactions::setCategory(string Newcategory)
{
    category = Newcategory;
}
string transactions::getCategory()
{
    return category;
}
void transactions::setBalance(double newBalance)
{
    balance = newBalance;
}
double transactions::getBalance()
{
    return balance;
}

void transactions::addTransaction(double amount, string type, string category, string date)
{
    Transaction t;
    t.amount = amount;
    t.type = type;
    t.category = category;
    t.date = date;
    transactionList.push_back(t);
}

void transactions::displayTransactions()
{
    if(transactionList.empty())
    {
        cout << "No transactions found." << endl;
        return;
    }

    cout << endl;
    cout << left
         << setw(12) << "Date"
         << setw(12) << "Category"
         << setw(20) << "Name"
         << setw(10) << "Amount" << endl;
    cout << string(54, '-') << endl; 

    for(const Transaction& t : transactionList)
    {
        cout << left
             << setw(12) << t.date
             << setw(12) << t.type
             << setw(20) << t.category
             << setw(10) << t.amount << endl;
    }
    cout << string(54, '-') << endl;
}