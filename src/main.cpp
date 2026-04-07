#include <iostream>
#include "transactions.h"
// #include <bits/stdc++.h>
//#include <ctime>

using namespace std;

int main() {
    bool flag = true;
    while (flag)
    {
        transactions t;
        cout << "----WELCOME TO COINLY----" << endl;
        cout << "1. Check Balance " << endl;
        cout << "2. Expenses Summary" << endl;
        cout << "3. Income Summary" << endl;
        cout << "4. Add Transaction" << endl;
        cout << "5. Exit" << endl;
        
        cout << "Please select an option: ";
        int option;
        cin >> option;
        switch (option)
        {
        case 1:
            /* code */
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            
            srand(time(0));
            t.setId(rand());
            cout << "Enter transaction type: "
                    << "1. Income "
                    << "2. Expense " << endl;    
            int type;
            cin >> type;
            if(type == 1)
            {
                t.setCategory("Income");
            }
            else if (type == 2)
            {
             
                t.setCategory("Expense");
            }
            break;
            
        case 5:
            flag = false;
            break;

        default:
            cout << "Invalid option!" << endl;
        }   
    }
    return 0;
}