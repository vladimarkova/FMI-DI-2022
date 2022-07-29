#include <iostream>

const int MAX_QUEUE = 100;

class Queue {
    int a[MAX_QUEUE];
    int front;
    int back;
public:
    int capacity() const {
        return MAX_QUEUE;
    }
    void setEmpty() {
        front = 0;
        back = -1;
    }
};

int main() {

    return 0;
}