#include <iostream>
#include <stack>
using std::cout;
using std::stack;

struct Cell {
    int row;
    int col;
    Cell(int _row = 0, int _col = 0) {
        row = _row;
        col = _col;
    }
};

double averageBrightness(int matrix[][100], int rows, int cols, int elRow, int elCol, bool visited[][100]) {
    stack<Cell> cells;
    cells.push(Cell(elRow, elCol));
    double sumBrightness = 0;
    int countCells = 0;

    while(!cells.empty()){
        Cell current = cells.top();
        cells.pop();
        sumBrightness += matrix[current.row][current.col];
        countCells++;
        for (int i = current.row - 1; i <= current.row + 1; i++) {
            for (int j = current.col - 1; j <= current.col + 1; j++) {
                if (i >= 0 && i < rows && j >= 0 && j < cols && matrix[i][j] != 0 && !visited[i][j]) {
                    cells.push(Cell(i, j));
                    visited[i][j] = true;
                }
            }
        }
    }

    return sumBrightness / countCells;
}

void printAverageBrightnesses(int matrix[][100], int rows, int cols) {
    bool visited[100][100] = { false };
    double avgBrightnesses[2500]; // oblastite mogat da budat nai-mnogo br. na kletkite / 4
    Cell representatives[2500];
    int k = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!visited[i][j] && matrix[i][j] != 0) {
                visited[i][j] = true;
                avgBrightnesses[k] = averageBrightness(matrix, rows, cols, i, j, visited);
                representatives[k] = Cell(i, j);
                k++;
            }
        }
    }

    for (int i = 0; i < k - 1; i++) {
        for (int j = i + 1; j < k; j++) {
            if (avgBrightnesses[j] > avgBrightnesses[i]) {
                double tmp = avgBrightnesses[i];
                avgBrightnesses[i] = avgBrightnesses[j];
                avgBrightnesses[j] = tmp;
            }
        }
    }

    for (int i = 0; i < k; i++) {
        cout << '(' << representatives[i].row << ", " << representatives[i].col << ") " << avgBrightnesses[i] << '\n';
    }
}

int main() {
    int matrix[6][6] = {
        170,   0,   0, 255, 221,   0,
         68,   0,  17,   0,   0,  68,
        221,   0, 238, 136,   0, 255,
          0,   0,  85,   0, 136, 238,
        238,  17,   0,  68,   0, 255,
         85, 170,   0, 221,  17,   0
    };

    int matrix2[100][100];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            matrix2[i][j] = matrix[i][j];
        }
    }

    printAverageBrightnesses(matrix2, 6, 6);

    return 0;
}