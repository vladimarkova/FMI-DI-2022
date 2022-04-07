#include <iostream>
#include <cstring>
using std::cout;

void print_backwards(const char *begin, const char *end) {
    char* word = new char[end - begin];
    int i = 0;
    for (const char* ptr = end - 1; ptr >= begin; ptr--) {
        if (*ptr > 32) {
            word[i] = *ptr;
            i++;
        } else {
            for (int k = i - 1; k >= 0; k--) {
                cout << word[k];
            }
            cout << " ";
            i = 0;
            while (*ptr <= 32 && ptr >= begin) {
                ptr--;
            }
            ptr++;
        }
    }
    for (int k = i - 1; k >= 0; k--) {
        cout << word[k];
    }
    cout << '\n';
};

void print_backwards_rec(const char *begin, const char *end) {
    if (begin >= end) {
        return; 
    }

    if (*(end - 1) <= 32) {
        print_backwards_rec(begin, end - 1);
        return;
    }

    char* word = new char[20];
    int i = 0;
    const char* ptr = end - 1;

    while (ptr >= begin && *ptr > 32) {
        word[i] = *ptr;
        i++;
        ptr--;
    }

    for (int k = i - 1; k >= 0; k--) {
        cout << word[k];
    }

    cout << " ";

    print_backwards_rec(begin, ptr);
};

void print_backwards(const char* string) {
    // int i = 0;
    // while (string[i] != '\0') {
    //     i++;
    // };

    int strLength = strlen(string);

    print_backwards_rec(string, string + strLength);
}

int main() {
    char myString[100] = "This is very hot!";
    const char* end = myString + 17;

    // print_backwards(myString, end);
    // print_backwards_rec(myString, end);

    print_backwards(myString);

    cout << '\n';

    return 0;
}