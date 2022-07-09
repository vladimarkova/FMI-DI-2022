#include <iostream>
#include <cstring>
#include <cmath>
using std::cout;
using std::strlen;

void stringTests() {
        char g = 'G';
    cout << (char)(g - 'A' + 'a') << '\n';

    const char* str = "12345";
    int len = 4;
    int num_rev = 0;
    while(len >= 0) { 
        num_rev *= 10;
        num_rev += (str[len--] - '0');
    //    std::cout << num << std::endl;
    }
    std::cout << num_rev << std::endl;

    int num = 0;
    const char* iter = str;
    cout << (void*)iter << '\n';
    while(*iter) { 
        num *= 10;
        num += (*iter++ - '0');
    }
    cout << (void*)iter << ' ' << (int)*iter << '\n';
    std::cout << num << std::endl;

    cout << 'a' << '\t' << 'b' << '\n';
    cout << 'a' + 'b' << '\n';
    cout << exp(3) << '\n';
}

int main(int argc, const char** argv) {
    // std::cout << argc << std::endl;
    // std::cout << argv[0] << std::endl; 
    // std::cout << argv[1] << std::endl;

    // stringTests();

    int n = 54891;

    while (n >= 10) {
        n /= 10;
    }
    // cout << n << '\n';

    int x = 2;
    x = 3.8;
    x = true;
    x = 2 <= 3;
    x = 'A';

    cout << x << ' ' << ++++x << ' ' << (int)'C' << ' ' << '\n';

    int a = 5;
    cout << a++ << ' ' << a << '\n';
    int b = ++a;
    cout << b << '\n';

    return 0;
}