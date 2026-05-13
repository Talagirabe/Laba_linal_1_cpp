#include "matrix.h"
#include "random"

static std::mt19937 generator(67); // фиксированная случайность

Matrix generate_matrix(int n) {
    std::uniform_real_distribution<double> distribution(-1.0, 1.0); // Распределение случайных чисел

    Matrix A(n, std::vector<double>(n));

    for(int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = distribution(generator);

    return A;
}

Vector generate_vector(int n) {
    std::uniform_real_distribution<double> distribution(-1.0, 1.0);

    Vector v(n);

    for (int i = 0; i < n; i++)
        v[i] = distribution(generator);

    return v;
}

Matrix generate_hilbert_matrix(int n) {
    Matrix H(n, std::vector<double>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            H[i][j] = 1.0 / (i + j + 1); // - 1

    return H;
}

Vector multiply(const Matrix& A, const Vector& x) {
    int n = A.size();
    Vector b(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            b[i] += A[i][j] * x[j];

    return b;


}