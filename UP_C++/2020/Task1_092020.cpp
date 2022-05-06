#include <iostream>
#include <cstring>
using std::cout;

bool is_subordinate (const char* employee, 
                     const char* manager, 
                     const char* leaders[][2], 
                     size_t n) {
    if (strcmp(employee, manager) == 0) {
        return false;
    }

    for (int i = 0; i < n; i++) {
        if (strcmp(leaders[i][0], employee) == 0) {
            if (strcmp(leaders[i][1], manager) == 0) {
                return true;
            } 
            return is_subordinate(leaders[i][1], manager, leaders, n);
        }
    }
    return false;
}

void sort(int* arr, int size) {

}

void printMatrix(int matrix[][20], int rows, int cols) {

}

void test(int** matrix, int rows, int cols) {

}

int main() {
    int something = 7;
    int myar[2][3] = {1, 2, 3, 4, 5, 6};
    // cout << &myar[1][2] << '\n'; // losho e!!!

    int* somePtr = new int(20);
    cout << &somePtr << '\n';
    // two below are equal
    cout << &(*somePtr) << '\n';
    cout << somePtr << '\n';

    // int arr1[15]; 
    // // ...
    // sort(arr1, 9);

    // int* arr2 = new int[20];
    // // ...
    // sort(arr2, 9);
    // // ...
    // delete[] arr2;

    // int matrix[10][20];
    // matrix[3][5] = 16;

    const char* leaders[3][2] = {
        "Maria", "Ivan",
        "Ivan", "Stoyan",
        "Peter", "Maria"    
    };

    const char* ptr = "gosho";
    // cout << ptr << '\n'; // gosho
    // cout << *ptr << '\n'; // g

    cout << is_subordinate("Ivan", "Maria", leaders, 3) << '\n';

    int** myMatrix = new int*[3];

    for (int i = 0; i < 3; i++) {
        myMatrix[i] = new int[2];
    } 

    myMatrix[0][1] = 10;

    for (int i = 0; i < 3; i++) {
        delete[] myMatrix[i];
    }

    delete[] myMatrix;  

    // Movie* ptr;

    // {
    //     ptr = new Movie;

    //     delete ptr;
    // }

    // *(ptr) losho e!!!

    int dog = 42;
    const int* cat = &dog;
    *((int*)cat) = 84;
    cout << dog << '\n';

    return 0;
}