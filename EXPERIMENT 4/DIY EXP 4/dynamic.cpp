#include <iostream>
using namespace std;

class Matrix {
    int rows, cols;
    int **mat;

public:
    // Constructor
    Matrix(int r, int c) {
        rows = r;
        cols = c;

        mat = new int*[rows];

        for (int i = 0; i < rows; i++)
            mat[i] = new int[cols];
    }

    // Deep copy constructor
    Matrix(const Matrix &m) {
        rows = m.rows;
        cols = m.cols;

        mat = new int*[rows];

        for (int i = 0; i < rows; i++) {
            mat[i] = new int[cols];

            for (int j = 0; j < cols; j++)
                mat[i][j] = m.mat[i][j];
        }
    }

    void input() {
        cout << "Enter matrix elements:\n";

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> mat[i][j];
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    }

    // Destructor
    ~Matrix() {
        for (int i = 0; i < rows; i++)
            delete[] mat[i];

        delete[] mat;
    }
};

int main() {
    int r, c;

    cout << "Enter rows and columns: ";
    cin >> r >> c;

    Matrix m1(r, c);

    m1.input();

    cout << "\nOriginal Matrix:\n";
    m1.display();

    Matrix m2 = m1;   // Deep copy

    cout << "\nCopied Matrix:\n";
    m2.display();

    return 0;
}