#include <iostream>
using std::cout;
using std::cin;

int numberOfDigits(int n) {
    int number = 0;
    while(n > 0) {
        number++;
        n /= 10;
    }
    return number;
}

bool lessThanLex(int a, int b) {
    int arr1[10];
    int arr2[10];
    int aDigitsNum = numberOfDigits(a);
    int bDigitsNum = numberOfDigits(b);

    int i = 0;
    while(a > 0) {
        arr1[aDigitsNum - i - 1] = a % 10;
        a /= 10;
        i++;
    }
    i = 0;
    while(b > 0) {
        arr2[bDigitsNum - i - 1] = b % 10;
        b /= 10;
        i++;
    }
    int minDigitsNum = aDigitsNum < bDigitsNum ? aDigitsNum : bDigitsNum;
    for (int i = 0; i < minDigitsNum; i++) {
        if (arr1[i] < arr2[i]) {
            return true;
        }
        if (arr2[i] < arr1[i]) {
            return false;
        }
    }
    // if we are here the digits are the same to minDigitsNum
    return aDigitsNum < bDigitsNum;
}

void sortLex(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (lessThanLex(arr[j], arr[i])) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int main() {
    int arr[6] = {13, 14, 7, 2018, 9, 0};
    sortLex(arr, 6);

    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';

    return 0;
}