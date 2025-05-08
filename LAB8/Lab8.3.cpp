#include <iostream>
using namespace std;

class Balance {
protected:
    double balance;

public:
    Balance() {
        balance = 0.0;
    }

    Balance(double initialBalance) {
        balance = initialBalance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    void checkBalance() {
        cout << "Current Balance: Rs. " << balance << endl;
    }
};

class InterestAccount : public Balance {
private:
    double interestRate;

public:
    InterestAccount() : Balance() {
        interestRate = 0.30; 
    }

    InterestAccount(double initialBalance) : Balance(initialBalance) {
        interestRate = 0.30;
    }

    void deposit(double amount) {
        double interest = amount * interestRate;
        Balance::deposit(amount + interest);
        cout << "Interest added: Rs. " << interest << endl;
    }
};

class ChargingAccount : public Balance {
private:
    double fee;

public:
    ChargingAccount() : Balance() {
        fee = 25.0; 
    }

    ChargingAccount(double initialBalance) : Balance(initialBalance) {
        fee = 25.0;
    }

    void withdraw(double amount) {
        if ((amount + fee) <= balance) {
            balance -= (amount + fee);
            cout << "Fee charged: Rs. " << fee << endl;
        } else {
            cout << "Insufficient balance including fee!" << endl;
        }
    }
};

class ACI {
public:
    void transfer(double amount, Balance& acc) {
        acc.deposit(amount);
    }

    void transfer(double amount, InterestAccount& acc) {
        acc.deposit(amount);
    }

    void transfer(double amount, ChargingAccount& acc) {
        acc.deposit(amount);
    }
};

int main() {
	cout << "The code is written by MESUM ABBAS CT-238" << endl;
    cout << "Testing Basic Account:" << endl;
    Balance basicAcc(1000);
    basicAcc.checkBalance();
    basicAcc.deposit(500);
    basicAcc.checkBalance();
    basicAcc.withdraw(200);
    basicAcc.checkBalance();
    cout << endl;

    cout << "Testing Interest Account:" << endl;
    InterestAccount interestAcc(1000);
    interestAcc.checkBalance();
    interestAcc.deposit(500);
    interestAcc.checkBalance();
    interestAcc.withdraw(200);
    interestAcc.checkBalance();
    cout << endl;
    
    cout << "Testing Charging Account:" << endl;
    ChargingAccount chargingAcc(1000);
    chargingAcc.checkBalance();
    chargingAcc.deposit(500);
    chargingAcc.checkBalance();
    chargingAcc.withdraw(200);
    chargingAcc.checkBalance();
    cout << endl;

    cout << "Testing Transfers:" << endl;
    ACI aci;
    
    Balance basicAcc2;
    InterestAccount interestAcc2;
    ChargingAccount chargingAcc2;
    
    aci.transfer(300, basicAcc2);
    basicAcc2.checkBalance();
    
    aci.transfer(300, interestAcc2);
    interestAcc2.checkBalance();
    
    aci.transfer(300, chargingAcc2);
    chargingAcc2.checkBalance();

    return 0;
}
