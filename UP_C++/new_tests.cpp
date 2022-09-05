#include <iostream>



int main() {
    int a[5] = { 1, 2, 3 };

    for (int i = 0; i < 5; i++) {
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;

    int *pt;
    int a1[3] = {4, 19, 13};
    pt = &a1[1];
    pt += 1;
    std::cout << *pt << std::endl;

    return 0;
}