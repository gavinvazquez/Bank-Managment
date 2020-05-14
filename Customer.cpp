#include "Customer.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

Customer::Customer(){
     cout<<"Constructor Ran For Customer";
};

Customer::Customer(string first,string last ,string user ,string pass){
     FName = first;
     LName = last;
     username = user;
     password = pass;
     customerAcct = Account();
};

//GETTERS
    Account &Customer::getCustomerAcct(){
         return customerAcct;
    };
    string Customer::getUsername(){
         return username;
    };
    string Customer::getPassword(){
         return password;
    };
    string Customer::getFName(){
         return FName;
    };
    string Customer::getLName(){
         return LName;
    };

//SETTERS old -> new
    void Customer::setCustomerAcct(Account newCustomerAcct){
         customerAcct = newCustomerAcct;
    };
    void Customer::setUsername(string newUsername){
         username = newUsername;
    };
    void Customer::setPassword(string newPassword){
         password = newPassword;
    };
    void Customer::setFName(string newFName){
         FName = newFName;
    };
    void Customer::setLNAme(string newLName){
         LName = newLName;
    };