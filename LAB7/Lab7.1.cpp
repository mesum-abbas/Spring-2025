#include <iostream>
using namespace std;

class IntMatrix {
private:
    int** data;
    int rows;
    int cols;

public:
    IntMatrix() : rows(1), cols(1) {
        data = new int*[1];
        data[0] = new int[1];
        data[0][0] = 0;
    }

    IntMatrix(int r, int c) : rows(r), cols(c) {
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = 0;
            }
        }
    }

    IntMatrix(const IntMatrix& other) : rows(other.rows), cols(other.cols) {
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    ~IntMatrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    IntMatrix& operator=(const IntMatrix& other) {
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

    IntMatrix operator+(const IntMatrix& other) {
        IntMatrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    IntMatrix operator-(const IntMatrix& other) {
        IntMatrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    IntMatrix operator*(const IntMatrix& other) {
        IntMatrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    int* operator[](int index) {
        return data[index];
    }

    const int* operator[](int index) const {
        return data[index];
    }

    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
	cout << "The code is written by MESUM ABBAS CT-238 " << endl;
    IntMatrix mat1(2, 3);
    mat1[0][0] = 1; mat1[0][1] = 2; mat1[0][2] = 3;
    mat1[1][0] = 4; mat1[1][1] = 5; mat1[1][2] = 6;

    IntMatrix mat2(2, 3);
    mat2[0][0] = 6; mat2[0][1] = 5; mat2[0][2] = 4;
    mat2[1][0] = 3; mat2[1][1] = 2; mat2[1][2] = 1;

    cout << "Matrix 1:" << endl;
    mat1.print();
    cout << "\nMatrix 2:" << endl;
    mat2.print();

    IntMatrix sum = mat1 + mat2;
    cout << "\nSum:" << endl;
    sum.print();

    IntMatrix diff = mat1 - mat2;
    cout << "\nDifference:" << endl;
    diff.print();

    IntMatrix mat3(3, 2);
    mat3[0][0] = 1; mat3[0][1] = 2;
    mat3[1][0] = 3; mat3[1][1] = 4;
    mat3[2][0] = 5; mat3[2][1] = 6;

    IntMatrix product = mat1 * mat3;
    cout << "\nProduct:" << endl;
    product.print();

    IntMatrix mat4 = mat1;
    cout << "\nCopied Matrix:" << endl;
    mat4.print();

    return 0;
}
