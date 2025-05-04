#include <iostream>
using namespace std;

class Matrix {
private:
    int** data;
    int rows;
    int cols;

public:
    Matrix() : rows(1), cols(1) {
        data = new int*[1];
        data[0] = new int[1];
        data[0][0] = 0;
    }

    Matrix(int r, int c) : rows(r), cols(c) {
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = 0;
            }
        }
    }

    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    Matrix& operator=(const Matrix& other) {
        if (this == &other) return *this;

        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;

        rows = other.rows;
        cols = other.cols;
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }
        }
        return *this;
    }

    bool searchMatrix(int target) const {
        int left = 0;
        int right = rows * cols - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int row = mid / cols;
            int col = mid % cols;
            int midValue = data[row][col];
            
            if (midValue == target) {
                return true;
            } else if (midValue < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }

    void setValues(const initializer_list<initializer_list<int>>& values) {
        int i = 0, j = 0;
        for (const auto& row : values) {
            j = 0;
            for (int val : row) {
                data[i][j++] = val;
            }
            i++;
        }
    }

    int* operator[](int index) {
        return data[index];
    }

    const int* operator[](int index) const {
        return data[index];
    }
};

int main() {
    Matrix mat(3, 4);
    mat.setValues({
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    });

    int target1 = 3;
    cout << "Searching for " << target1 << ": " << (mat.searchMatrix(target1) ? "Found" : "Not found") << endl;

    int target2 = 13;
    cout << "Searching for " << target2 << ": " << (mat.searchMatrix(target2) ? "Found" : "Not found") << endl;

    int target3 = 60;
    cout << "Searching for " << target3 << ": " << (mat.searchMatrix(target3) ? "Found" : "Not found") << endl;

    return 0;
}
