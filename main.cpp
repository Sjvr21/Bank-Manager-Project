#include <iostream>
#include <fstream>
#include <ctime>
#include <string>


using namespace std;

int EnviarDinero(int AccNumber, int  money, int AccMoney){

    
char opcion;

while(opcion != 'n'){

    time_t now = time(0);
   
   char* dateTime = ctime(&now);


    ofstream transfers("transactions.txt", ios::app);
    

    
    cout << "Enter the account number: ";
    cin >> AccNumber;

    cout << "Enter the ammount of money you want to transfer: ";
    cin >> money;

    if(money <= AccMoney){
        
         cout << "Transfer sucessful";
        cout << '\a';
        transfers << "You transferred $"<<money<<" to account number: "<<AccNumber<<" on "<<dateTime<<endl;
        transfers.close();
        AccMoney = AccMoney - money;
    }
     else{
      cout << "Your account doesn't have that money";

    }
    cout << endl; 
    cout << "Quieres continuar?";
    cin >> opcion;
    
    system("clear");

    return AccMoney;

}
}

void AccStatement(){
    string lista;
    ifstream statement("transactions.txt");

 cout << "Account Statements: \n";  
 while (getline(statement, lista)){

    //Output the text from the file 
    cout << lista<<endl;
  }
  

  //Close the file
  statement.close();

}

int main(){



    string Username, password;
    int opt;
    int AccNumber;
    double AccMoney, money;

    //El loop se repetira hasta que el username y password sean los correctos

    while(Username != "User12" & password != "Password"){

    cout << "Welcome to the Central Bank Account Software"<<endl;
    cout << "Enter your Username: "; // Username "User12"
    cin >> Username;

    cout << endl;

    cout << "Enter your password: "; // Password "Password"
    cin >> password;

    if(Username == "User12" & password == "Password"){

    AccMoney = 188.78;

    while(opt != 5){

       
    cout << "Welcome "<<Username<<"!\n";   
    cout << "Select A Option\n";
    cout <<"1-View Account Balance\n";
    cout <<"2-Deposit Money\n";
    cout <<"3-Transfer Money\n";
    cout <<"4-View Transfer Statements\n";
    cout <<"5-EXIT\n";
    cin >> opt;
    
    switch (opt)
    {
    case 1:
        //Account balance code
        cout << "############################\n";
        cout << "Your balance is : $"<<AccMoney<<endl;
        cout << "############################\n";
        break;
    
    case 2:
        // Deposit Money Code
        cout << "Enter the ammount of money you want to deposit: ";

        cin >> money;

        if(money > 0){
        cout <<endl;
        AccMoney = AccMoney + money;
        cout << "Deposit done sucessfuly";

        }

        break;

    case 3:
        EnviarDinero(AccNumber, money, AccMoney);
        cout << endl;
        AccMoney = EnviarDinero(AccNumber,money,AccMoney);
        break;

    case 4:

        AccStatement();
        break;

    case 5:
        system("clear");
        cout << "Exiting...";
        break;
        
    default:

    system("clear");
    cout << "***********************************************"<<endl;
    cout << "El numero entrado es incorrecto"<<endl;
    cout << "Intentalo de nuevo"<<endl;
    cout << "***********************************************"<<endl;
        break;
        
    }


    }



    } else {
        
        //Esto si eres de windows tendrias que cambiarlo a "clr"
        system("clear");
        cout << "***********************************************"<<endl;
        cout << "Username or Password Incorrect"<<endl;
        cout << "Please Try Again"<<endl;
        cout << "***********************************************"<<endl;

    }


    }
return 0;

}

