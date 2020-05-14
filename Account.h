#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Account{
    private:
        int ID;
        double balance;

    public:
        static int count;
        Account();

        int getID();
        double &getBalance();
        void setBalance(double*);
};

#endif 

