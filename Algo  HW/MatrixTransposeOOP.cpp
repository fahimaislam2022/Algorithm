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

    void fillFromStream(ifstream &fin) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                fin >> matrix[i][j];
            }
        }
    }

    void transpose(Matrix &result) const {
        for (int i = 0; i < cols; ++i) {
            for (int j = 0; j < rows; ++j) {
                result.matrix[i][j] = this->matrix[j][i];
            }
        }
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
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

    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int totalElements = rows * cols;
    if (totalElements > 100000) {
        cout << "Error: Matrix dimensions exceed the number of generated values (100,000)." << endl;
        return 1;
    }

    ifstream fin("100k.txt");

    Matrix matrixA(rows, cols);
    matrixA.fillFromStream(fin);

    Matrix matrixTransposeA(cols, rows);

    fin.close();

    cout << "Matrix A:" << endl;
    matrixA.print();
    cout << endl;

    matrixA.transpose(matrixTransposeA);

    cout << "Transpose of Matrix A:" << endl;
    matrixTransposeA.print();
    cout << endl;

    return 0;
}

