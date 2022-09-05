#include <iostream>

class Base { 
public:     
    Base() { std::cout << "Base::Base()\n"; }    
    Base(const Base&) { std::cout << "Base::copy()\n"; }     
    virtual void f() { std::cout << "Base::f()\n"; }    
    virtual ~Base() { std::cout << "Base::~\n"; } 
}; 

class Der : public Base { 
public:
    Der() { std::cout << "Der::Der()\n"; }  
    Der(const Der&) { std::cout << "Der::Copy()\n"; }   
    void f() { std::cout << "Der::f()\n"; }     
    ~Der() { std::cout << "Der::~\n"; } 
}; 

void g1(Base a) { std::cout << "F:";   a.f(); } 

void g2(Der a) { std::cout << "F:";   a.f(); } 

void g3(Base& a) { std::cout << "F:";   a.f(); }

int main() {
    std::cout << "1:\n";   
    Der d;

    std::cout << "2:\n";
    g1(d);

    std::cout << "3:\n";
    g2(d);

    std::cout << "4:\n";
    g3(d);

    std::cout << "5:\n";

    return 0;
}