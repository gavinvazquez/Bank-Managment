#include "Customer.h"
#include "Account.h"
#include "functions.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//LINKED LIST
//-------------------------------------------------------------------------------------


bool isEmpty(){
    if(!head)
        return true;
    return false;
};


void addToList(double amount, int acctID, int ID){
head = new Node(head,ID,acctID,amount);
cout<<head->transaction;
cout<<"WORKED";
};


int transactionIDfunc(int &IDtracker){
    IDtracker = IDtracker + 1;
    return IDtracker;
};


//remove?

void printLinkedList(){
    for(Node* temp = head; temp; temp = temp->next){
        cout<<"\n\nTransaction Amount:"<<temp->transaction;
    }
}
//find by account ID and trabsation ID



//MENU FUNCTIONS
//-------------------------------------------------------------------------------------
void createProfile(vector<Customer> &allCustomers){
        system("clear");
        string loginName;
        string loginPassword;
        string first;
        string last;

        cout<<"\n\tFirst Name: ";
        cin>>first;
        cout<<"\n\tLast Name: ";
        cin>>last;
        cout<<"\n\tUsername: ";
        cin>>loginName;
        cout<<"\n\tPassword: ";
        cin>>loginPassword;

        Customer newCustomer(first,last,loginName,
        loginPassword);

        allCustomers.push_back(newCustomer);
       system("clear");
}

void displayAccounts(vector<Customer>allCustomers){
    system("clear");
    for (int i = 0; i < allCustomers.size(); i++)
    {
        cout<<"\t\n";
        cout<<allCustomers[i].getFName()<<" "<<allCustomers[i].getLName()<<"'s Account";
        cout<<"\t\n";
        cout<<"Account ID: "<<allCustomers[i].getCustomerAcct().getID();
        cout<<"\t\n";
        cout<<"Current Balance: $"<<allCustomers[i].getCustomerAcct().getBalance();
        cout<<"\n------------------------\n\t\n";
    }
}

void depositAmount(vector<Customer> &allCustomers,int trans){
   string bankerInput;
   bool foundUser;
   double deposit;
   double newAmount;

   system("clear");
   cout<<"\t\nWhich user's account would you like to deposit to?\n\n";
   cout<<"\tIf you would like to exit to the menu enter: EXIT\n\n";
   cout<<"\t\nUsername: ";
   cin>>bankerInput;
   system("clear");

    if(bankerInput == "EXIT"){
        return;
    }

   for (int i = 0; i < allCustomers.size(); i++)
   {
       if(allCustomers[i].getUsername() == bankerInput ){
        system("clear");
        cout<<"\t\n\n"<<"Account ID: "<<allCustomers[i].getCustomerAcct().getID();
        cout<<"\t\n"<<"Current Balance: $"<<allCustomers[i].getCustomerAcct().getBalance()<<"\n\n";
        cout<<"\t\nHow much would you like to deposit to this account?\n\n"<<"$";
        cin>>deposit;

        newAmount = allCustomers[i].getCustomerAcct().getBalance() + deposit;
        allCustomers[i].getCustomerAcct().setBalance(&newAmount);
        system("clear");
        cout<<"\t\n\n Done!";
        addToList(deposit,allCustomers[i].getCustomerAcct().getID(),transactionIDfunc(trans));
        foundUser = true;
       }
   }
   if(foundUser == false){
    cout<<"Sorry, That Username doesnt exist. Please try again.";
    depositAmount(allCustomers,trans);
   }
}

void withdrawAmount(vector<Customer> &allCustomers){
   string bankerInput;
   bool foundUser;
   double withdraw;
   double newAmount;

   system("clear");
   cout<<"\t\nWhich user's account would you like to withdraw from?\n\n";
   cout<<"\tIf you would like to exit to the menu enter: EXIT\n\n";
   cout<<"\t\nUsername: ";
   cin>>bankerInput;
   system("clear");

    if(bankerInput == "EXIT"){
        return;
    }

   for (int i = 0; i < allCustomers.size(); i++)
   {
       if(allCustomers[i].getUsername() == bankerInput ){
        system("clear");
        cout<<"\t\n\n"<<"Account ID: "<<allCustomers[i].getCustomerAcct().getID();
        cout<<"\t\n"<<"Current Balance: $"<<allCustomers[i].getCustomerAcct().getBalance()<<"\n\n";
        cout<<"\t\nHow much would you like to withdraw from this account?\n\n"<<"$";
        cin>>withdraw;

        newAmount = allCustomers[i].getCustomerAcct().getBalance() - withdraw;
        allCustomers[i].getCustomerAcct().setBalance(&newAmount);
        
        cout<<"\t\n\n Done!";
        foundUser = true;
       }
   }
   if(foundUser == false){
    cout<<"Sorry, That Username doesnt exist. Please try again.";
    withdrawAmount(allCustomers);
   }
}

void checkEnquiry(vector<Customer>&allCustomers){
   string bankerInput;
   bool foundUser;
   system("clear");
   cout<<"\t\nWhich user's account's balance would you like to view?\n\n";
   cout<<"\tIf you would like to exit to the menu enter: EXIT\n\n";
   cout<<"\t\nUsername: ";
   cin>>bankerInput;
   system("clear");

    if(bankerInput == "EXIT"){
        return;
    }

   for (int i = 0; i < allCustomers.size(); i++)
   {
       if(allCustomers[i].getUsername() == bankerInput ){
        system("clear");
        cout<<"\t\n";
        cout<<allCustomers[i].getFName()<<" "<<allCustomers[i].getLName()<<"'s Account";
        cout<<"\t\n\n"<<"Account ID: "<<allCustomers[i].getCustomerAcct().getID();
        cout<<"\t\n"<<"Current Balance: $"<<allCustomers[i].getCustomerAcct().getBalance()<<"\n\n";
        foundUser = true;
       }
       if(foundUser == false){
        cout<<"Sorry, That Username doesnt exist. Please try again.";
        checkEnquiry(allCustomers);

        }
   }
}

void closeAccount(vector<Customer>&allCustomers){
   string bankerInput;
   bool foundUser;

   system("clear");
   cout<<"\t\nWhich user's account's would you like to delete?\n\n";
   cout<<"\tIf you would like to exit to the menu enter: EXIT\n\n";
   cout<<"\t\nUsername: ";
   cin>>bankerInput;
   system("clear");
    
    if(bankerInput == "EXIT"){
        return;
    }

   for (int i = 0; i < allCustomers.size(); i++)
   {
       if(allCustomers[i].getUsername() == bankerInput ){
        system("clear");
        allCustomers.erase(allCustomers.begin()+i);
        foundUser = true;
       }
       if(foundUser == false){
        cout<<"Sorry, That Username doesnt exist. Please try again.";
        closeAccount(allCustomers);

        }
   }
}

void editAccount(vector<Customer>&allCustomers){
   string bankerInput;
   bool foundUser;

   system("clear");
   cout<<"\t\nWhich user's account's would you like to edit?\n\n";
   cout<<"\tIf you would like to exit to the menu enter: EXIT\n\n";
   cout<<"\t\nUsername: ";
   cin>>bankerInput;
   system("clear");

    if(bankerInput == "EXIT"){
        return;
    }

   for (int i = 0; i < allCustomers.size(); i++)
   {
       if(allCustomers[i].getUsername() == bankerInput ){
        system("clear");
        int menuChoice;
        string editUser, editPass, editFirst, editLast;

        foundUser = true;
        cout<<"\n\tMAIN MENU";
        cout<<"\n\n\t1. Username";
        cout<<"\n\n\t2. Password";
        cout<<"\n\n\t3. First Name";
        cout<<"\n\n\t4. Last Name";
        cout<<"\n\n\t5. All Info";
        cin>>menuChoice;
         switch(menuChoice)
        {
        case 1:
            cout<<"\n\n\tNew Username: ";
            cin>>editUser;
            allCustomers[i].setUsername(editUser);
            break;
        case 2:
            cout<<"\n\n\tNew Password: ";
            cin>>editPass;
            allCustomers[i].setPassword(editPass);
            break;
        case 3:
            cout<<"\n\n\tNew First Name: ";
            cin>>editFirst;
            allCustomers[i].setFName(editFirst);
            break;
        case 4:
            cout<<"\n\n\tNew Last Name: ";
            cin>>editLast;
            allCustomers[i].setLNAme(editLast);
            break;
        case 5:
            cout<<"\n\n\tNew Username: ";
            cin>>editUser;
            allCustomers[i].setUsername(editUser);
            cout<<"\n\n\tNew Password: ";
            cin>>editPass;
            allCustomers[i].setPassword(editPass);
            cout<<"\n\n\tNew First Name: ";
            cin>>editFirst;
            allCustomers[i].setFName(editFirst);
            cout<<"\n\n\tNew Last Name: ";
            cin>>editLast;
            allCustomers[i].setLNAme(editLast);
            break;
        default:{
            break;
         }
        }
       }
       else{
           foundUser = false;
       }
       if(foundUser == false){
        cout<<"Sorry, That Username doesnt exist. Please try again.";
        editAccount(allCustomers);
        }
    }
}