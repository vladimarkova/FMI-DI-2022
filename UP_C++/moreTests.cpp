#include <iostream>
#include <cstring>

void test1(int* t) {
    std::cout << t << '\n';
}

void test2(int& t) {
    t = t + 2;
}

void printArrayWithPointers(int a[], int n) {
    std::cout << sizeof(a) << ' ' << sizeof(a[0]) << '\n'; // !!!
    for(int i = 0; i < n; i++)
        std::cout << "a[" << i << "]: " << &a[i] << ' ' << a[i] << '\n';
}

int main() {
    char str[] = "Hello";
    // std::cout << sizeof(str) << '\n' << strlen(str) << '\n';

    // for (int i = 128; i <= 150; i++) {
    //     std::cout << (char)i << ' ';
    // }
    // std::cout << '\n';

    int a = 5;
    int b = 10;
    int* ptr = &a;

    // std::cout << *ptr << ' ' << ptr << '\n';

    // int& ref = a;
    // std::cout << ref << ' ' << &ref << '\n';
    // ref = b;
    // std::cout << ref << ' ' << a << ' ' << &ref << ' ' << &a << '\n';

    int matrix[4][2] = { {1, 2}, {4, 5}, {7, 8}, {9, 10} };
    int rows = 4;


    // std::cout << matrix << '\n'; // address of the first element of the first row
	// std::cout << matrix + rows - 1 << '\n'; // address of the first element of the last row
	
    // std::cout << *(matrix + 2) << '\n'; // address of the first element of the third row
	
    // std::cout << **(matrix + 2) << '\n'; // value of the first element of the third row
    // std::cout << &matrix[0][0] << '\n';

    int t = 12;
    test1(&t);
    test2(t);
    std::cout << t << '\n' << (char)(5 + '0') << '\n';

    int* s;
    std::cout << s << '\n';
    // *s = 5;
    // std::cout << *s << '\n';

    int arr[6] = { 1, 8, 2, 4, 15, 3 };
    printArrayWithPointers(arr, 6); 

    return 0;
}