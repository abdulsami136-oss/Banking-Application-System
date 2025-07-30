#include <iostream>
#include <string>
using namespace std;

struct User {
    string name;
    string accountNumber;
    string password;
    double balance;};


void mainMenu(User users[], int &userCount, int loggedInIndex);
void transferFunds(User users[], int loggedInIndex);

int main() {
    User users[100];
    int userCount = 0;
    int loggedInIndex = -1;
    int choice;

    cout << "====> Welcome To Banking App <====" << endl;

    do {
        cout << "\n1. Log In";
        cout << "\n2. Sign Up";
        cout << "\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string enteredAccount, enteredPassword;
            cout << "\nEnter Account Number: ";
            cin >> enteredAccount;
            cout << "Enter Password: ";
            cin >> enteredPassword;

            bool loginSuccess = false;
            for (int i = 0; i < userCount; i++) {
                if (users[i].accountNumber == enteredAccount && users[i].password == enteredPassword) {
                    loggedInIndex = i;
                    loginSuccess = true;
                    break;
                }
            }

            if (loginSuccess) {
                cout << "\nLogin successful. Welcome, " << users[loggedInIndex].name << "!" << endl;
                mainMenu(users, userCount, loggedInIndex);
            } else {
                cout << "Invalid account number or password. Please try again." << endl;
            }
        } else if (choice == 2) {
            if (userCount < 100) {
                cout << "\nSign Up for a New Account:";
                cout << "\nEnter Name: ";
                cin >> users[userCount].name;
                cout << "Enter Account Number: ";
                cin >> users[userCount].accountNumber;
                cout << "Set a Password: ";
                cin >> users[userCount].password;
                cout << "Enter Initial Balance: ";
                cin >> users[userCount].balance;

                userCount++;
                cout << "Account created successfully! You can now log in." << endl;
            } else {
                cout << "User limit reached. Cannot create more accounts." << endl;
            }
        } else if (choice == 3) {
            cout << "Thank you for using the banking app. Goodbye!" << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}

void mainMenu(User users[], int &userCount, int loggedInIndex) {
    int option;

    do {
        cout << "\n==== Main Menu ====";
        cout << "\n1. Transfer Funds";
        cout << "\n2. View Account Details";
        cout << "\n3. Log Out\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
        case 1:
            transferFunds(users, loggedInIndex);
            break;
        case 2:
            cout << "\nAccount Details:";
            cout << "\nName: " << users[loggedInIndex].name;
            cout << "\nAccount Number: " << users[loggedInIndex].accountNumber;
            cout << "\nBalance: " << users[loggedInIndex].balance << endl;
            break;
        case 3:
            cout << "Logging out... Goodbye, " << users[loggedInIndex].name << "!" << endl;
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (option != 3);
}

void transferFunds(User users[], int loggedInIndex) {
    string receiverAccount;
    double amount;

    cout << "\n==== Transfer Funds ===="<<endl;
    cout << "Enter Receiver's Account Number: ";
    cin >> receiverAccount;
    cout << "Enter Amount to Transfer: ";
    cin >> amount;

    if (users[loggedInIndex].balance >= amount) {
        users[loggedInIndex].balance -= amount;
        cout << "Transaction successful!";
        cout << "\nUpdated Balance: " << users[loggedInIndex].balance << endl;
    } else {
        cout << "Insufficient balance. Transaction failed." << endl;
    }
}
