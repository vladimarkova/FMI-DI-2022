#include <iostream>

class Animal {
    int weight = 20;
    int height = 30;
public:
    Animal() {
        std::cout << 'A' << '\n';
    }
    // Animal(const Animal& other) {
    //     std::cout << "Called Copy A" << '\n';
    // }
    void talk() {
        std::cout << "Animal talking..." << '\n';
    }
    void present() {
        std::cout << "I am an animal" << '\n';
    }
    void setWeight(int _weight) {
        weight = _weight;
    }
    int getWeight() {
        return weight;
    }
    ~Animal() {
        std::cout << "Bye Animal..." << '\n';
    }
};

class Cat : public Animal {
    int furThickness = 3;
public:
    Cat() {
        std::cout << 'C' << '\n';
    }
    Cat(const Cat& other):Animal(other) {
        furThickness = other.furThickness;
        std::cout << "CAT, Called Copy CT" << '\n';
    }
    Cat(Cat&& other) { 
        std::cout << "in cat move ctor" << std::endl;
    }
    void talk() {
         std::cout << "Meow..." << '\n';
    }
    void talk(char* saying) {
        Animal::talk(); // Animal talking...
        std::cout << "Meow..." << '\n' << saying << '\n';
    }
    void setFurThickness(int _furThickness) {
        furThickness = _furThickness;
    }
    void present() {
        std::cout << furThickness << ' ';
        talk();
    }
    ~Cat() {
        std::cout << "Bye Cat..." << '\n';
    }
};

Animal f(Animal a1) {
    // a1.talk();
    Cat c1;
    return c1;
}

Cat f1(Animal a1) {
    // a1.talk();
    Cat c1;
    return c1;
}

Animal f2(Cat a1) {
    // a1.talk();
    return a1;
}

Cat* f3(Animal* a1) {
    // a1.talk();
    // Cat c1;
    // return c1;
    return (Cat*)a1;
}

Animal f4(Animal a1) {
    // a1.talk();
    Cat c1;
    return c1;
}

int main() {
    // Cat c;
    // c.talk();
    // c.talk("Hello from Cat...!");
    // c.present();
    // Cat c1(c);
    // c1.setFurThickness(5);
    // c1.present();

    // Cat* cp = &c;
    // cp->present();
    // Cat& rc = c;
    // rc.setFurThickness(5);
    // c.present();

    // Animal a = c;
    // a.talk();
    // a.present();
    // a.setFurThickness(4); class Animal has no member setFurThickness
    // Animal* ap = &c;
    // ap->talk();

    // f(c1).present();
    // f1(c1).present();
    // f2(c1).present();
    // f2(a).present(); // no suitable conversion

    // Cat result = f3(c1);
    // result.setFurThickness(7);
    // result.present();

    // Cat* pt = f3(&a);
    // pt->setFurThickness(6);
    // pt->present();

    // f4(c).present();

    // Animal* a4;
    // Cat* c4 = (Cat*)a4;
    // c4->present();

    Cat c5;
    c5.setWeight(40);
    Cat c6(c5);
    std::cout << c6.getWeight() << '\n';

    return 0;
}
