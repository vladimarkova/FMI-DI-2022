#include <iostream>

int calc(int a[5]) {
    int sum = 8;
    for (int i = 0; a[i]; ++i)
    sum += i;
    return sum;
}

void f(int * arr1, const int * arr2) {
    int *p1 = arr1;
    const int *p2 = arr2;
    while(*p2 >= 0)
    {
    *p1++ = *p2++;
    }
}

int main() {
    // int a[7] = {1, 2, 3};
    // std::cout << calc(a) << '\n';

    // char text[] = "hello";
    // char* p = text;
    // std::cout << *(p + 1) << '\n';
    // while (*p) std::cout << ++*p++;
    // std::cout << '\n' << text << ' ' << *text << '\n';

    // int* pt;
    // int a[3] = {4, 19, 13};
    // pt = &a[1];
    // pt += 1;
    // std::cout << *pt << std::endl;

    // int A[4] = {-1, -2, -3, -4};
    // int B[4] = {10, 20, 30, -1};
    // f(A, B);

    // for (int i = 0; i < 4; i++) {
    //     std::cout << A[i] << ' ';
    // }
    // std::cout << '\n';

    // for (int i = 0; i < 4; i++) {
    //     std::cout << B[i] << ' ';
    // }
    // std::cout << '\n';

    // int x = 1;
    // switch (x) {
    //     case 1 : x++;
    //     case 2 : x += 2;
    //     case 4 : x += 4; break;
    //     default : x += 5;
    // }
    // std::cout << x << '\n';

    for(int i = 1, x = 0, y = 1; i < 5; i++) {
        x += i;
        y *= x;
        if (i == 4) {
            std::cout << x << ' ' << y << '\n';
        }
    }

    int i = 3;
    while(--i) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}
