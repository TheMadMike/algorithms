/*
----------------------------------
    Matrix determinant calculator
    using Laplace expansion
----------------------------------
    Copyright 2020 by Michał Gibas
*/

#include <iostream>

typedef unsigned long size_t;

double** calculate_minor(double** matrix, size_t size, size_t row, size_t column);
double calculate_determinant(double** matrix, size_t size);

double** create_qmatrix(size_t size);
void destroy_matrix(double** matrix, size_t size);
void print_matrix(double** matrix, size_t size);

int main(void) {
    std::cout << "Matrix determinant calculator\n\n";

    std::cout << "Enter the size of the quadratic matrix A[NxN]: ";
    size_t size;
    std::cin >> size;

    std::cout << "A =\n";
    double** matrix = new double*[size];

    for(size_t i = 0; i < size; ++i) {
        matrix[i] = new double[size];
        for(size_t j = 0; j < size; ++j) {
            std::cin >> matrix[i][j]; 
        }
    }

    std::cout << "\n\ndet A = " << calculate_determinant(matrix, size) << "\n\n";

    destroy_matrix(matrix, size);
    return 0;
}
double calculate_determinant(double** matrix, size_t size) {
    if(size == 0)
        return 0.0;
    if(size == 1)
        return matrix[0][0];

    double det = 0.0;

    size_t i = 0;
    for(size_t j = 0; j < size; ++j) {
        double** minor = calculate_minor(matrix, size, i, j);
        double d = calculate_determinant(minor, size-1);
        if((i+j+2) % 2 != 0)
            d *= -1;

        det += matrix[i][j] * d; 
    }    

    return det;
}

double** calculate_minor(double** matrix, size_t size, size_t row, size_t column) {
    double** minor = create_qmatrix(size-1);
    size_t r = 0, c = 0;
    for(size_t i = 0; i < size; ++i) {
        if(i != row) {
            for(size_t j = 0; j < size; ++j) {
                if(j != column) {
                    minor[r][c] = matrix[i][j];
                    ++c;
                }
            }
            ++r;
        }
        c = 0;
    }

    return minor;
}


double** create_qmatrix(size_t size) {
    double** matrix = new double*[size];
    for(size_t i = 0; i < size; ++i) {
        matrix[i] = new double[size];
    }

    return matrix;
}

void destroy_matrix(double** matrix, size_t size) {
    for(size_t i = 0; i < size; ++i)
        delete[] matrix[i];    
    
    delete[] matrix;
}

void print_matrix(double** matrix, size_t size) {
    for(size_t i = 0; i < size; ++i) {
        for(size_t j = 0; j < size; ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
}