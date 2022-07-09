#include <iostream>

struct Node {
    int val = 0;
    Node* left = nullptr;
};

Node n{5};

int a;

int& testRef(int& x) {
    x++;
    return x;
}

int& pointerFunction(int* px) {
    int y = *px + 1;
    //!!! return &y; // y е записан в стековата рамка, която изчезва!
    //!!! return &x; // x е записан в стековата рамка, която изчезва!
    int a[10] = { 0 };
    // return a; // a е записан в стековата рамка, която изчезва!
    return *px;
}

void pesho() {
    static int cnt{ 0 };
    std::cout << ++cnt << std::endl;
}

struct gosho {
    static int var;
    int pesho = 3;
    gosho& operator++() { 
        ++pesho;
        return *this;
    }
    gosho operator++(int) { 
        gosho old = *this;
        ++(*this);
        return old;
    }
};
int gosho::var = 42;

int main() {
    pesho();
    pesho();    
    std::cout << ++gosho::var << std::endl;
    gosho g;
    ++g;
    std::cout << g.pesho << std::endl;
    std::cout << g++.pesho << std::endl;
    std::cout << g.pesho << std::endl;

    gosho* g1 = new gosho();
    g1->pesho;

    int a = 10;
    int* ptr = &a;
    std::cout << --*(ptr) << ' ' << ptr << '\n';
    --ptr;
    // std::cout << ptr << *(ptr) << '\n';

    int t = 15;
    int result = testRef(t);
    std::cout << result << ' ' << t << '\n' << ++result << ' ' << t << '\n';

    int* testPtr = &t;
    std::cout << '\n' << *testPtr << '\n';
    int newPtr = pointerFunction(testPtr);
    std::cout << *testPtr << '\n';
    std::cout << newPtr << '\n';
    newPtr++;
    std::cout << *testPtr << ' ' << newPtr << '\n';

    return 0;
}