#include <iostream>
using namespace std;

int main() {
    bool flag = true;
    while (flag)
    {
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
            
        case 2:
            /* code */
            
        case 3:
            /* code */
            
        case 4:
            /* code */
            
        case 5:
            flag = false;
            break;

        default:
            cout << "Invalid option!" << endl;
        }   
    }
    return 0;
}