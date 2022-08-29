#include <iostream>

double findAvgElemFromSymGroup(double matrix[11][11], int row, int col) {
    int sum = 0;
    int count = 0;
    sum += matrix[col][row];
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {

        }
    }
    return count > 0 ? (sum / count) : 0;
}

void transformMatrix(double matrix[11][11]) {
    double oldMatrix[11][11];
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            oldMatrix[i][j] = matrix[i][j];
        }
    }
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            matrix[i][j] = findAvgElemFromSymGroup(matrix, i, j);
        }
    }
}

int main() {

    return 0;
}