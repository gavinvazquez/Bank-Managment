#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "Customer.h"
#include "Account.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct Node{
    Node *next;
    double transaction;
    int accountID;
    int transactionID;  

    Node(Node * n, int ID, int acctID, double trans){
        next = n;
        accountID = acctID;
        transaction = trans;
        transactionID = ID;
    }
};


//LINKED LIST FUNCTIONS
bool isEmpty();
void addToList(double amount, int acctID, int *ID);
int transactionIDfunc(int &IDtracker);
void printLinkedList();
void findByAccountID(int input);
void findByTransactionID(int input);

//MENU FUNCTIONS
void createProfile(vector<Customer> &allCustomers);
void displayAccounts(vector<Customer>allCustomers);
void depositAmount(vector<Customer> &allCustomers,int trans);
void withdrawAmount(vector<Customer> &allCustomers);
void checkEnquiry(vector<Customer>&allCustomers);
void closeAccount(vector<Customer>&allCustomers);
void editAccount(vector<Customer>&allCustomers);
#endif