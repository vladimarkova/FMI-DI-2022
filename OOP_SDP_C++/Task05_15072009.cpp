#include <iostream>

class A { 
public:     
    A() { std::cout << "A::A()\n"; g(); }     
    void operator=(const A&) { std::cout << "A::=\n"; }     
    void f() { std::cout << "A::f()\n"; g(); }     
    virtual void g () { std::cout << "A::g()\n"; }     
    virtual ~A() { std::cout << "A::~\n"; } 
}; 

class B : public A { 
public:     
    B() { std::cout << "B::B()\n"; }
    void f() { std::cout << "B::f()\n"; }     
    void g() { std::cout << "B::g()\n"; }  
    ~B() { std::cout << "B::~\n"; } 
};

int main() {
    std::cout << "1:\n";
    B* bp = new B;

    std::cout << "2:\n";
    A* bp_a = bp;
    bp_a->f();

    std::cout << "3:\n";
    bp_a->g();

    std::cout << "4:\n";
    // A a;
    // a = *bp;

    std::cout << "5:\n";
    B b;
    b = *bp;

    std::cout << "6:\n";
    delete bp_a;

    std::cout << "7:\n"; 

    return 0;
}