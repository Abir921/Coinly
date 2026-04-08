#include "transactions.h"
using namespace std;

transactions::transactions()
{
    
}
transactions::~transactions()
{
    
}
void transactions::setCategory(string Newcategory)
{
    Transaction* newTransaction = new Transaction();
    newTransaction->category = Newcategory;
}
string transactions::getCategory()
{
    Transaction* newTransaction = new Transaction();   
    return newTransaction->category;
}
void transactions::setBalance(double newBalance)
{
    balance = newBalance;
}
double transactions::getBalance()
{
    return balance;
}