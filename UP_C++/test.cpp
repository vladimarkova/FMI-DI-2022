#include <iostream>
#include <cmath>

int countDigits(int n) {
    int count = 0;
    while (n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

int myPow(int num, int power) {
    int result = 1;

    while(power > 0) {
       result *= num;
       power--; 
    }

    return result;
}

int main()
{
    int num;

    std::cin >> num;

    if (num > 0) {
        std::cout << "positive\n";
    } else if (num < 0) {
        std::cout << "negative\n";
    } else {
        std::cout << "zero\n";
    }

    int reversed = 0;

    int digits = countDigits(num);
    int i = digits - 1;

    while (num > 0) {
        reversed += (num % 10) * myPow(10, i);
        num /= 10;
        i--;
    }
    std::cout << reversed << '\n';

    std::cout << myPow(2, 3) << '\n';

    int a[] = { 3 + 2, 2 * 4 };
    char b[3] = { 'w', 't', 'c' };
    std::cout << b << ' ' << b + 1 << ' ' << *(b + 2) << '\n';

    int c[3] = { 'w', 't', 'c' };
    std::cout << c << ' ' << c + 1 << ' ' << *(c + 2) << '\n';

    int d[5] = { 1, 3 };
    for (int i = 0; i < 5; i++) {
        std::cout << d[i] << ' ';
    }
    std::cout << '\n';
    
    return 0;
}