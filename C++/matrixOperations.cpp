#include <iostream>
#include <vector>

class Matrix {
public:
    int rows;
    int cols;
    // A 2D vector: a vector of vectors of integers
    std::vector<std::vector<int>> data;

    Matrix(int r = 0, int c = 0) : rows(r), cols(c) {
        data.resize(rows, std::vector<int>(cols, 0));
    }
};

Matrix addMatrices(const Matrix& a, const Matrix& b) {
    Matrix result(a.rows, a.cols);

    for (int i = 0; i < a.rows; ++i) {
        for (int j = 0; j < a.cols; ++j) {
            result.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return result;
}

Matrix subtractMatrices(const Matrix& a, const Matrix& b) {
    Matrix result(a.rows, a.cols);

    for (int i = 0; i < a.rows; ++i) {
        for (int j = 0; j < a.cols; ++j) {
            result.data[i][j] = a.data[i][j] - b.data[i][j];
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

Matrix transposeMatrix(const Matrix& m) {
    Matrix result(m.cols, m.rows);

    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.cols; ++j) {
            result.data[j][i] = m.data[i][j];
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

void printUpperTriangular(const Matrix& m) {
    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.cols; ++j) {
            if (i > j) {
                std::cout << 0 << '\t';
            } else {
                std::cout << m.data[i][j] << '\t';
            }
        }
        std::cout << '\n';
    }
    std::cout << "\n\n";
}

int main(void) {
    int choice;
    std::cout << "\nThis is a program for Matrix Operations.\n\n";
    std::cout << "[1] Addition\n[2] Subtraction\n[3] Multiplication\n[4] Transpose\n[5] Upper Triangular Form\n\nEnter your choice: ";
    std::cin >> choice;

    // Fixed validation check to allow choices 1 through 5
    if (choice < 1 || choice > 5) {
        std::cout << "Invalid choice.\n";
        return 1;
    }

    int r1, c1;
    std::cout << "\nEnter rows and cols for matrix 1: ";
    std::cin >> r1 >> c1;

    // Upper Triangular Form requires a square matrix
    if (choice == 5 && r1 != c1) {
        std::cout << "\nError: Upper triangular form requires a square matrix (rows == cols).\n\n";
        return 1;
    }

    Matrix a(r1, c1);
    std::cout << "\nEnter matrix 1 elements: ";
    for (int i = 0; i < r1; ++i)
        for (int j = 0; j < c1; ++j)
            std::cin >> a.data[i][j];

    // Single-matrix operations stop here and print
    if (choice == 4) {
        std::cout << "\nResult (Transpose):\n\n";
        printMatrix(transposeMatrix(a));
        return 0;
    } else if (choice == 5) {
        std::cout << "\nResult (Upper Triangular Form):\n\n";
        printUpperTriangular(a);
        return 0;
    }

    // Two-matrix operations (Addition, Subtraction, Multiplication)
    int r2, c2;
    std::cout << "\nEnter rows and cols for matrix 2: ";
    std::cin >> r2 >> c2;

    // Dimension validations for two-matrix operations
    if (choice == 1 || choice == 2) {
        if (r1 != r2 || c1 != c2) {
            std::cout << "\nError: Dimensions must match for addition/subtraction.\n\n";
            return 1;
        }
    } else if (choice == 3) {
        if (c1 != r2) {
            std::cout << "\nError: Columns of matrix 1 (" << c1
                      << ") must equal rows of matrix 2 (" << r2 << ") for multiplication.\n\n";
            return 1;
        }
    }

    Matrix b(r2, c2);
    std::cout << "\nEnter matrix 2 elements: ";
    for (int i = 0; i < r2; ++i)
        for (int j = 0; j < c2; ++j)
            std::cin >> b.data[i][j];

    // Compute two-matrix results
    Matrix result;
    switch (choice) {
        case 1:
            result = addMatrices(a, b);
            break;
        case 2:
            result = subtractMatrices(a, b);
            break;
        case 3:
            result = multiplyMatrices(a, b);
            break;
    }

    std::cout << "\nResult:\n\n";
    printMatrix(result);
    return 0;
}
