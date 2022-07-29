#include <iostream>

const int INITIAL_CAPACITY = 20;
const int EMPTY_STACK = -1;
const int RESIZE_FACTOR = 2;

class ResizingStack {
    int* a;
    int top;
    int capacity;
    void copy(const ResizingStack& other) {
        top = EMPTY_STACK;
        capacity = other.capacity;
        a = new int[capacity];
        for (int i = 0; i < capacity; i++) {
            a[i] = other.a[i];
        }
    }
public:
    ResizingStack() {
        capacity = INITIAL_CAPACITY;
        a = new int[capacity];
        top = EMPTY_STACK;
    }
    ResizingStack(const ResizingStack& other) {
        copy(other);
    }
    ResizingStack& operator=(const ResizingStack& other) {
        if (this != &other) {
            delete[] a;
            copy(other);
        }
        return *this;
    }
    ~ResizingStack() {
        delete[] a;
    }
    bool empty() const {
        return top == EMPTY_STACK;
    }
    void push(const int x) {
        if (full()) {
            resize();
        }
        a [++top] = x;
    }
    int pop() {
        if (empty()) {
            return -1;
        }
        // std::cout << "called pop..." << '\n';
        int curr = top;
        top--;
        return a[curr];
    }
    int peek() const {
        if (empty()) {
            return -1;
        }
        return a[top];
    }

    bool full() const {
        return top == capacity - 1;
    }
    void resize() {
        int newCapacity = capacity * RESIZE_FACTOR;
        int* newa = new int[newCapacity];
        for (int i = 0; i < capacity; i++) {
            newa[i] = a[i];
        }
        delete[] a;
        a = newa;
        capacity = newCapacity;
    }
    void print() const {
        std::cout << "top: " << top << '\n';
        // for (int i = capacity - 1; i >= 0; i--) {
        //     std::cout << a[i] << ' ';
        // }
        for (int i = 0; i <= capacity - 1; i++) {
            std::cout << a[i] << ' ';
        }
        std::cout << '\n';
    }
};

int main() {
    ResizingStack s;
    s.push(3);
    s.push(1);
    s.push(12);
    s.push(101);
    s.push(75);
    s.push(4);
    s.push(9);
    s.push(19);

    s.print();

    s.pop();
    s.print();

    return 0;
}