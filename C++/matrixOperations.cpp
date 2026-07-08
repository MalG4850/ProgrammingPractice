#include <iostream>
#include <vector>

class Matrix {
public:
    int rows;
    int cols;
    // A 2D vector: a vector of vectors of integers
    std::vector<std::vector<int>> data;

    // Constructor to easily initialize a matrix with given dimensions
    Matrix(int r = 0, int c = 0) : rows(r), cols(c) {
        data.resize(rows, std::vector<int>(cols, 0));
    }
};

// Pass by const reference to avoid expensive copying
Matrix addMatrices(const Matrix& a, const Matrix& b) {
    Matrix result(a.rows, a.cols);

    for (int i = 0; i < a.rows; ++i) {
        for (int j = 0; j < a.cols; ++j) {
            result.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return result;
}

Matrix multiplyMatrices(const Matrix& a, const Matrix& b) {
    Matrix result(a.rows, b.cols);

    for (int i = 0; i < a.rows; ++i) {
        for (int j = 0; j < b.cols; ++j) {
            result.data[i][j] = 0;
            for (int k = 0; k < a.cols; ++k) {
                result.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return result;
}

void printMatrix(const Matrix& m) {
    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.cols; ++j) {
            std::cout << m.data[i][j] << '\t';
        }
        std::cout << '\n';
    }
    std::cout << "\n\n";
}

int main() {
    int choice;
    std::cout << "\nThis is a program for Matrix Operations.\n\n";
    std::cout << "[1] Addition\n[2] Multiplication\n\nEnter your choice: ";
    std::cin >> choice;

    if (choice != 1 && choice != 2) {
        std::cout << "Invalid choice.\n";
        return 1;
    }

    int r1, c1, r2, c2;
    std::cout << "\nEnter rows and cols for matrix 1: ";
    std::cin >> r1 >> c1;
    std::cout << "\nEnter rows and cols for matrix 2: ";
    std::cin >> r2 >> c2;

    // --- Validation Checks Right Here ---
    if (choice == 1) {
        if (r1 != r2 || c1 != c2) {
            std::cout << "\nError: Dimensions must match for addition (e.g., both must be MxN).\n\n";
            return 1;
        }
    } else if (choice == 2) {
        if (c1 != r2) {
            std::cout << "\nError: Columns of matrix 1 (" << c1
                      << ") must equal rows of matrix 2 (" << r2 << ") for multiplication.\n\n";
            return 1;
        }
    }

    // --- Inputs are validated! Safe to create matrices and get elements ---
    Matrix a(r1, c1);
    Matrix b(r2, c2);

    std::cout << "\nEnter matrix 1 elements: ";
    for (int i = 0; i < r1; ++i)
        for (int j = 0; j < c1; ++j)
            std::cin >> a.data[i][j];

    std::cout << "\nEnter matrix 2 elements: ";
    for (int i = 0; i < r2; ++i)
        for (int j = 0; j < c2; ++j)
            std::cin >> b.data[i][j];

    // --- Perform operations ---
    Matrix result;
    if (choice == 1) {
        result = addMatrices(a, b);
    } else {
        result = multiplyMatrices(a, b);
    }

    std::cout << "\nResult:\n\n";
    printMatrix(result);
    return 0;
}
