/*
class Class_Name
{
 // declaration(s);
}
*/

// Class Member Access Modifiers: public, private and protected


#include <iostream>
#include <string>
#include <vector>

class Player {
private:
     // Attributes
     std::string name = "Player name";
     int health = 100;
     int xp = 3;
public:
     // Methods
     void talk(std::string txt) {std::cout << name << " says " << txt << std::endl;}
     bool is_dead(); // function prototypes
};

class Account {
private:
    // Attributes
    std::string name = "Account Name";
    double balance;
public:
    // methods
//    bool deposite(double bal) {balance += bal; std::cout << "In deposit" << std::endl; return 0;}
//    bool withdraw(double bal) {balance -= bal; std::cout << "In withdraw" << std::endl; return 0;}
    void set_balance(double bal);
    double get_balance() {return balance;};

    bool withdraw(double bal);
    bool deposite(double bal);

    void set_name(std::string);
    void get_name(std::string n) {std::cout << "Account name: " << n << std::endl;}
};

void Account::set_balance(double bal) {
    balance = bal;
}

bool Account::withdraw(double bal) {
    if (balance - bal >= 0) {
        balance -= bal;
        return 1;
    }
    else {
        return 0;
    }
}

bool Account::deposite(double bal) {
    balance += bal;
    return 1;
}

void Account::set_name(std::string n) {
    name = n;
}

int main () {
//    Player x;
//    x.name = "Name x"; // Error this attribute is private.
//    x.health = 100;
//    x.xp = 12;
//    x.talk("Hi");

//    Account x_account;
//    x_account.name = "Account X";
//    x_account.balance = 5000.0;
//
//    x_account.deposite(1000.0);
//    x_account.withdraw(100.0);

//    Player *enemy = new Player;
//    (*enemy).name = "Enemy";
//    (*enemy).health = 100;
//    enemy -> xp = 15;
//    enemy -> talk("I will destroy you!");


    Account account_test;
    account_test.set_name("Test account");
    account_test.set_balance(1000);

    if (account_test.deposite(200)) {
        std::cout << "Deposit OK" << std::endl;
    } else {
        std::cout << "Deposit not allowed" << std::endl;
    }

    if (account_test.withdraw(1500)) {
        std::cout << "Withdrawal OK" << std::endl;
    } else {
        std::cout << "Not sufficient funds" << std::endl;
    }
    return 0;
}