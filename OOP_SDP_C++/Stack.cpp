#include <iostream>

const int EMPTY_STACK = -1;
const int MAX_STACK = 100;

class Stack {
    int a[MAX_STACK];
    int top; // index of top element
    bool full() const {
        return top == MAX_STACK - 1;
    }
public:
    Stack() {
        top = EMPTY_STACK;
    }
    bool empty() const {
        return top == EMPTY_STACK;
    }
    void push(const int x) {
        if (!full()) {
            a[++top] = x;
        }
    }
    int pop() {
        if (empty()) {
            return -1;
        }
        return a[top--];
    }
    int peek() const {
        if (empty()) {
            return -1;
        }
        return a[top];
    }
    void print() const {
        if (empty()) {
            return;
        }
        for (int i = top; i >= 0; i--) {
            std::cout << a[i] << ' ';
        }
        std::cout << '\n';
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(4);
    s.push(5);
    s.push(7);
    s.push(10);
    s.push(6);
    s.push(12);
    s.push(101);
    
    s.print();

    return 0;
}