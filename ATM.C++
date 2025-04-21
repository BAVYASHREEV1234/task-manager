#include<iostream>
#include<limits>

using namespace std;

class ATM{
private:
   int pin;
   double balance;

public:
   ATM():pin(1234),balance(10000.0){}
    
   void login(){
      int attempts=0;
      int enteredpin;

      while(attempts<3){
        cout<<"Enter your 4-digit PIN:";
        cin>>enteredpin;


        if(enteredpin==pin){
            cout<<"Login successfull:"<<endl;
            return;
        }
        else{
            attempts++;
            cout<<"incorrect PIN.Attempts left:"<<(3-attempts)<<endl;

        }
      }

        cout<<"Account locked due to too many incoorrect attempts"<<endl;
        exit(0);
        }
        void displayMenu(){
            int choice;

            do{
                cout<<"\n---ATM MainMenu---"<<endl;
                cout<<"1.CheckBalance"<<endl;
                cout<<"2.WidhdrawMoney"<<endl;
                cout<<"3.DepositMoney"<<endl;
                cout<<"4.Change PIN"<<endl;
                cout<<"5.Exit"<<endl;
                cout<<"Enter your choice:";
                cin>>choice;

                switch (choice){
                    case 1:
                       CheckBalance();
                       break;
                    case 2:
                       WidhdrawMoney();
                       break;
                    case 3:
                       DepositMoney();
                       break;
                    case 4:
                       ChangePIN();
                       break;
                    case 5:
                       cout<<"Thank you for using the ATM.Goodbye!"<<endl;
                       break;
                    default:
                       cout<<"Invalid choice.Please try again."<<endl;

                }
            }while(choice!=5);
             
        }
        void CheckBalance(){
            cout<<"Your current balance is Rs "<<balance<<endl;
        }
        void WidhdrawMoney(){
            double amount;
            cout<<"Enter amount to widhdraw: Rs";
            cin>>amount;

            if(amount>balance){
                cout<<"Insufficient balance"<<endl;

            }else{
                balance-=amount;
                cout<<"Widhdrawal successfull! New balance  Rs"<<balance<<endl;

            }
        }
        void  DepositMoney(){
            double amount;
            cout<<"Enter amount to deposit : RS.";
            cin>>amount;

            if(amount<=0){
                cout<<"Invalid deposit amount"<<endl;

            }else{
                balance+=amount;
                cout<<"Deposit successfull ! New balance: Rs."<<balance<<endl;
            }
        }
        void ChangePIN(){
            int newPin;
            cout<<"Enter new four-digit PIN:";
            cin>>newPin;

            if(newPin<1000||newPin>9999){
                cout<<"Invalid PIN .Please enter a four-digit number,"<<endl;

            }else{
                pin=newPin;
                cout<<"PIN changed successfully!"<<endl;

            }
        }
        };
        int  main(){
            ATM atm;
            atm.login();
            atm.displayMenu();
            return 0;
        }

        