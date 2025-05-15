#include <iostream>
using namespace std;

template <class T>
class Calculator {
private:
    T num1;
    T num2;

public:
    Calculator(T n1, T n2) {
        num1 = n1;
        num2 = n2;
    }

    void showNumbers() {
        cout << "First number: " << num1 << endl;
        cout << "Second number: " << num2 << endl;
    }

    T add() {
        return num1 + num2;
    }

    T subtract() {
        return num1 - num2;
    }

    T multiply() {
        return num1 * num2;
    }

    T divide() {
        if (num2 == 0) {
            cout << "Error: Cannot divide by zero!" << endl;
            return 0;
        }
        return num1 / num2;
    }
};

int main() {
	cout << " The code is written by MESUM ABBAS CT-238" << endl;
    Calculator<int> intCalc(10, 5);
    cout << "Integer Calculator:" << endl;
    intCalc.showNumbers();
    cout << "Sum: " << intCalc.add() << endl;
    cout << "Difference: " << intCalc.subtract() << endl;
    cout << "Product: " << intCalc.multiply() << endl;
    cout << "Quotient: " << intCalc.divide() << endl << endl;

    Calculator<double> doubleCalc(10.5, 2.5);
    cout << "Double Calculator:" << endl;
    doubleCalc.showNumbers();
    cout << "Sum: " << doubleCalc.add() << endl;
    cout << "Difference: " << doubleCalc.subtract() << endl;
    cout << "Product: " << doubleCalc.multiply() << endl;
    cout << "Quotient: " << doubleCalc.divide() << endl;

    return 0;
}
