#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int _data, Node* _next) {
        data = _data;
        next = _next;
    }
};

class LinkedQueue {
    Node* front;
    Node* back;
    void copy(const LinkedQueue& other) {
        if (other.empty()) {
            front = back = nullptr;
            return;
        }
        Node* tmp = other.front;
        while(tmp) {
            enqueue(tmp->data);
            tmp = tmp->next;
        }
    }
    void erase() {
        while(!empty()) {
            dequeue();
        }
    }
public:
    LinkedQueue() {
        front = back = nullptr;
    }
    LinkedQueue(const LinkedQueue& other) {
        copy(other);
    }
    LinkedQueue& operator=(const LinkedQueue& other) {
        if (this != &other) {
            erase();
            copy(other);
        }
        return *this;
    }
    ~LinkedQueue() {
        erase();
    }
    bool empty() const {
        return front == nullptr;
    }
    void enqueue(int x) {
        if (empty()) {
            front = new Node(x, nullptr);
            back = front;
        } else {
            Node* newNode = new Node(x, nullptr);
            back->next = newNode;
            back = newNode;
        }
    }
    int dequeue() {
        if (empty()) {
            return -1;
        }
        Node* toDelete = front;
        int data = toDelete->data;
        if (front == back) {
            front = front->next;
            front = back = nullptr;
        } else {
            front = front->next;
        }
        delete toDelete;
        return data;
    }
    int head() const {
        if (empty()) {
            return -1;
        }
        return front->data;
    }

};

int main() {
    
    return 0;
}