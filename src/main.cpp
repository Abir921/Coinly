#include <iostream>
#include "transactions.h"
#include <string>
#include <ctime>
#include <fstream>
std::ofstream outfile;


bool fileExists(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}

using namespace std;

string getCurrentDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    string date = to_string(1900 + ltm->tm_year) + "-";
    date += to_string(1 + ltm->tm_mon) + "-";
    date += to_string(ltm->tm_mday);

    return date;
}
void displayMenu() {
    cout << endl;
    cout << "----WELCOME TO COINLY----" << endl;
    cout << "1. Add Transaction " << endl;
    cout << "2. View Transactions" << endl;
    cout << "3. Show Balance" << endl;
    cout << "4. Edit Transaction" << endl;
    cout << "5. Delete Transaction" << endl;
    cout << "6. Exit" << endl;
}

int main() {
    transactions t;
    bool flag = true;

    string output_file_path = "transactions.txt";
    
    
    std::ofstream appendfile(output_file_path, std::ios_base::app);

    while (flag)
    {
        displayMenu();
     
        int option;
        cout << "Please select an option: ";
        cin >> option;

        string name;
        double amount;
        double balance;
        //Takes user input from a set of options
        switch (option)
        {
        case 1:
            int category;
            cout << endl << "Enter transaction type: " << endl
                    << "1.Income "
                    << "2. Expense " << endl
                    << "(Enter 1 or 2): ";   

            cin >> category;
            if(category == 1)
            {
                t.setCategory("Income");
                cout << "What is the name of income? ";
                cin >> name;
            }
            else if (category == 2)
            {
             
                t.setCategory("Expense");
                cout << "What is the name of expense? " ;
                cin >> name;
            }
            else cout << "Invalid category!" << endl;


            cout << "Enter amount: ";
            cin >> amount;
            if(category == 2)
            {
                amount = -amount; // Make expenses negative
            }
            balance = amount + t.getBalance();
            t.setBalance(balance);

            t.addTransaction(amount, t.getCategory(), name, getCurrentDate());
            if(!fileExists(output_file_path))
            {
                outfile.open(output_file_path);
                outfile << getCurrentDate() << " | " << t.getCategory() << " | " << name << " | " << amount << endl;
            }
            else
            {
                appendfile << getCurrentDate() << " | " << t.getCategory() << " | " << name << " | " << amount << endl;
            }
            cout << "Transaction added successfully!" << endl; 
            break;
            
        case 2:
            /* View Transactions */
            t.displayTransactions();
            break;

        case 3:
        //Show balance
            cout << endl;
            cout << "YOUR BALANCE IS " << t.getBalance() << endl;
            break;
        
        case 4:
            t.displayTransactions();
            int editIndex;
            cout << "Enter the transaction number you want to edit: ";
            cin >> editIndex;
            t.editTransaction(editIndex);
            cout << "Transaction edited successfully!" << endl;
            break;

        case 5:
            t.displayTransactions();
            int deleteIndex;
            cout << "Enter the transaction number you want to delete: ";
            cin >> deleteIndex;
            t.deleteTransaction(deleteIndex);
            cout << "Transaction deleted successfully!" << endl;
            break;

        case 6:
            flag = false;
            break;

        default:
            cout << "Invalid option!" << endl;
            break;
        }
    }
    outfile.close();
    return 0;
}