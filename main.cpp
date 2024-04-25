
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int main(){

    int AccNumber, money, AccMoney = 10000;
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
        
        transfers << "You transferred $"<<money<<" to account number: "<<AccNumber<<" on "<<dateTime<<endl;
        transfers.close();

    }
     else{
      cout << "Your account doesn't have that money";

    }
    cout << endl; 
    cout << "Quieres continuar?";
    cin >> opcion;
    
    system("clear");


    
}

    

    return 0;
}



