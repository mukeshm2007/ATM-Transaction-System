#include <iostream>
#include <string>
using namespace std;

int main()
{
    int pin = 1234, enteredPin;
    double balance = 1000;
    int choice;
    double amount;

    string history[10];   // Array to store transactions
    int count = 0;        // Number of transactions stored

    cout << "Enter PIN: ";
    cin >> enteredPin;

    // Check PIN
    if(enteredPin != pin)
    {
        cout << "Incorrect PIN";
        return 0;
    }

    do
    {
        cout << "\n--- ATM MENU ---\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Transaction History\n";
        cout << "5. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Balance: " << balance << endl;
                break;

            case 2:
                cout << "Enter deposit amount: ";
                cin >> amount;

                balance += amount;

                if(count < 10)
                {
                    history[count] = "Deposited " + to_string(amount);
                    count++;
                }

                cout << "Amount Deposited\n";
                break;

            case 3:
                cout << "Enter withdraw amount: ";
                cin >> amount;

                if(amount <= balance)
                {
                    balance -= amount;

                    if(count < 10)
                    {
                        history[count] = "Withdraw " + to_string(amount);
                        count++;
                    }

                    cout << "Please collect cash\n";
                }
                else
                {
                    cout << "Insufficient balance\n";
                }

                break;

            case 4:
                cout << "\nTransaction History:\n";

                for(int i = 0; i < count; i++)
                {
                    cout << history[i] << endl;
                }

                break;

            case 5:
                cout << "Thank you for using ATM\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while(choice != 5);

    return 0;
}
