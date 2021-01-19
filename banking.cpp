#include<iostream>
using namespace std;

class Bank {

    int acc_no, balance;
    char name[30];
     

    public:

        void openAccount();

        void showAccount() {
            cout << "\n\nAccount Number: " << acc_no << endl;
            cout << "Name: " << name << endl;
            cout << "Balance: " << balance << endl;
        }

        void deposit() {
            long amt;
            cout << "Enter Amount you want to Deposit: ";
            cin >> amt;
            balance += amt;
        }

        void withdraw() {
            long amt;
            cout << "Enter Amount you want to Withdraw: ";
            cin >> amt;
            if(amt <= balance) {
                balance -= amt;
            }
            else 
                cout << "Balance is less";
        }

        int searchAccount(int);
};

void Bank :: openAccount() {
    cout << "Enter Account Number: ";
    cin >> acc_no;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Balance: ";
    cin >> balance;
}

int Bank :: searchAccount(int a) {
    if(acc_no == a){
        showAccount();
        return 1;
    }
    return 0;
}

int main()
{
    Bank account[3];

    int found = 0, a, ch;

    for(int i = 0; i <= 2; i++) {
        account[i].openAccount();
    }

    do {

        cout << "\n\n1. Display All\n2. Display By Account Number\n3. Deposit\n4. Withdraw\n5. Exit" << endl;

        cout << "\n\nEnter Your Choice: ";
        cin >> ch;

        switch(ch) {
            case 1:
                for(int i = 0; i <= 2; i++) {
                    account[i].showAccount();
                }
                break;

            case 2:
                cout << "\n\nEnter Account Number: ";
                cin >> a;
                for(int i = 0; i <= 2; i++) {
                    found = account[i].searchAccount(a);
                    if(found == 1) {
                        break;
                    }
                }
                if(found != 1)
                    cout << "Record Not Found";
                break;

            case 3:
                cout << "\n\nEnter Account Number to Deposit: ";
                cin >> a;
                for(int i = 0; i <= 2; i++) {
                    found = account[i].searchAccount(a);
                    if(found == 1){
                        account[i].deposit();
                        break;
                    }
                }
                if(found != 1)
                    cout << "Record Not Found";
                break;

            case 4:
                cout << "\n\nEnter Account Number to Withdraw: ";
                cin >> a;
                for(int i = 0; i<= 2; i++) {
                    found = account[i].searchAccount(a);
                    if(found){
                        account[i].withdraw();
                        break;
                    }
                }
                if(found != 1)
                    cout << "Record Not Found";
                break;

            case 5:
                cout << "\n\nHave a nice day";
                break;

            default: 
                cout << "\n\nSorry.. Try Again!!";
        };

    }while(ch != 5);

    return 0;
}