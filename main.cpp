#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

const int SIZE = 4; 

template <typename T>
void initializeMatrix(T matrix[][SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = static_cast<T>(rand() % 100);
        }
    }
}

template <typename T>
void printMatrix(const T matrix[][SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

template <typename T>
void findDiagonalMinMax(const T matrix[][SIZE], int size) {
    T max = matrix[0][0];
    T min = matrix[0][0];

    for (int i = 1; i < size; ++i) {
        if (matrix[i][i] > max) {
            max = matrix[i][i];
        }
        if (matrix[i][i] < min) {
            min = matrix[i][i];
        }
    }

    cout << "Max on the main diagonal: " << max << endl;
    cout << "Min on the main diagonal: " << min << endl;
}

template <typename T>
void sortRowsAscending(T matrix[][SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        std::sort(matrix[i], matrix[i] + size);
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int intMatrix[SIZE][SIZE];
    double doubleMatrix[SIZE][SIZE];

    initializeMatrix(intMatrix, SIZE);
    initializeMatrix(doubleMatrix, SIZE);

    cout << "Initialized integer matrix:" << endl;
    printMatrix(intMatrix, SIZE);
    findDiagonalMinMax(intMatrix, SIZE);
    sortRowsAscending(intMatrix, SIZE);
    cout << "Integer matrix with rows sorted in ascending order:" << endl;
    printMatrix(intMatrix, SIZE);

    cout << "Initialized double matrix:" << endl;
    printMatrix(doubleMatrix, SIZE);
    findDiagonalMinMax(doubleMatrix, SIZE);
    sortRowsAscending(doubleMatrix, SIZE);
    cout << "Double matrix with rows sorted in ascending order:" << endl;
    printMatrix(doubleMatrix, SIZE);

    return 0;
}
