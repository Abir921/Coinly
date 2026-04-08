#include <iostream>
#include "transactions.h"

using namespace std;

int main() {
    bool flag = true;
    while (flag)
    {
        transactions t;
        cout << endl;
        cout << "----WELCOME TO COINLY----" << endl;
        cout << "1. Add Transaction " << endl;
        cout << "2. View Transactions" << endl;
        cout << "3. Show Balance" << endl;
        cout << "4. Exit" << endl;
        
        cout << "Please select an option: ";
        int option;
        cin >> option;

        //Takes user input from a set of options
        switch (option)
        {
        case 1:
            cout << "Enter transaction type: "
                    << "1. Income "
                    << "2. Expense " << endl;    
            int category;
            cin >> category;
            if(category == 1)
            {
                t.setCategory("Income");
            }
            else if (category == 2)
            {
             
                t.setCategory("Expense");
            }
            cout << "What is the type of expense/income? " << endl;
           
            cout << "Enter amount: ";
            double amount;
            cin >> amount;
            t.setBalance(amount);

            break;
            
        case 2:
            /* code */
            break;
        case 3:
            cout << endl;
            cout << "Your balance is: " << t.getBalance() << endl;
            break;
        case 4:
            flag = false;
            break;

        default:
            cout << "Invalid option!" << endl;
            break;
        }   
    }
    return 0;
}