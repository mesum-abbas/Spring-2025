#include <iostream>
#include <vector>
using namespace std;

class ArrayMultiplier {
public:
    virtual void calculate() = 0;
    virtual ~ArrayMultiplier() {}
};

class ArrayMultiplier1D : public ArrayMultiplier {
private:
    vector<int> array;
    int multiplier;
    vector<int> result;
    
public:
    ArrayMultiplier1D(const vector<int>& arr, int mult) : array(arr), multiplier(mult) {
        result.resize(array.size());
    }
    
    void calculate() override {
        cout << "Performing 1D array multiplication..." << endl;
        for (size_t i = 0; i < array.size(); i++) {
            result[i] = array[i] * multiplier;
        }
    }
    
    void displayResult() {
        cout << "Original array: ";
        for (int num : array) {
            cout << num << " ";
        }
        cout << endl;
        
        cout << "Multiplier: " << multiplier << endl;
        
        cout << "Result array: ";
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }
};

class ArrayMultiplier2D : public ArrayMultiplier {
private:
    vector<vector<int>> array;
    int multiplier;
    vector<vector<int>> result;
    
public:
    ArrayMultiplier2D(const vector<vector<int>>& arr, int mult) : array(arr), multiplier(mult) {
        result.resize(array.size());
        for (size_t i = 0; i < array.size(); i++) {
            result[i].resize(array[i].size());
        }
    }
    
    void calculate() override {
        cout << "Performing 2D array multiplication..." << endl;
        for (size_t i = 0; i < array.size(); i++) {
            for (size_t j = 0; j < array[i].size(); j++) {
                result[i][j] = array[i][j] * multiplier;
            }
        }
    }
    
    void displayResult() {
        cout << "Original 2D array:" << endl;
        for (const auto& row : array) {
            for (int num : row) {
                cout << num << " ";
            }
            cout << endl;
        }
        
        cout << "Multiplier: " << multiplier << endl;
        
        cout << "Result 2D array:" << endl;
        for (const auto& row : result) {
            for (int num : row) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    vector<int> arr1D = {1, 2, 3, 4, 5};
    ArrayMultiplier1D multiplier1D(arr1D, 3);
    
    multiplier1D.calculate();
    multiplier1D.displayResult();
    
    
    vector<vector<int>> arr2D = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    ArrayMultiplier2D multiplier2D(arr2D, 2);
    
    multiplier2D.calculate();
    multiplier2D.displayResult();
    
    return 0;
}
