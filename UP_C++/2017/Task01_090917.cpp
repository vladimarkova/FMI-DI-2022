#include <iostream>
#include <cstring>
using std::cout;

int findIslandSize(char matrix[][100], int elRow, int elCol, int rows, int cols, bool visited[][100]) {
    int sum = 0;
    if (elCol != 0 && matrix[elRow][elCol - 1] == '4' && !visited[elRow][elCol - 1]) {
        visited[elRow][elCol - 1] = true;
        sum += findIslandSize(matrix, elRow, elCol - 1, rows, cols, visited);
    }
    if (elCol != cols - 1 && matrix[elRow][elCol + 1] == '4' && !visited[elRow][elCol + 1]) {
        visited[elRow][elCol + 1] = true;
        sum += findIslandSize(matrix, elRow, elCol + 1, rows, cols, visited);
    }
    if (elRow != 0 && matrix[elRow - 1][elCol] == '4' && !visited[elRow - 1][elCol]) {
        visited[elRow - 1][elCol] = true;
        sum += findIslandSize(matrix, elRow - 1, elCol, rows, cols, visited);
    }
    if (elRow != rows - 1 && matrix[elRow + 1][elCol] == '4' && !visited[elRow + 1][elCol]) {
        visited[elRow + 1][elCol] = true;
        sum += findIslandSize(matrix, elRow + 1, elCol, rows, cols, visited);
    }
    return sum + 1;
}

int maxIslandSize(char matrix[][100], int rows, int cols) {
    int maxSize = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '4') {
                bool visited[100][100] = {false};
                visited[i][j] = true;
                int currentIslandSize = findIslandSize(matrix, i, j, rows, cols, visited);
                if (currentIslandSize > maxSize) {
                    maxSize = currentIslandSize;
                }
            }
        }
    }
    return maxSize;
}

// for reference
void myStrcpy(char* arr1, const char* arr2) {
    int i = 0;
    while (arr2[i] != '\0') {
        arr1[i] = arr2[i];
        i++;
    }
    arr1[i] = '\0';
}

int main() {
    char matrix[100][100];
    strcpy(matrix[0], "RR1144");
    strcpy(matrix[1], "144R14");
    strcpy(matrix[2], "S14443");
    strcpy(matrix[3], "44SSRR");
    

    cout << maxIslandSize(matrix, 4, 6) << '\n';

    // char testArr[10];
    // myStrcpy(testArr, "ABCDE");
    // cout << testArr << '\n';

    return 0;
}