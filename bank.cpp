#include "Customer.h"
#include "Account.h"
#include "functions.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    vector<Customer>allCustomers;
    int transactionID = 0;
    int input;
    string loginName;
    string loginPassword;
    string first;
    string last;
    
    int option = 0;
    bool loopStop = false;
    while(loopStop != true){
        cout<<"\n\n\n\tMAIN MENU";
        cout<<"\n\n\t1. NEW ACCOUNT";
        cout<<"\n\n\t2. DEPOSIT AMOUNT";
        cout<<"\n\n\t3. WITHDRAW AMOUNT";
        cout<<"\n\n\t4. BALANCE ENQUIRY";
        cout<<"\n\n\t5. ALL ACCOUNT HOLDER LIST";
        cout<<"\n\n\t6. CLOSE AN ACCOUNT";
        cout<<"\n\n\t7. MODIFY AN ACCOUNT";
        cout<<"\n\n\t8. DISPLAY ALL TRANSACTIONS";
        cout<<"\n\n\t9. FIND TRANSACTION BY ACCOUNT ID";
        cout<<"\n\n\t10. FIND TRANSACTION BY TRANSACTION ID";
        cout<<"\n\n\t11. EXIT";
        cout<<"\n\n";
        cout<<"\n\n\tSelect Your Option: ";
        cin>>option;

        switch(option)
        {
        case 1:
            createProfile(allCustomers);
            break;

        case 2:
            depositAmount(allCustomers, transactionID);
            break;

        case 3:
            withdrawAmount(allCustomers);
            break;

        case 4:
            checkEnquiry(allCustomers);
            break;

        case 5:
            displayAccounts(allCustomers);
            break;

        case 6:
            closeAccount(allCustomers);
            break;

        case 7:
            editAccount(allCustomers);
            break;

        case 8:
            printLinkedList();
            break;

        case 9:
            cout<<"\n\tEnter the Account ID for the transactions you would like to display: ";
            cin>>input;
            findByAccountID(input);
            break;

        case 10:
            cout<<"\n\tEnter the Transaction ID for the transaction you would like to display: ";
            cin>>input;
            findByTransactionID(input);
            break;

        case 11:
            cout<<"Thank you for using the bank managment service!";
            loopStop = true;
            cout<<"\n\n";
            return 0;
            break;

        default:{
            break;
        }
      }
    }
    return 0;
}

