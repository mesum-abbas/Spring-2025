#include <iostream>
using namespace std;

class Store {
protected:
    float total_bill;
public:
    Store(float bill) : total_bill(bill) {}
    virtual float calculateFinalBill() = 0;
    virtual ~Store() {}
};

class ImtiazStore : public Store {
public:
    ImtiazStore(float bill) : Store(bill) {}
    float calculateFinalBill() override {
        return total_bill * 0.93;
    }
};

class BinHashimStore : public Store {
public:
    BinHashimStore(float bill) : Store(bill) {}
    float calculateFinalBill() override {
        return total_bill * 0.95;
    }
};

int main() {
    float billAmount;
    cout << "Enter total bill amount: ";
    cin >> billAmount;

    ImtiazStore imtiaz(billAmount);
    BinHashimStore binhashim(billAmount);

    cout << "ImtiazStore final bill: " << imtiaz.calculateFinalBill() << endl;
    cout << "BinHashimStore final bill: " << binhashim.calculateFinalBill() << endl;

    return 0;
}
