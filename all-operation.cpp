#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<double>> data;
    int rows;
    int cols;

public:
    // Constructor
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data.resize(rows, std::vector<double>(cols, 0.0));
    }

    // Function to set the value of an element
    void set(int row, int col, double value) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            data[row][col] = value;
        }
    }

    // Function to get the value of an element
    double get(int row, int col) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            return data[row][col];
        }
        return 0.0; // Default value if out of bounds
    }

    // Function to add two matrices
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            // Matrices must have the same dimensions for addition
            throw std::runtime_error("Matrix dimensions do not match for addition.");
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.set(i, j, data[i][j] + other.data[i][j]);
            }
        }

        return result;
    }

    // Function to subtract two matrices
    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            // Matrices must have the same dimensions for subtraction
            throw std::runtime_error("Matrix dimensions do not match for subtraction.");
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.set(i, j, data[i][j] - other.data[i][j]);
            }
        }

        return result;
    }

    // Function to multiply two matrices
    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            // The number of columns in the first matrix must match the number of rows in the second matrix
            throw std::runtime_error("Matrix dimensions do not match for multiplication.");
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                double sum = 0.0;
                for (int k = 0; k < cols; ++k) {
                    sum += data[i][k] * other.data[k][j];
                }
                result.set(i, j, sum);
            }
        }

        return result;
    }

    // Function to transpose a matrix
    Matrix transpose() const {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.set(j, i, data[i][j]);
            }
        }
        return result;
    }

    // Function to display the matrix
    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Matrix A(2, 3);
    A.set(0, 0, 1);
    A.set(0, 1, 2);
    A.set(0, 2, 3);
    A.set(1, 0, 4);
    A.set(1, 1, 5);
    A.set(1, 2, 6);

    Matrix B(3, 2);
    B.set(0, 0, 7);
    B.set(0, 1, 8);
    B.set(1, 0, 9);
    B.set(1, 1, 10);
    B.set(2, 0, 11);
    B.set(2, 1, 12);

    std::cout << "Matrix A:" << std::endl;
    A.display();

    std::cout << "Matrix B:" << std::endl;
    B.display();

    Matrix C = A * B;

    std::cout << "Matrix C (A * B):" << std::endl;
    C.display();

    return 0;
}
