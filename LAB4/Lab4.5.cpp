#include <iostream>
using namespace std;
class DynamicArray {
private:
    int* arr;     
    int capacity;  
    int length;    

public:
    DynamicArray(int size) : capacity(size), length(0) {
        arr = new int[capacity](); 
    }
	void push(int value) {
        if (length == capacity) { 
            int newCapacity = capacity * 2;
            int* newArr = new int[newCapacity]();
            for (int i = 0; i < length; i++) {
                newArr[i] = arr[i]; 
            }
            delete[] arr; 
            arr = newArr;
            capacity = newCapacity;
        }
        arr[length++] = value; 
    }
    int size() const {
        return length;
    }
	void display() const {
        cout << "Array: ";
        for (int i = 0; i < length; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~DynamicArray() {
        delete[] arr;
    }
};
int main() {
	cout<<"THE CODE IS WRITTEN BY MESUM ABBAS CT-238"<<endl;
    DynamicArray arr(3); 
	arr.push(5);
    arr.push(10);
    arr.push(15);
    arr.push(20); 
	cout << "Current Size: " << arr.size() << endl;
    arr.display();

    return 0;
}
