#include <iostream>
using std::cout;

void subsample(float img[][10], int rows, int cols) {
    for (int i = 0; i < (rows + 1) / 2; i++) {
        for (int j = 0; j < (cols + 1) / 2; j++) {
            if (2 * i + 1 >= rows && 2 * j + 1 >= cols) {
                cout << img[2 * i][2 * j] << ' ';
            }
            else if(2 * i + 1 >= rows) {
                float avg = (img[2 * i][2 * j] + img[2 * i][2 * j + 1]) / 2;
                cout << avg << ' '; 
            }
            else if(2 * j + 1 >= cols) {
                float avg = (img[2 * i][2 * j] + img[2 * i + 1][2 * j]) / 2;
                cout << avg << ' '; 
            } 
            else {
                float avg = (img[2 * i][2 * j] + 
                             img[2 * i + 1][2 * j] + 
                             img[2 * i][2 * j + 1] +
                             img[2 * i + 1][2 * j + 1])/ 4;
                cout << avg << ' ';
            }
        }
        cout << '\n';
    }
}

int main() {
    float img[2][10] = {
        1.0, 2.0, 3.0, 0, 0, 0, 0, 0, 0, 0,
        4.5, 6.5, 7.5
    };
    subsample(img, 2, 3);

    return 0;
}