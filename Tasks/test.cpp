#include <iostream>

int main() {
    char* a = "Hello!";
    std::cout << *(a + 1) << ' ' << ++*a++ << ' ' << *a << '\n';

    char w = 'a';
    std::cout << ++w << '\n';

    return 0;
}