#include <iostream>
using namespace std;

template <typename T1, typename T2>
void swapValues(T1 &a, T2 &b) {
    T1 temp = a;
    a = static_cast<T1>(b);  
    b = static_cast<T2>(temp); 
}

int main() {
    cout << " The code is written by MESUM ABBAS CT-238" << endl;
    int num1 = 5, num2 = 10;
    cout << "Before swap (int, int): " << num1 << " " << num2 << endl;
    swapValues(num1, num2);
    cout << "After swap (int, int): " << num1 << " " << num2 << endl << endl;
    
    double d = 3.14;
    float f = 2.71f;
    cout << "Before swap (double, float): " << d << " " << f << endl;
    swapValues(d, f);
    cout << "After swap (double, float): " << d << " " << f << endl << endl;
    
   
    return 0;
}
