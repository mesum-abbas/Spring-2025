#include <iostream>
#include <cctype> 
using namespace std;

template <typename T>
class mycontainer {
private:
    T element;
public:
    mycontainer(T arg) : element(arg) {} 
    
    void increase() {
        element += 1;
    }
    
    T getValue() {
        return element;
    }
};
template <>
class mycontainer<char> {
private:
    char element;
public:
    mycontainer(char arg) : element(arg) {} 
    void uppercase() {
        if (islower(element)) {
            element = toupper(element);
        }
    }
    
    char getValue() {
        return element;
    }
};

int main() {
	cout << " The code is written by MESUM ABBAS CT-238" << endl;
    mycontainer<int> myint(5);
    cout << "Initial int value: " << myint.getValue() << endl;
    myint.increase();
    cout << "After increase(): " << myint.getValue() << endl << endl;
    
    mycontainer<double> mydouble(3.14);
    cout << "Initial double value: " << mydouble.getValue() << endl;
    mydouble.increase();
    cout << "After increase(): " << mydouble.getValue() << endl << endl;
    

    mycontainer<char> mychar('a');
    cout << "Initial char value: " << mychar.getValue() << endl;
    mychar.uppercase();  
    cout << "After uppercase(): " << mychar.getValue() << endl;
    
    return 0;
}
