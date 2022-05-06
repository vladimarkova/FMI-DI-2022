#include <iostream>
#include <cstring>
using std::cout;

void revealPassword(char books[][30][101], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        bool isSorted = true;
        for (int j = 0; j < cols - 1; j++) {
            if (strcmp(books[i][j], books[i][j + 1]) > 0) {
                isSorted = false;
            }
        }
        if (isSorted) {
            int titleLength = strlen(books[i][(cols - 1) / 2]);
            int tempLength = 0;
            for (int k = 0; k < titleLength; k++) {
                if (books[i][(cols - 1) / 2][k] == ' ') {
                    cout << tempLength << ' ';
                    tempLength = 0;
                } else {
                    tempLength++;
                }
            }
            cout << tempLength << ' ';
        }
    }
}

int main() {
    char books[20][30][101];
    
    strcpy(books[0][0], "Algebra");
    strcpy(books[0][1], "Analitichna geometriya");
    strcpy(books[0][2], "C++");

    strcpy(books[1][0], "UP");
    strcpy(books[1][1], "OOP");
    strcpy(books[1][2], "SDP");

    strcpy(books[2][0], "Bazi ot danni");
    strcpy(books[2][1], "Izkustven intelekt");
    strcpy(books[2][2], "Ruby");

    revealPassword(books, 3, 3);

    return 0;
}