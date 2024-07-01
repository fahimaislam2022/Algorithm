#include <bits/stdc++.h>
using namespace std;

class Matrix {
private:
    int **matrix;
    int rows;
    int cols;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        matrix = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new int[cols];
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void fillFromFile(ifstream &fin) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                fin >> matrix[i][j];
            }
        }
    }

    void print() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void multiply(const Matrix &other, Matrix &result) const {
        if (cols != other.rows) {
            cout << "Error: Matrix dimensions mismatch for multiplication." << endl;
            return;
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                result.matrix[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }
    }
};

int main() {
    srand(time(0));
    ofstream fout("100k.txt");
    for (int i = 0; i < 100000; i++) {
        int a = rand() % 6 + 1;
        fout << a << endl;
    }
    fout.close();

    int rowsA, colsA, rowsB, colsB;
    cout << "Enter number of rows for Matrix A: ";
    cin >> rowsA;
    cout << "Enter number of columns for Matrix A: ";
    cin >> colsA;

    cout << "Enter number of rows for Matrix B: ";
    cin >> rowsB;
    cout << "Enter number of columns for Matrix B: ";
    cin >> colsB;

    int totalElementsA = rowsA * colsA;
    int totalElementsB = rowsB * colsB;
    if (totalElementsA > 100000 || totalElementsB > 100000) {
        cout << "Error: Matrix dimensions exceed the number of generated values (100,000)." << endl;
        return 1;
    }

    ifstream fin("100k.txt");

    Matrix matrixA(rowsA, colsA);
    matrixA.fillFromFile(fin);

    Matrix matrixB(rowsB, colsB);
    matrixB.fillFromFile(fin);

    fin.close();

    cout << "Matrix A:" << endl;
    matrixA.print();
    cout << endl;

    cout << "Matrix B:" << endl;
    matrixB.print();
    cout << endl;

    Matrix matrixResult(rowsA, colsB);
    matrixA.multiply(matrixB, matrixResult);

    cout << "Matrix Multiplication (A * B):" << endl;
    matrixResult.print();
    cout << endl;

    return 0;
}

