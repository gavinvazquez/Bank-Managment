#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Account.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Customer{
    private:
        Account customerAcct;
        string username;
        string password;
        string FName;
        string LName;
        
    public:
    //Constructors
    Customer();
    Customer(string,string,string,string);

    //simply return the varibles
    Account &getCustomerAcct();
    string getUsername();
    string getPassword();
    string getFName();
    string getLName();

    //set values equal to and pass in values new = old;
    void setCustomerAcct(Account);
    void setUsername(string);
    void setPassword(string);
    void setFName(string);
    void setLNAme(string);
    
};

#endif 