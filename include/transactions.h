#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H
#include <string>
using namespace std;


#pragma once

class transactions
{
private:
    int id;
    double amount;
    string category;

public:
    transactions();
    void setId(int Newid);
    int getId();

    void setCategory(string Newcategory);
    string getCategory();
    ~transactions();
    
};
#endif