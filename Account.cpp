#include "Account.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int Account::count = 0;

Account::Account(){
    count++;
    ID = count;
    balance = 0;
}

int Account::getID(){
    return ID;
}

double &Account::getBalance(){
    return balance;
}

void Account::setBalance(double *bal){
    balance = *bal;
}


