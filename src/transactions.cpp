#include "transactions.h"
#include <iostream>
#include <iomanip>
using namespace std;

transactions::transactions()
{
    balance = 0.0;
    num = 1;
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
         << setw(12) << "No."
         << setw(12) << "Date"
         << setw(12) << "Category"
         << setw(20) << "Name"
         << setw(10) << "Amount" << endl;
    cout << string(54, '-') << endl; 

    for(const Transaction& t : transactionList)
    {
        cout << left
             << setw(12) << num
             << setw(12) << t.date
             << setw(12) << t.type
             << setw(20) << t.category
             << setw(10) << t.amount << endl;
        num++;
        }
    cout << string(54, '-') << endl;
    
}

void transactions::editTransaction(int index)
{
   int i = index -1;

   if(i < 0 || i >= transactionList.size())
   {
        cout << "Invalid transaction number." << endl;
        return;
   }

   Transaction& t = transactionList[i];

   cout << "Editing transaction #" << index << ":" << endl;
   cout << "Current details:" << endl;
   cout << "Date: " << t.date << endl;
   cout << "Category: " << t.type << endl;
   cout << "Name: " << t.category << endl;
   cout << "Amount: " << t.amount << endl;

   if(t.type == "Income")
   {
    balance -= t.amount; // Subtract old amount from balance
   }
    else if(t.type == "Expense")
    {
     balance += t.amount; // Add old amount back to balance
    }

   cout << "Enter new category(1. Income 2. Expense): ";
   int cat;
   cin >> cat;
   (cat = 1) ? t.type = "Income" : t.type = "Expense";

   cout << "Enter new name: ";
    cin >> t.category;

    cout << "Enter new amount: ";
    cin >> t.amount;

    if(t.type == "Income")
    {
        balance += t.amount; // Add new amount to balance
    }
    else if(t.type == "Expense")
    {
        balance -= t.amount; // Subtract new amount from balance
    }
}
void transactions::deleteTransaction(int index)
{
    int i = index -1;
    if(i < 0 || i >= transactionList.size())
    {
        cout << "Invalid transaction number." << endl;
        return;
    }

    Transaction& t = transactionList[i];
    if(t.type == "Income")
    {
        balance -= t.amount;
    }
    else if(t.type == "Expense")
    {
        balance += t.amount;
    }
    
    cout << "Deleting transaction #" << index << ":" << endl;
    cout << t.date << " | " << t.type << " | " << t.category << " | " << t.amount << endl;

    transactionList.erase(transactionList.begin() + i);

}