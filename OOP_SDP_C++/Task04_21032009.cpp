#include <iostream>

class Base { 
public:  
    Base () {std::cout << "Base::Base()\n"; f(); g();}  
    Base (Base&) {std::cout << "Base::Base(Base&)\n"; f();g();}   
    virtual void f () {std::cout << "Base::f()\n";g();}  
    void g () {std::cout << "Base::g()\n";}
    virtual ~Base() {
        std::cout << "~Base()" << '\n';
    }
};

class Derived1 : public Base { 
public:  
    Derived1 () {std::cout << "Derived1::Derived1()\n"; f(); g();}  
    Derived1 (Derived1 &) { std::cout << "Derived1::Derived1(Derived1&)\n";f();g(); }   
    void f () {std::cout << "Derived1::f()\n";g();}  
    virtual void g () {std::cout << "Derived1::g()\n";}
    ~Derived1() {
        std::cout << "~Derived1()" << '\n';
    }
};

class Derived2 : public Derived1 { 
public:  
    Derived2 () {std::cout << "Derived2::Derived2()\n";f();g();}  
    Derived2 (Derived2 &) { std::cout << "Derived2::Derived2(Derived2&)\n";f();g(); }   
    void f () {
        // Derived1::f();
        std::cout << "Derived2::f()\n";g();}  
    void g () {std::cout << "Derived2::g()\n";}
    ~Derived2() {
        std::cout << "~Derived2()" << '\n';
    }
};
    
void fCopy (Base obj) {  obj.f();  obj.g(); }

int main() {
    std::cout << "////////TASK1: " << std::endl;
    Base *pBase  = new Derived2;

    std::cout << "////////TASK2: " << std::endl;
    Derived1 *pDerived1 = new Derived2; 

    std::cout << "////////TASK3: " << std::endl;
    Derived2 *pDerived2 = new Derived2;

    std::cout << "////////TASK4: " << std::endl;
    pBase->f();

    std::cout << "////////TASK5: " << std::endl;
    pDerived1->f();

    std::cout << "////////TASK6: " << std::endl;
    pDerived2->f ();

    std::cout << "////////TASK7: " << std::endl;
    fCopy (*pBase);

    std::cout << "////////TASK8: " << std::endl;
    delete pBase;
    delete pDerived1;
    delete pDerived2;
}