/* 
 * File:   main.cpp
 * Author: dvdemon
 *
 * Created on July 18, 2015, 4:31 PM
 */

#include <cstdlib>
#include <iostream>

class Account {
protected:
    int _balance;
    friend class Checking;
public:

    Account() {
        std::cout << "Constructor account" << std::endl;
    };

    int getBalance() {
        return _balance;
    }

    //*
    Account & operator=(Account &other)
    {
            std::cout << "Assign Account =" << std::endl;
            _balance = other._balance;
            return *this;
    }
    //*/
};

class Checking : public Account {
private:
    int _fOverdraftProtect;
public:

    Checking(int balance, int fOverdraftProtect) {
        std::cout << "Constructor Checking" << std::endl;
        _balance = balance;
        _fOverdraftProtect = fOverdraftProtect;
    }

    //*

    Checking & operator=(Account &other) {
        std::cout << "Assign Checking" << std::endl;
        _balance = other._balance;
        _fOverdraftProtect = 0;
        return *this;
    }
    //*/
};

int main(int argc, char** argv) {
    Checking checking(1000, 1);

    //std::cout << "Operations with account" << std::endl;
    Account account;
    account = checking; 
    //std::cout << "Account balance = " << account.getBalance() << std::endl;

    checking = account;

    //std::cout << "Checking balance = " << checking.getBalance() << std::endl;

    return 0;
}

