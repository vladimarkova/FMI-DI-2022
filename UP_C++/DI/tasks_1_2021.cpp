#include <iostream>

// int calc(int a[5]) {
//     int sum = 8;
//     for (int i = 0; a[i]; ++i)
//     sum += i;
//     return sum;
// }

void f(int * arr1, const int * arr2) {
    int *p1 = arr1;
    const int *p2 = arr2;
    while(*p2 >= 0) {
        *p1++ = *p2++;
    }
}

int main() {
    // int a[7] = {1, 2, 3};
    // std::cout << calc(a);

    // char text[] = "hello";
    // char* p = text;
    // std::cout << *p <<'\n' << *text <<'\n' << text << '\n';
    // while (*p) std::cout << ++*p++;
    // std::cout << '\n';

    // int *pt;
    // int a[3] = {4, 19, 13};
    // pt = &a[1];
    // pt += 1;
    // std::cout << *pt << std::endl;

    // int b = 5;
    // int c = 10;
    // const int* ptr = &b;
    // ptr = &c;
    // std::cout << *ptr << '\n';

    int A[4] = {-1, -2, -3, -4};
    int B[4] = {10, 20, 30, -1};
    f(A, B);

    for (int i = 0; i < 4; i++) {
        std::cout << A[i] << ' ';
    }
    std::cout << '\n';
     for (int i = 0; i < 4; i++) {
        std::cout << B[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}