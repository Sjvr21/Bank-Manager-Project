#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <windows.h>
#include <vector>

using namespace std;

struct Account {   
    int accountNumber;
    string holderName;
    double balance;
};


vector<Account> accounts;

void addAccount() {

   
    Account newAccount;
    cout << "Enter new account number: ";
    cin >> newAccount.accountNumber;
    cout << "Enter holder's name: ";
    cin >> newAccount.holderName;
    cout << "Enter initial balance: ";
    cin >> newAccount.balance;
    accounts.push_back(newAccount);
    cout << "Account successfully added.\n";
    
}


void listAccounts() {
    cout << "List of All Accounts:\n";
    for (const auto& account : accounts) {
        cout << "Account Number: " << account.accountNumber
            << ", Holder: " << account.holderName
            << ", Balance: $" << account.balance << endl;
    }

}




int EnviarDinero(int& AccNumber, double& money, double& AccMoney) {
    char opcion = 'y';
    do {
    
        time_t tiempo = time(0);
        char* dateTime = ctime(&tiempo);

        ofstream transfers("transactions.txt", ios::app);  
        cout << "Enter the account number: ";               
        cin >> AccNumber;
        cout << "Enter the amount of money you want to transfer: ";
        cin >> money;

        if (money <= AccMoney && money > 0) {
            cout << "Transfer successful\n" << '\a';       
            transfers << "You transferred $" << money << " to account number: " << AccNumber << " on " << dateTime << endl;
            transfers.close();
            AccMoney -= money;
        }
        else {
            cout << "Your account doesn't have that money\n";
        }

        cout << "Do you want to make another transaction? (y/n): ";
        cin >> opcion;
        system("cls");

    } while (opcion != 'n');

    return AccMoney;
}


void AccStatement() {
    ifstream statement("transactions.txt");
    string line;

    cout << "Account Statements: \n";
    while (getline(statement, line)) {
        cout << line << endl;
    }
    statement.close();
}



void cambiarCredenciales(string& Username, string& password) {
    string currentUsername, currentPassword, newUsername, newPassword;

    cout << "Enter your current username: ";
    cin >> currentUsername;
    cout << "Enter your current password: ";
    cin >> currentPassword;

    

    if (currentUsername == Username && currentPassword == password) {
        cout << "Enter your new username: ";
        cin >> newUsername;
        cout << "Enter your new password: ";
        cin >> newPassword;

        ofstream NewUser("Username.txt");
        NewUser << newUsername;
                                    
        ofstream NewPass("Password.txt");
        NewPass << newPassword;

        NewPass.close();
        NewUser.close();

        Username = newUsername;
        password = newPassword;
        cout << "Username and password have been changed successfully.\n";
    }
    else {
        cout << "Incorrect username or password.\n";
    }
}

int main() {

    
    string Username, password, defPass = "Password", defUser = "Juancho";
    int opt = 0, AccNumber;
    double AccMoney = 188.78, money;
    
    


    string Pass;
    ifstream PasswordFile("Password.txt"); 
 while (getline(PasswordFile, Pass)){

    defPass = Pass;
  }
  PasswordFile.close();


    string User;
    ifstream UserFile("Username.txt"); 
 while (getline(UserFile, User)){

    defUser = User;
  }
  UserFile.close();


    
    cout << "Welcome to the Central Bank Account Software" << endl;
    cout << "Enter your Username: ";
    cin >> Username;

    cout << "Enter your password: ";
    cin >> password;
    system("cls");


   
    while (Username != defUser || password != defPass) {
        system("cls");
        cout << "Username or Password Incorrect\nPlease Try Again" << endl;
        cout << "Enter your Username: ";
        cin >> Username;
        cout << "Enter your password: ";
        cin >> password;
        system("cls");

    }

    do {
        
       
        cout << "Welcome " << Username << "!\n";
        cout << "Select An Option\n";
        cout << "1-View Account Balance\n";
        cout << "2-Deposit Money\n";
        cout << "3-Transfer Money\n";
        cout << "4-View Transfer Statements\n";
        cout << "5-Change Username and Password\n";
        cout << "6-Add New Account\n";
        cout << "7-List of Accounts\n";
        cout << "8-Exit\n";
        cin >> opt;


       
        switch (opt) {
        case 1:
            system("cls");
            cout << "############################\n";
            cout << "Your balance is: $" << AccMoney << endl;
            cout << "############################\n";
            break;
        case 2:
            system("cls");
            cout << "Enter the amount of money you want to deposit: ";
            cin >> money;
            if (money > 0) {
                AccMoney += money;
                cout << "Deposit done successfully\n";
            }
            break;
        case 3:
            system("cls");
            EnviarDinero(AccNumber, money, AccMoney);
            break;
        case 4:
            system("cls");
            AccStatement();
            break;
        case 5:
            system("cls");
            cambiarCredenciales(Username, password);

            break;
        case 6:
            addAccount();
            break;
        case 7:
            listAccounts();
            break;
        case 8:
            system("cls");
            cout << "Exiting...";
            break;
        default:
            system("cls");
            cout << "Invalid option, please try again.\n";
            break;
        }
    } while (opt != 8);  
    

    return 0;
}
