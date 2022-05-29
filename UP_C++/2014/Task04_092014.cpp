#include <iostream>
using std::cout;

void square(int n, float* x, float* y) {
    float xMin = x[0];
    float xMax = x[0];
    float yMin = y[0];
    float yMax = y[0];
    for (int i = 1; i < n; i++) {
        if (x[i] < xMin) {
            xMin = x[i];
        }
        else if (x[i] > xMax) {
            xMax = x[i];
        }
        if (y[i] < yMin) {
            yMin = y[i];
        }
        else if (y[i] > yMax) {
            yMax = y[i];
        }
    }
    float a;
    if (xMax - xMin > yMax - yMin) {
        a = xMax - xMin;
    } 
    else {
        a = yMax - yMin;
    }
    cout << "Square center: (" << xMin + a/2 << ", " << yMax - a/2 << ")\n";
    cout << "Square side: " << a << '\n';
}

int main() {
    float x[5] = { -2, -3, -1.5, 4, 0};
    float y[5] = { 1, 4.5, 7.8, -3.4, -1 };
    square(5, x, y);

    return 0;
}