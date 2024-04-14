#include <iostream>
using namespace std;

const int n = 3;

class Matrix {
private:
    int m[n][n];
public:
    Matrix() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                m[i][j] = 0;
            }
        }
    }

    Matrix(int (&input)[n][n]) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                m[i][j] = input[i][j];
            }
        }
    }

    Matrix operator+(Matrix& other) {
        Matrix result;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                result.m[i][j] = m[i][j] + other.m[i][j];
            }
        }
        return result;
    }

    void print() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int m1[n][n] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int m2[n][n] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    Matrix obj1(m1);
    Matrix obj2(m2);

    Matrix obj3 = obj1 + obj2;

    cout << "Sum of matrices:" << endl;
    obj3.print();

    return 0;
}
