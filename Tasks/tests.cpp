#include <iostream>
#include <cstring>

void testFunction(int** matrix) {
    // test
}

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

    char text[] = "hello";
    char* p = text;
    std::cout << *(p + 1) << '\n';
    while (*p) std::cout << ++*p++;
    std::cout << '\n' << text << ' ' << *text << '\n';

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

    // for(int i = 1, x = 0, y = 1; i < 5; i++) {
    //     x += i;
    //     y *= x;
    //     if (i == 4) {
    //         std::cout << x << ' ' << y << '\n';
    //     }
    // }

    // int i = 3;
    // while(--i) {
    //     std::cout << i << ' ';
    // }
    // std::cout << '\n';

    // double arr[10] = { 1.2, 3.4, 5.6 };
    // for (int i = 0; i < 10; i++) {
    //     std::cout << arr[i] << ' ';
    // }
    // std::cout << '\n';

    // int a[] = { 5, 6 };
    // int x;
    // x = a[1];
    // a[1] = 10;

    //  char word[5] = { 'H', 'e', 'l', 'l', 'o' };
    //  std::cout << word << '\n';

    // char word[100] = "He\0llo";
    // std::cout << std::strlen(word) << '\n';

    // char w1[7] = "abc";
    // // std::strcpy(w1, "rotten");
    // std::strcat(w1, "rot");
    // // std::cout << w1 << '\n';
    // std::cout << std::strchr(w1, 'c') << '\n';

    // char word[5] = { 'H', 'e', 'l', 'l', 'o' };
    // char word2[10];

    // std::cout << std::strlen(word) << '\n'; // !!! UNDEFINED BEHAVIOUR
    // std::strcpy(word2, word); // !!! UNDEFINED BEHAVIOUR
    // std::cout << word2 << '\n';

    // int* ptr = nullptr;
    // std::cout << "ptr: " << ptr << '\n';

    // double d = 1.23;
    // double* p1 = &d;
    // double** pp1 = &p1;

    // std::cout << pp1 << ' ' << *pp1 << ' ' << **pp1 << '\n';
// #if 0
//     int x = 5;
//     int* p = &x;
//     (*p)++; // *p++ is different!!!
//     std::cout << x << '\n';
//     std::cout << p << ' ' << &p << '\n';
// #endif
//     int (*a)[10];

    return 0;
}
