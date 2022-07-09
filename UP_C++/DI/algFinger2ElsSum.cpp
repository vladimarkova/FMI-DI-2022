#include <iostream>
#include <algorithm>

bool isThere2DiffElsWithSum(int a[], int size, int sum) {
    int leftFinger = 0;
    int rightFinger = size - 1;
    std::sort(a, a + size);
    while (leftFinger < rightFinger) {
        if (a[leftFinger] + a[rightFinger] == sum) {
            std::cout << a[leftFinger] << " + " << a[rightFinger] << " = " << sum << '\n';
            return true;
        } 
        else if (a[leftFinger] + a[rightFinger] < sum) {
            leftFinger++;
        }
        else {
            rightFinger++;
        }
    }
    return false;
}

int main() {
    int a[9] = {0, 1, 3, 3, 4, 5, 6, 8, 1};
    std::cout << isThere2DiffElsWithSum(a, 9, 12) << '\n';

    return 0;   
}