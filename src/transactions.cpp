#include "transactions.h"
using namespace std;
transactions::transactions()
{
    id = 0;
    amount = 0.0;
}
void transactions::setId(int Newid)
{
    id = id;
}
int transactions::getId()
{
    return id;
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